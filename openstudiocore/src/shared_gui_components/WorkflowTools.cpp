#include "WorkflowTools.hpp"

#include <QSysInfo>

#include "../runmanager/lib/RunManager.hpp"
#include "../runmanager/lib/WorkItem.hpp"
#include "../runmanager/lib/Workflow.hpp"

#include "../model/ThermalZone.hpp"
#include "../model/DaylightingControl.hpp"
#include "../model/Space.hpp"
#include "../model/Model.hpp"
#include "../model/IlluminanceMap.hpp"
#include "../model/GlareSensor.hpp"

#include "../model/ThermalZone_Impl.hpp"
#include "../model/DaylightingControl_Impl.hpp"
#include "../model/Space_Impl.hpp"
#include "../model/Model_Impl.hpp"
#include "../model/IlluminanceMap_Impl.hpp"
#include "../model/GlareSensor_Impl.hpp"

#include "../analysis/Problem.hpp"
#include "../analysis/Analysis.hpp"
#include "../analysisdriver/SimpleProject.hpp"

#include "../utilities/core/ApplicationPathHelpers.hpp"

namespace openstudio {

void getRadiancePreRunWarningsAndErrors(std::vector<std::string> &t_warnings, 
    std::vector<std::string> &t_errors,
    openstudio::runmanager::RunManager &t_runManager,
    boost::optional<openstudio::model::Model> &t_model)
{

  t_warnings.clear();
  t_errors.clear();

  openstudio::runmanager::ConfigOptions co(true);
  t_runManager.setConfigOptions(co);
  bool ruby_not_installed = co.getTools().getAllByName("ruby").tools().size() == 0;
  bool radiance_not_installed = co.getTools().getAllByName("rtrace").tools().size() == 0;
  
  if(radiance_not_installed){
    t_errors.push_back("Radiance is required, but not installed.");
  }

  if(ruby_not_installed){
    t_errors.push_back("Ruby is required, but not installed.");
  }
  
  // TODO remove when fixed
  #if defined(Q_OS_WIN)
  if(QSysInfo::windowsVersion() == QSysInfo::WV_XP){
    t_errors.push_back("OpenStudio is currently unable to run Radiance on XP operating systems.");
  }
  #endif

  if (t_model)
  {
    // ThermalZone
    std::vector<model::ThermalZone> thermalZones = t_model->getModelObjects<model::ThermalZone>();
    if(thermalZones.size() > 0){
      //BOOST_FOREACH(model::ThermalZone thermalZone, thermalZones){
      //  std::vector<model::Space> spaces = thermalZone.spaces();
      //  if(spaces.size() > 0){
      //  }
      //  boost::optional<model::IlluminanceMap> illuminanceMap = thermalZone.illuminanceMap();
      //  if(illuminanceMap){
      //  }
      //  boost::optional<model::DaylightingControl> primaryDaylightingControl = thermalZone.primaryDaylightingControl();
      //  if(primaryDaylightingControl){
      //  }
      //}
    }
    else{
      t_errors.push_back("The OpenStudio model has no ThermalZone objects.");
    }

    // Space
    std::vector<model::Space> spaces = t_model->getModelObjects<model::Space>();
    if(spaces.size() == 0){
      t_errors.push_back("The OpenStudio model has no Space objects.");
    }

    // IlluminanceMap
    std::vector<model::IlluminanceMap> illuminanceMaps = t_model->getModelObjects<model::IlluminanceMap>();
    if(illuminanceMaps.size() > 0){
      BOOST_FOREACH(model::IlluminanceMap illuminanceMap, illuminanceMaps){
        boost::optional<model::Space> space = illuminanceMap.space();
        if(!space){
          t_errors.push_back("An OpenStudio model IlluminanceMap object is not assigned to a Space object.");
          break;
        }
        else{
          //boost::optional<model::ThermalZone> thermalZone = space->thermalZone();
          //std::vector<model::DaylightingControl> daylightingControls = space->daylightingControls();
          //std::vector<model::IlluminanceMap> illuminanceMaps = space->illuminanceMaps();
          //std::vector<model::GlareSensor> glareSensors = space->glareSensors();
        }
      }
    }
    else{
      t_errors.push_back("The OpenStudio model has no IlluminanceMap objects.");
    }

    // DaylightingControl
    std::vector<model::DaylightingControl> daylightingControls = t_model->getModelObjects<model::DaylightingControl>();
    if(daylightingControls.size() > 0){
      BOOST_FOREACH(model::DaylightingControl daylightingControl, daylightingControls){
        boost::optional<model::Space> space = daylightingControl.space();
        if(!space){
          t_errors.push_back("An OpenStudio model DaylightingControl object is not assigned to a Space object.");
          break;
        }
      }
    }
    else{
      t_errors.push_back("The OpenStudio model has no DaylightingControl objects.");
    }

    // GlareSensor
    std::vector<model::GlareSensor> glareSensors = t_model->getModelObjects<model::GlareSensor>();
    if(glareSensors.size() == 0){
      t_warnings.push_back("The OpenStudio model has no GlareSensor objects.");
    }
  }
}

OptionalInt getProjectRadianceJobIndex(const openstudio::analysisdriver::SimpleProject &t_project)
{
  openstudio::analysis::Problem problem = t_project.analysis().problem();
  OptionalInt index = problem.getWorkflowStepIndexByJobType(runmanager::JobType::ModelToIdf);
  if (index && *index > 0 && problem.workflow()[*index - 1].isWorkItem()) {
    openstudio::runmanager::WorkItem wi = problem.workflow()[*index - 1].workItem();
    if (wi.jobkeyname == "pat-radiance-job")
    {
      return *index - 1;
    }
  }

  return OptionalInt();
}

bool projectHasRadiance(const openstudio::analysisdriver::SimpleProject &t_project)
{
  return getProjectRadianceJobIndex(t_project);
}

void removeRadianceFromProject(openstudio::analysisdriver::SimpleProject &t_project)
{
  openstudio::analysis::Problem problem = t_project.analysis().problem();
  OptionalInt index = getProjectRadianceJobIndex(t_project);
  if (index)
  {
    problem.erase(problem.workflow()[*index]);
  }
}

void addRadianceToProject(openstudio::analysisdriver::SimpleProject &t_project)
{
  openstudio::analysis::Problem problem = t_project.analysis().problem();
  OptionalInt index = getProjectRadianceJobIndex(t_project);
  if (index)
  {
    return; // nothing to do
  }

  openstudio::runmanager::ConfigOptions co(true);
  std::vector<openstudio::runmanager::ToolInfo> rad = co.getTools().getAllByName("rad").tools();

  if (!rad.empty())
  {
    openstudio::path radiancePath = rad.back().localBinPath.parent_path();
    OptionalInt index = problem.getWorkflowStepIndexByJobType(runmanager::JobType::ModelToIdf);

    if (index)
    {
      LOG_FREE(Debug, "WorkflowTools", "Adding radiance job at location " << *index);
      openstudio::runmanager::WorkItem wi = runmanager::Workflow::radianceDaylightCalculations(getOpenStudioRubyIncludePath(), radiancePath);
      wi.jobkeyname = "pat-radiance-job";
      problem.insert(*index, wi);
    }
  }
}

}