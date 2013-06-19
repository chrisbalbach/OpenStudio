/**********************************************************************
*  Copyright (c) 2008-2013, Alliance for Sustainable Energy.  
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

#include <utilities/data/Test/DataFixture.hpp>

using openstudio::Logger;
using openstudio::FileLogSink;
using openstudio::toPath;

// initiallize for each test
void DataFixture::SetUp() {
}

// tear down after for each test
void DataFixture::TearDown() {
}

// initiallize static members
void DataFixture::SetUpTestCase() {
  logFile = FileLogSink(toPath("./DataFixture.log"));
  logFile->setLogLevel(Info);
}

// tear down static members
void DataFixture::TearDownTestCase() {
  logFile->disable();
}

boost::optional<openstudio::FileLogSink> DataFixture::logFile;