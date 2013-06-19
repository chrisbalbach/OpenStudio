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

#include <model/SiteGroundReflectance.hpp>
#include <model/SiteGroundReflectance_Impl.hpp>

#include <model/Model.hpp>
#include <model/Model_Impl.hpp>
#include <model/Site.hpp>
#include <model/Site_Impl.hpp>

#include <utilities/idd/OS_Site_GroundReflectance_FieldEnums.hxx>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

  SiteGroundReflectance_Impl::SiteGroundReflectance_Impl(const IdfObject& idfObject,
                                                         Model_Impl* model,
                                                         bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    BOOST_ASSERT(idfObject.iddObject().type() == SiteGroundReflectance::iddObjectType());
  }

  SiteGroundReflectance_Impl::SiteGroundReflectance_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                         Model_Impl* model,
                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    BOOST_ASSERT(other.iddObject().type() == SiteGroundReflectance::iddObjectType());
  }

  SiteGroundReflectance_Impl::SiteGroundReflectance_Impl(const SiteGroundReflectance_Impl& other,
                                                         Model_Impl* model,
                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  boost::optional<ParentObject> SiteGroundReflectance_Impl::parent() const
  {
    boost::optional<Site> result = this->model().getOptionalUniqueModelObject<Site>();
    return boost::optional<ParentObject>(result);
  }

  const std::vector<std::string>& SiteGroundReflectance_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SiteGroundReflectance_Impl::iddObjectType() const {
    return SiteGroundReflectance::iddObjectType();
  }

  double SiteGroundReflectance_Impl::januaryGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::JanuaryGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isJanuaryGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::JanuaryGroundReflectance);
  }

  double SiteGroundReflectance_Impl::februaryGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::FebruaryGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isFebruaryGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::FebruaryGroundReflectance);
  }

  double SiteGroundReflectance_Impl::marchGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::MarchGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isMarchGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::MarchGroundReflectance);
  }

  double SiteGroundReflectance_Impl::aprilGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::AprilGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isAprilGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::AprilGroundReflectance);
  }

  double SiteGroundReflectance_Impl::mayGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::MayGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isMayGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::MayGroundReflectance);
  }

  double SiteGroundReflectance_Impl::juneGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::JuneGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isJuneGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::JuneGroundReflectance);
  }

  double SiteGroundReflectance_Impl::julyGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::JulyGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isJulyGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::JulyGroundReflectance);
  }

  double SiteGroundReflectance_Impl::augustGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::AugustGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isAugustGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::AugustGroundReflectance);
  }

  double SiteGroundReflectance_Impl::septemberGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::SeptemberGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isSeptemberGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::SeptemberGroundReflectance);
  }

  double SiteGroundReflectance_Impl::octoberGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::OctoberGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isOctoberGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::OctoberGroundReflectance);
  }

  double SiteGroundReflectance_Impl::novemberGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::NovemberGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isNovemberGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::NovemberGroundReflectance);
  }

  double SiteGroundReflectance_Impl::decemberGroundReflectance() const {
    boost::optional<double> value = getDouble(OS_Site_GroundReflectanceFields::DecemberGroundReflectance,true);
    BOOST_ASSERT(value);
    return value.get();
  }

  bool SiteGroundReflectance_Impl::isDecemberGroundReflectanceDefaulted() const {
    return isEmpty(OS_Site_GroundReflectanceFields::DecemberGroundReflectance);
  }

  bool SiteGroundReflectance_Impl::setJanuaryGroundReflectance(double januaryGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::JanuaryGroundReflectance, januaryGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetJanuaryGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::JanuaryGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setFebruaryGroundReflectance(double februaryGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::FebruaryGroundReflectance, februaryGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetFebruaryGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::FebruaryGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setMarchGroundReflectance(double marchGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::MarchGroundReflectance, marchGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetMarchGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::MarchGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setAprilGroundReflectance(double aprilGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::AprilGroundReflectance, aprilGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetAprilGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::AprilGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setMayGroundReflectance(double mayGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::MayGroundReflectance, mayGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetMayGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::MayGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setJuneGroundReflectance(double juneGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::JuneGroundReflectance, juneGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetJuneGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::JuneGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setJulyGroundReflectance(double julyGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::JulyGroundReflectance, julyGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetJulyGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::JulyGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setAugustGroundReflectance(double augustGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::AugustGroundReflectance, augustGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetAugustGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::AugustGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setSeptemberGroundReflectance(double septemberGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::SeptemberGroundReflectance, septemberGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetSeptemberGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::SeptemberGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setOctoberGroundReflectance(double octoberGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::OctoberGroundReflectance, octoberGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetOctoberGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::OctoberGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setNovemberGroundReflectance(double novemberGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::NovemberGroundReflectance, novemberGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetNovemberGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::NovemberGroundReflectance, "");
    BOOST_ASSERT(result);
  }

  bool SiteGroundReflectance_Impl::setDecemberGroundReflectance(double decemberGroundReflectance) {
    bool result = false;
    result = setDouble(OS_Site_GroundReflectanceFields::DecemberGroundReflectance, decemberGroundReflectance);
    return result;
  }

  void SiteGroundReflectance_Impl::resetDecemberGroundReflectance() {
    bool result = setString(OS_Site_GroundReflectanceFields::DecemberGroundReflectance, "");
    BOOST_ASSERT(result);
  }

} // detail

IddObjectType SiteGroundReflectance::iddObjectType() {
  IddObjectType result(IddObjectType::OS_Site_GroundReflectance);
  return result;
}

double SiteGroundReflectance::januaryGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->januaryGroundReflectance();
}

bool SiteGroundReflectance::isJanuaryGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isJanuaryGroundReflectanceDefaulted();
}

double SiteGroundReflectance::februaryGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->februaryGroundReflectance();
}

bool SiteGroundReflectance::isFebruaryGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isFebruaryGroundReflectanceDefaulted();
}

double SiteGroundReflectance::marchGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->marchGroundReflectance();
}

bool SiteGroundReflectance::isMarchGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isMarchGroundReflectanceDefaulted();
}

double SiteGroundReflectance::aprilGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->aprilGroundReflectance();
}

bool SiteGroundReflectance::isAprilGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isAprilGroundReflectanceDefaulted();
}

double SiteGroundReflectance::mayGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->mayGroundReflectance();
}

bool SiteGroundReflectance::isMayGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isMayGroundReflectanceDefaulted();
}

double SiteGroundReflectance::juneGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->juneGroundReflectance();
}

bool SiteGroundReflectance::isJuneGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isJuneGroundReflectanceDefaulted();
}

double SiteGroundReflectance::julyGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->julyGroundReflectance();
}

bool SiteGroundReflectance::isJulyGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isJulyGroundReflectanceDefaulted();
}

double SiteGroundReflectance::augustGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->augustGroundReflectance();
}

bool SiteGroundReflectance::isAugustGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isAugustGroundReflectanceDefaulted();
}

double SiteGroundReflectance::septemberGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->septemberGroundReflectance();
}

bool SiteGroundReflectance::isSeptemberGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isSeptemberGroundReflectanceDefaulted();
}

double SiteGroundReflectance::octoberGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->octoberGroundReflectance();
}

bool SiteGroundReflectance::isOctoberGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isOctoberGroundReflectanceDefaulted();
}

double SiteGroundReflectance::novemberGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->novemberGroundReflectance();
}

bool SiteGroundReflectance::isNovemberGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isNovemberGroundReflectanceDefaulted();
}

double SiteGroundReflectance::decemberGroundReflectance() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->decemberGroundReflectance();
}

bool SiteGroundReflectance::isDecemberGroundReflectanceDefaulted() const {
  return getImpl<detail::SiteGroundReflectance_Impl>()->isDecemberGroundReflectanceDefaulted();
}

bool SiteGroundReflectance::setJanuaryGroundReflectance(double januaryGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setJanuaryGroundReflectance(januaryGroundReflectance);
}

void SiteGroundReflectance::resetJanuaryGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetJanuaryGroundReflectance();
}

bool SiteGroundReflectance::setFebruaryGroundReflectance(double februaryGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setFebruaryGroundReflectance(februaryGroundReflectance);
}

void SiteGroundReflectance::resetFebruaryGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetFebruaryGroundReflectance();
}

bool SiteGroundReflectance::setMarchGroundReflectance(double marchGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setMarchGroundReflectance(marchGroundReflectance);
}

void SiteGroundReflectance::resetMarchGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetMarchGroundReflectance();
}

bool SiteGroundReflectance::setAprilGroundReflectance(double aprilGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setAprilGroundReflectance(aprilGroundReflectance);
}

void SiteGroundReflectance::resetAprilGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetAprilGroundReflectance();
}

bool SiteGroundReflectance::setMayGroundReflectance(double mayGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setMayGroundReflectance(mayGroundReflectance);
}

void SiteGroundReflectance::resetMayGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetMayGroundReflectance();
}

bool SiteGroundReflectance::setJuneGroundReflectance(double juneGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setJuneGroundReflectance(juneGroundReflectance);
}

void SiteGroundReflectance::resetJuneGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetJuneGroundReflectance();
}

bool SiteGroundReflectance::setJulyGroundReflectance(double julyGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setJulyGroundReflectance(julyGroundReflectance);
}

void SiteGroundReflectance::resetJulyGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetJulyGroundReflectance();
}

bool SiteGroundReflectance::setAugustGroundReflectance(double augustGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setAugustGroundReflectance(augustGroundReflectance);
}

void SiteGroundReflectance::resetAugustGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetAugustGroundReflectance();
}

bool SiteGroundReflectance::setSeptemberGroundReflectance(double septemberGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setSeptemberGroundReflectance(septemberGroundReflectance);
}

void SiteGroundReflectance::resetSeptemberGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetSeptemberGroundReflectance();
}

bool SiteGroundReflectance::setOctoberGroundReflectance(double octoberGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setOctoberGroundReflectance(octoberGroundReflectance);
}

void SiteGroundReflectance::resetOctoberGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetOctoberGroundReflectance();
}

bool SiteGroundReflectance::setNovemberGroundReflectance(double novemberGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setNovemberGroundReflectance(novemberGroundReflectance);
}

void SiteGroundReflectance::resetNovemberGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetNovemberGroundReflectance();
}

bool SiteGroundReflectance::setDecemberGroundReflectance(double decemberGroundReflectance) {
  return getImpl<detail::SiteGroundReflectance_Impl>()->setDecemberGroundReflectance(decemberGroundReflectance);
}

void SiteGroundReflectance::resetDecemberGroundReflectance() {
  getImpl<detail::SiteGroundReflectance_Impl>()->resetDecemberGroundReflectance();
}

/// @cond
SiteGroundReflectance::SiteGroundReflectance(boost::shared_ptr<detail::SiteGroundReflectance_Impl> impl)
  : ModelObject(impl)
{}
SiteGroundReflectance::SiteGroundReflectance(Model& model)
  : ModelObject(SiteGroundReflectance::iddObjectType(),model)
{}

/// @endcond

} // model
} // openstudio

