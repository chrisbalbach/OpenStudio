/**********************************************************************
*  Copyright (c) 2008-2014, Alliance for Sustainable Energy.  
*  All rights reserved.
*  
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*  
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*  
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#include <gtest/gtest.h>
#include "RunManagerTestFixture.hpp"
#include <runmanager/Test/ToolBin.hxx>
#include <runmanager/lib/JobFactory.hpp>
#include <runmanager/lib/RunManager.hpp>
#include <runmanager/lib/LocalProcessCreator.hpp>

#include <model/Model.hpp>
#include <model/WeatherFile.hpp>

#include <utilities/filetypes/EpwFile.hpp>
#include <utilities/idf/IdfFile.hpp>
#include <utilities/idf/Workspace.hpp>
#include <utilities/idf/WorkspaceObject.hpp>

#include <utilities/idd/OS_TimeDependentValuation_FieldEnums.hxx>
#include <utilities/idd/OS_WeatherFile_FieldEnums.hxx>

#include <boost/filesystem/path.hpp>

#include <resources.hxx>

using namespace openstudio;

TEST_F(RunManagerTestFixture, URLTestRelative)
{
  openstudio::path osm = resourcesPath() / openstudio::toPath("runmanager") / openstudio::toPath("UrlTestRelative.osm");
  openstudio::path weatherdir = resourcesPath() / openstudio::toPath("runmanager"); 
  openstudio::model::Model m = openstudio::model::exampleModel();

  openstudio::IdfObject schedule(openstudio::IddObjectType::OS_TimeDependentValuation);
  schedule.setString(OS_TimeDependentValuationFields::Url, "./ScheduleFile.csv");
  m.addObject(schedule);

  m.save(osm, true);

  openstudio::runmanager::FileInfo fi(osm, "osm");

  ASSERT_TRUE(fi.exists);
  openstudio::runmanager::Files f;
  f.append(fi);

  // Create a search path for searching relative to the input file
  std::vector<openstudio::URLSearchPath> searchpaths;
  searchpaths.push_back(openstudio::URLSearchPath(openstudio::toPath("."), openstudio::URLSearchPath::ToInputFile));

  // Create a job that uses an osm file that contains a url
  openstudio::runmanager::Job j = openstudio::runmanager::JobFactory::createJob(
      openstudio::runmanager::JobType::Null,
      openstudio::runmanager::Tools(),
      openstudio::runmanager::JobParams(),
      f,
      searchpaths
      );

  ASSERT_GE(j.inputFiles().size(), 2u);

  // Grab the original file added by the user
  openstudio::runmanager::FileInfo origfile = j.inputFiles().at(0);

  // Grab the FileInfo that was actually added to the job (it should have been updated by the factory)
  openstudio::runmanager::FileInfo updatedfile = j.inputFiles().at(1);

  EXPECT_TRUE(origfile != updatedfile);

  // Verify that the new file was created, that it exists and that it resides at a different location
  // than the original file.
  EXPECT_TRUE(updatedfile.exists);
  EXPECT_NE(openstudio::toString(updatedfile.fullPath), openstudio::toString(fi.fullPath));
  EXPECT_EQ(updatedfile.filename, fi.filename);
  
  // Verify that the new FileInfo object now has a required file attached to it
  std::vector<std::pair<QUrl, openstudio::path> > requiredfiles = updatedfile.requiredFiles;

  ASSERT_EQ(1u, requiredfiles.size());
  EXPECT_EQ(f.files().at(0).requiredFiles.size(), static_cast<size_t>(0));

  // Verify that said required file is what we expect. The "from" location is the path of the file, the "to" location is a shortened
  // relative path. The relative path is expected because the file will be copied/linked/transfered into place when it is required
  // during job execution.
  EXPECT_TRUE(requiredfiles[0].first == QUrl::fromLocalFile(openstudio::toQString(resourcesPath()/openstudio::toPath("runmanager")/openstudio::toPath("ScheduleFile.csv"))));

  // Using this version for now
  EXPECT_TRUE(requiredfiles[0].second == openstudio::toPath(requiredfiles[0].first.toLocalFile()));
  //  This version is more accurate for when we go back to relative urls in the osm file
  //  EXPECT_TRUE(requiredfiles[0].second == openstudio::toPath("ScheduleFile.csv"));


  // Now, load the idf which was created in the previous step
  openstudio::OptionalIdfFile idf = openstudio::IdfFile::load(updatedfile.fullPath);

  ASSERT_TRUE(idf);
  openstudio::Workspace ws(*idf);
  std::vector<openstudio::WorkspaceObject> urlobjects = ws.objectsWithURLFields();

  ASSERT_EQ(1u, urlobjects.size());
  openstudio::WorkspaceObject wso = urlobjects.at(0);
  const unsigned int numfields = wso.numFields();

  bool urlfound = false;
  for (unsigned int i = 0; i < numfields; ++i)
  {
    boost::optional<QUrl> url = wso.getURL(i);

    if (url)
    {
      // Verify that the idf contains the one URL we expect it to, and that it's been updated to match the required file spec
      urlfound = true;
      //Using this version while we are configured to fixup the URLs to be absolute
      EXPECT_TRUE(url == QUrl::fromLocalFile(openstudio::toQString(resourcesPath()/openstudio::toPath("runmanager")/openstudio::toPath("ScheduleFile.csv"))));
      //  EXPECT_EQ(openstudio::toString(url->toString()), "file:ScheduleFile.csv");
      break;
    }
  }

  EXPECT_TRUE(urlfound);

}


TEST_F(RunManagerTestFixture, URLTestAbsolute)
{
  openstudio::path osm = resourcesPath() / openstudio::toPath("runmanager") / openstudio::toPath("UrlTestAbsolute.osm");
  openstudio::path weatherdir = resourcesPath() / openstudio::toPath("runmanager"); 
  openstudio::model::Model m = openstudio::model::exampleModel();

  openstudio::IdfObject schedule(openstudio::IddObjectType::OS_TimeDependentValuation);
  schedule.setString(OS_TimeDependentValuationFields::Url,
                     openstudio::toString(resourcesPath() / openstudio::toPath("runmanager") / openstudio::toPath("ScheduleFile.csv")) );
  m.addObject(schedule);

  m.save(osm, true);

  openstudio::runmanager::FileInfo fi(osm, "osm");

  ASSERT_TRUE(fi.exists);
  openstudio::runmanager::Files f;
  f.append(fi);


  // Create a job that uses an osm file that contains a url
  openstudio::runmanager::Job j = openstudio::runmanager::JobFactory::createJob(
      openstudio::runmanager::JobType::Null,
      openstudio::runmanager::Tools(),
      openstudio::runmanager::JobParams(),
      f);

  ASSERT_GE(j.inputFiles().size(), 1u);

  // Grab the original file added by the user
  openstudio::runmanager::FileInfo origfile = j.inputFiles().at(0);

  // Grab the FileInfo that was actually added to the job (it should have been updated by the factory)
  openstudio::runmanager::FileInfo updatedfile = j.inputFiles().at(1);

  EXPECT_TRUE(origfile != updatedfile);

  // Verify that the new file was created, that it exists and that it resides at a different location
  // than the original file.
  EXPECT_TRUE(updatedfile.exists);
  EXPECT_NE(openstudio::toString(updatedfile.fullPath), openstudio::toString(fi.fullPath));
  EXPECT_EQ(updatedfile.filename, fi.filename);
  
  // Verify that the new FileInfo object now has a required file attached to it
  std::vector<std::pair<QUrl, openstudio::path> > requiredfiles = updatedfile.requiredFiles;

  ASSERT_EQ(requiredfiles.size(), static_cast<size_t>(1));
  EXPECT_EQ(f.files().at(0).requiredFiles.size(), static_cast<size_t>(0));

  // Verify that said required file is what we expect. The "from" location is the path of the file, the "to" location is a shortened
  // relative path. The relative path is expected because the file will be copied/linked/transfered into place when it is required
  // during job execution.
  QUrl rhs = QUrl::fromLocalFile(openstudio::toQString(resourcesPath()/openstudio::toPath("runmanager")/openstudio::toPath("ScheduleFile.csv")));
  //std::string first = openstudio::toString(requiredfiles[0].first.toString());
  //std::string second = openstudio::toString(rhs.toString());
  EXPECT_TRUE(requiredfiles[0].first == rhs);
  // Using this version for now
  EXPECT_TRUE(requiredfiles[0].second == openstudio::toPath(requiredfiles[0].first.toLocalFile()));
//  This version is more accurate for when we go back to relative urls in the osm file
//  EXPECT_TRUE(requiredfiles[0].second == openstudio::toPath("ScheduleFile.csv"));

  // Now, load the idf which was created in the previous step
  openstudio::OptionalIdfFile idf = openstudio::IdfFile::load(updatedfile.fullPath);

  ASSERT_TRUE(idf);
  openstudio::Workspace ws(*idf);
  std::vector<openstudio::WorkspaceObject> urlobjects = ws.objectsWithURLFields();

  ASSERT_EQ(1u, urlobjects.size());
  openstudio::WorkspaceObject wso = urlobjects.at(0);
  const unsigned int numfields = wso.numFields();

  bool urlfound = false;
  for (unsigned int i = 0; i < numfields; ++i)
  {
    boost::optional<QUrl> url = wso.getURL(i);

    if (url)
    {
      // Verify that the idf contains the one URL we expect it to, and that it's been updated to match the required file spec
      urlfound = true;
      //Using this version while we are configured to fixup the URLs to be absolute
      EXPECT_TRUE(url == QUrl::fromLocalFile(openstudio::toQString(resourcesPath()/openstudio::toPath("runmanager")/openstudio::toPath("ScheduleFile.csv"))));
      //  EXPECT_EQ(openstudio::toString(url->toString()), "file:ScheduleFile.csv");
      break;
    }
  }

  EXPECT_TRUE(urlfound);

}

TEST_F(RunManagerTestFixture, JobCreateTest)
{
  openstudio::path outdir = openstudio::tempDir() / openstudio::toPath("JobCreateTest");

  openstudio::path idf = (resourcesPath() / openstudio::toPath("runmanager") / openstudio::toPath("5ZoneWarmest.idf"));
  openstudio::path epw = (resourcesPath() / openstudio::toPath("runmanager") / openstudio::toPath("USA_CO_Golden-NREL.724666_TMY3.epw"));

  openstudio::runmanager::Job j = openstudio::runmanager::JobFactory::createEnergyPlusJob(
    openstudio::runmanager::ToolInfo(energyPlusExePath()),
    energyPlusIDDPath(),
    idf,
    epw,
    outdir);

  boost::shared_ptr<openstudio::runmanager::ProcessCreator> lpc(new openstudio::runmanager::LocalProcessCreator());
  
  j.start(lpc);
  j.waitForFinished();

  EXPECT_FALSE(j.running());
  EXPECT_FALSE(j.treeRunning());
  EXPECT_FALSE(j.runningRemotely());

  EXPECT_TRUE(j.errors().succeeded());

}

TEST_F(RunManagerTestFixture, GenericJobCreateTest)
{
  openstudio::path outdir = openstudio::tempDir() / openstudio::toPath("GenericJobCreateTest");

  openstudio::path idf = (resourcesPath() / openstudio::toPath("runmanager") / openstudio::toPath("5ZoneWarmest.idf"));
  openstudio::path epw = (resourcesPath() / openstudio::toPath("runmanager") / openstudio::toPath("USA_CO_Golden-NREL.724666_TMY3.epw"));

  openstudio::runmanager::Files files;
  openstudio::runmanager::FileInfo idffileinfo(idf, "idf");
  idffileinfo.addRequiredFile(epw, openstudio::toPath("in.epw"));
  files.append(idffileinfo);
  
  openstudio::runmanager::ToolInfo eplus("energyplus", energyPlusExePath());
  openstudio::runmanager::Tools tools;
  tools.append(eplus);

  files.append(openstudio::runmanager::FileInfo(energyPlusIDDPath(), "idd"));

  openstudio::runmanager::JobParams params;
  params.append("outdir", openstudio::toString(outdir));

  openstudio::runmanager::Job j = openstudio::runmanager::JobFactory::createJob(openstudio::runmanager::JobType::EnergyPlus,
      tools,
      params,
      files);

  boost::shared_ptr<openstudio::runmanager::ProcessCreator> lpc(new openstudio::runmanager::LocalProcessCreator());

  j.start(lpc);
  j.waitForFinished();

  EXPECT_FALSE(j.running());
  EXPECT_FALSE(j.treeRunning());
  EXPECT_FALSE(j.runningRemotely());

  EXPECT_TRUE(j.errors().succeeded());

}
