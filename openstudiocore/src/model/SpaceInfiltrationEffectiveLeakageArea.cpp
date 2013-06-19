/**********************************************************************
 *  Copyright (c) 2008-2011, Alliance for Sustainable Energy.
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

#include <model/SpaceInfiltrationEffectiveLeakageArea.hpp>
#include <model/SpaceInfiltrationEffectiveLeakageArea_Impl.hpp>

#include <model/Schedule.hpp>
#include <model/Schedule_Impl.hpp>
#include <model/Space.hpp>
#include <model/Space_Impl.hpp>
#include <model/SpaceType.hpp>
#include <model/SpaceType_Impl.hpp>
#include <model/DefaultScheduleSet.hpp>
#include <model/DefaultScheduleSet_Impl.hpp>
#include <model/LifeCycleCost.hpp>

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_SpaceInfiltration_EffectiveLeakageArea_FieldEnums.hxx>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

  SpaceInfiltrationEffectiveLeakageArea_Impl::SpaceInfiltrationEffectiveLeakageArea_Impl(
      const IdfObject& idfObject,                                                                                  
      Model_Impl* model,
      bool keepHandle)
    : SpaceLoad_Impl(idfObject,model,keepHandle)
  {
    BOOST_ASSERT(idfObject.iddObject().type() == SpaceInfiltrationEffectiveLeakageArea::iddObjectType());
  }

  SpaceInfiltrationEffectiveLeakageArea_Impl::SpaceInfiltrationEffectiveLeakageArea_Impl(
      const openstudio::detail::WorkspaceObject_Impl& other,
      Model_Impl* model,
      bool keepHandle)
    : SpaceLoad_Impl(other,model,keepHandle)
  {
    BOOST_ASSERT(other.iddObject().type() == SpaceInfiltrationEffectiveLeakageArea::iddObjectType());
  }

  SpaceInfiltrationEffectiveLeakageArea_Impl::SpaceInfiltrationEffectiveLeakageArea_Impl(
      const SpaceInfiltrationEffectiveLeakageArea_Impl& other,
      Model_Impl* model,
      bool keepHandle)
    : SpaceLoad_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& SpaceInfiltrationEffectiveLeakageArea_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SpaceInfiltrationEffectiveLeakageArea_Impl::iddObjectType() const {
    return SpaceInfiltrationEffectiveLeakageArea::iddObjectType();
  }

  std::vector<ScheduleTypeKey> SpaceInfiltrationEffectiveLeakageArea_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_SpaceInfiltration_EffectiveLeakageAreaFields::ScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("SpaceInfiltrationEffectiveLeakageArea","Infiltration"));
    }
    return result;
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::hardSize()
  {
    boost::optional<Space> space = this->space();
    if (!space){
      return false;
    }
    return false;
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::hardApplySchedules()
  {
    bool result = false;
    boost::optional<Schedule> schedule = this->schedule();
    if (schedule){
      result = this->setSchedule(*schedule);
    }
    return result;
  }

  double SpaceInfiltrationEffectiveLeakageArea_Impl::effectiveAirLeakageArea() const {
    boost::optional<double> value = getDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::EffectiveAirLeakageArea,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::getEffectiveAirLeakageArea(bool returnIP) const {
    OptionalDouble value = effectiveAirLeakageArea();
    OSOptionalQuantity result = getQuantityFromDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::EffectiveAirLeakageArea, value, returnIP);
    BOOST_ASSERT(result.isSet());
    return result.get();
  }

  double SpaceInfiltrationEffectiveLeakageArea_Impl::stackCoefficient() const {
    boost::optional<double> value = getDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::StackCoefficient,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::getStackCoefficient(bool returnIP) const {
    OptionalDouble value = stackCoefficient();
    OSOptionalQuantity result = getQuantityFromDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::StackCoefficient, value, returnIP);
    BOOST_ASSERT(result.isSet());
    return result.get();
  }

  double SpaceInfiltrationEffectiveLeakageArea_Impl::windCoefficient() const {
    boost::optional<double> value = getDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::WindCoefficient,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::getWindCoefficient(bool returnIP) const {
    OptionalDouble value = windCoefficient();
    OSOptionalQuantity result = getQuantityFromDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::WindCoefficient, value, returnIP);
    BOOST_ASSERT(result.isSet());
    return result.get();
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setEffectiveAirLeakageArea(double effectiveAirLeakageArea) {
    bool result = setDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::EffectiveAirLeakageArea, effectiveAirLeakageArea);
    return result;
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setEffectiveAirLeakageArea(const Quantity& effectiveAirLeakageArea) {
    OptionalDouble value = getDoubleFromQuantity(OS_SpaceInfiltration_EffectiveLeakageAreaFields::EffectiveAirLeakageArea,effectiveAirLeakageArea);
    if (!value) {
      return false;
    }
    return setEffectiveAirLeakageArea(value.get());
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setStackCoefficient(double stackCoefficient) {
    bool result = setDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::StackCoefficient, stackCoefficient);
    return result;
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setStackCoefficient(const Quantity& stackCoefficient) {
    OptionalDouble value = getDoubleFromQuantity(OS_SpaceInfiltration_EffectiveLeakageAreaFields::StackCoefficient,stackCoefficient);
    if (!value) {
      return false;
    }
    return setStackCoefficient(value.get());
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setWindCoefficient(double windCoefficient) {
    bool result = setDouble(OS_SpaceInfiltration_EffectiveLeakageAreaFields::WindCoefficient, windCoefficient);
    return result;
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setWindCoefficient(const Quantity& windCoefficient) {
    OptionalDouble value = getDoubleFromQuantity(OS_SpaceInfiltration_EffectiveLeakageAreaFields::WindCoefficient,windCoefficient);
    if (!value) {
      return false;
    }
    return setWindCoefficient(value.get());
  }

  int SpaceInfiltrationEffectiveLeakageArea_Impl::spaceIndex() const {
    return OS_SpaceInfiltration_EffectiveLeakageAreaFields::SpaceorSpaceTypeName;
  }

  boost::optional<Schedule> SpaceInfiltrationEffectiveLeakageArea_Impl::schedule() const
  {
    boost::optional<Schedule> result = getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_SpaceInfiltration_EffectiveLeakageAreaFields::ScheduleName);
    if (!result){
      // search upwards
      OptionalSpace space = this->space();
      OptionalSpaceType spaceType = this->spaceType();
      if (space){
        result = space->getDefaultSchedule(DefaultScheduleType::InfiltrationSchedule);
      }else if (spaceType){
        result = spaceType->getDefaultSchedule(DefaultScheduleType::InfiltrationSchedule);
      }
    }
    return result;
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::isScheduleDefaulted() const
  {
    return isEmpty(OS_SpaceInfiltration_EffectiveLeakageAreaFields::ScheduleName);
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setSchedule(Schedule& schedule)
  {
    bool result = ModelObject_Impl::setSchedule(OS_SpaceInfiltration_EffectiveLeakageAreaFields::ScheduleName,
                                                "SpaceInfiltrationEffectiveLeakageArea",
                                                "Infiltration",
                                                schedule);
    return result;
  }

  void SpaceInfiltrationEffectiveLeakageArea_Impl::resetSchedule()
  {
    bool result = setString(OS_SpaceInfiltration_EffectiveLeakageAreaFields::ScheduleName, "");
    BOOST_ASSERT(result);
  }

  openstudio::Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::effectiveAirLeakageArea_SI() const {
    return getEffectiveAirLeakageArea(false);
  }

  openstudio::Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::effectiveAirLeakageArea_IP() const {
    return getEffectiveAirLeakageArea(true);
  }

  openstudio::Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::stackCoefficient_SI() const {
    return getStackCoefficient(false);
  }

  openstudio::Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::stackCoefficient_IP() const {
    return getStackCoefficient(true);
  }

  openstudio::Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::windCoefficient_SI() const {
    return getWindCoefficient(false);
  }

  openstudio::Quantity SpaceInfiltrationEffectiveLeakageArea_Impl::windCoefficient_IP() const {
    return getWindCoefficient(true);
  }

  boost::optional<ModelObject> SpaceInfiltrationEffectiveLeakageArea_Impl::scheduleAsModelObject() const {
    OptionalModelObject result;
    OptionalSchedule intermediate = schedule();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  bool SpaceInfiltrationEffectiveLeakageArea_Impl::setScheduleAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalSchedule intermediate = modelObject->optionalCast<Schedule>();
      if (intermediate) {
        Schedule schedule(*intermediate);
        return setSchedule(schedule);
      }
      else {
        return false;
      }
    }
    else {
      resetSchedule();
    }
    return true;
  }

} // detail

SpaceInfiltrationEffectiveLeakageArea::SpaceInfiltrationEffectiveLeakageArea(const Model& model)
  : SpaceLoad(SpaceInfiltrationEffectiveLeakageArea::iddObjectType(),model)
{
  BOOST_ASSERT(getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>());
  bool test = setEffectiveAirLeakageArea(0.1);
  BOOST_ASSERT(test);
  test = setStackCoefficient(0.1);
  BOOST_ASSERT(test);
  test = setWindCoefficient(0.1);
  BOOST_ASSERT(test);
}

IddObjectType SpaceInfiltrationEffectiveLeakageArea::iddObjectType() {
  IddObjectType result(IddObjectType::OS_SpaceInfiltration_EffectiveLeakageArea);
  return result;
}

boost::optional<Schedule> SpaceInfiltrationEffectiveLeakageArea::schedule() const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->schedule();
}

bool SpaceInfiltrationEffectiveLeakageArea::isScheduleDefaulted() const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->isScheduleDefaulted();
}

double SpaceInfiltrationEffectiveLeakageArea::effectiveAirLeakageArea() const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->effectiveAirLeakageArea();
}

Quantity SpaceInfiltrationEffectiveLeakageArea::getEffectiveAirLeakageArea(bool returnIP) const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->getEffectiveAirLeakageArea(returnIP);
}

double SpaceInfiltrationEffectiveLeakageArea::stackCoefficient() const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->stackCoefficient();
}

Quantity SpaceInfiltrationEffectiveLeakageArea::getStackCoefficient(bool returnIP) const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->getStackCoefficient(returnIP);
}

double SpaceInfiltrationEffectiveLeakageArea::windCoefficient() const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->windCoefficient();
}

Quantity SpaceInfiltrationEffectiveLeakageArea::getWindCoefficient(bool returnIP) const {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->getWindCoefficient(returnIP);
}

bool SpaceInfiltrationEffectiveLeakageArea::setSchedule(Schedule& schedule) {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->setSchedule(schedule);
}

void SpaceInfiltrationEffectiveLeakageArea::resetSchedule() {
  getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->resetSchedule();
}

bool SpaceInfiltrationEffectiveLeakageArea::setEffectiveAirLeakageArea(double effectiveAirLeakageArea) {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->setEffectiveAirLeakageArea(effectiveAirLeakageArea);
}

bool SpaceInfiltrationEffectiveLeakageArea::setEffectiveAirLeakageArea(const Quantity& effectiveAirLeakageArea) {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->setEffectiveAirLeakageArea(effectiveAirLeakageArea);
}

bool SpaceInfiltrationEffectiveLeakageArea::setStackCoefficient(double stackCoefficient) {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->setStackCoefficient(stackCoefficient);
}

bool SpaceInfiltrationEffectiveLeakageArea::setStackCoefficient(const Quantity& stackCoefficient) {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->setStackCoefficient(stackCoefficient);
}

bool SpaceInfiltrationEffectiveLeakageArea::setWindCoefficient(double windCoefficient) {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->setWindCoefficient(windCoefficient);
}

bool SpaceInfiltrationEffectiveLeakageArea::setWindCoefficient(const Quantity& windCoefficient) {
  return getImpl<detail::SpaceInfiltrationEffectiveLeakageArea_Impl>()->setWindCoefficient(windCoefficient);
}

/// @cond
SpaceInfiltrationEffectiveLeakageArea::SpaceInfiltrationEffectiveLeakageArea(
    boost::shared_ptr<detail::SpaceInfiltrationEffectiveLeakageArea_Impl> impl)
  : SpaceLoad(impl)
{}
/// @endcond

} // model
} // openstudio

