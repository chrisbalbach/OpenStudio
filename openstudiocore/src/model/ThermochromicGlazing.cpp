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

#include <model/ThermochromicGlazing.hpp>
#include <model/ThermochromicGlazing_Impl.hpp>
#include <model/ModelExtensibleGroup.hpp>

#include <utilities/idd/OS_WindowMaterial_GlazingGroup_Thermochromic_FieldEnums.hxx>

#include <utilities/core/Assert.hpp>
#include <utilities/math/FloatCompare.hpp>

namespace openstudio {
namespace model {

namespace detail {

  ThermochromicGlazing_Impl::ThermochromicGlazing_Impl(const IdfObject& idfObject,
                                                       Model_Impl* model,
                                                       bool keepHandle)
    : Glazing_Impl(idfObject,model,keepHandle)
  {
    BOOST_ASSERT(idfObject.iddObject().type() == ThermochromicGlazing::iddObjectType());
  }

  ThermochromicGlazing_Impl::ThermochromicGlazing_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                       Model_Impl* model,
                                                       bool keepHandle)
    : Glazing_Impl(other,model,keepHandle)
  {
    BOOST_ASSERT(other.iddObject().type() == ThermochromicGlazing::iddObjectType());
  }

  ThermochromicGlazing_Impl::ThermochromicGlazing_Impl(const ThermochromicGlazing_Impl& other,
                                                       Model_Impl* model,
                                                       bool keepHandle)
    : Glazing_Impl(other,model,keepHandle)
  {}

  IddObjectType ThermochromicGlazing_Impl::iddObjectType() const {
    return ThermochromicGlazing::iddObjectType();
  }

  double ThermochromicGlazing_Impl::thickness() const {
    GlazingVector glazings = mf_glazings();
    double result = 0.0;         // running average
    unsigned n = 0;
    bool warned = false;
    BOOST_FOREACH(const Glazing& glazing,glazings) {
      double glazingThickness = glazing.thickness();
      if (n == 0) {
        result = glazingThickness;
      }
      else {
        // keep runnning average
        if (!warned && ! equal(glazingThickness,result)) {
          LOG(Warn,"Thermochromic group '" << name().get() << "' contains glazings of different "
              << "thicknesses.");
          warned = true;
        }
        result = (result*static_cast<double>(n) + glazingThickness)/static_cast<double>(n + 1);
      }
      ++n;
    }
    return result;
  }

  double ThermochromicGlazing_Impl::thermalConductivity() const {
    LOG_AND_THROW("Thermal conductivity not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::thermalConductance() const {
    LOG_AND_THROW("Thermal conductance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::thermalResistivity() const {
    LOG_AND_THROW("Thermal resistivity not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::thermalResistance() const {
    LOG_AND_THROW("Thermal resistance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::thermalTransmittance() const {
    LOG_AND_THROW("Thermal transmittance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::thermalAbsorptance() const {
    LOG_AND_THROW("Thermal absorptance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::thermalReflectance() const {
    LOG_AND_THROW("Thermal reflectance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::solarTransmittance() const {
    LOG_AND_THROW("Solar transmittance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::solarAbsorptance() const {
    LOG_AND_THROW("Solar absorptance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::solarReflectance() const {
    LOG_AND_THROW("Solar reflectance not yet supported for ThermochromicGlazings.");
  }

  OptionalDouble ThermochromicGlazing_Impl::getVisibleTransmittance() const {
    LOG_AND_THROW("Visible transmittance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::visibleAbsorptance() const {
    LOG_AND_THROW("Visible absorptance not yet supported for ThermochromicGlazings.");
  }

  double ThermochromicGlazing_Impl::visibleReflectance() const {
    LOG_AND_THROW("Visible reflectance not yet supported for ThermochromicGlazings.");
  }

  const std::vector<std::string>& ThermochromicGlazing_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  bool ThermochromicGlazing_Impl::setThickness(double value) {
    GlazingVector glazings = mf_glazings();
    DoubleVector rollbackValues;
    for (unsigned i = 0,n = glazings.size(); i < n; ++ i) {
      rollbackValues.push_back(glazings[i].thickness());
      bool ok = glazings[i].setThickness(value);
      if (!ok) {
        // rollback previous values
        for (int j = i-1; j <= 0; --j) {
          glazings[j].setThickness(rollbackValues[j]);
        }
        return false;
      }
    }
    return true;
  }

  bool ThermochromicGlazing_Impl::setThermalConductivity(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setThermalConductance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setThermalResistivity(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setThermalResistance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setThermalTransmittance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setThermalAbsorptance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setThermalReflectance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setSolarTransmittance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setSolarAbsorptance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setSolarReflectance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setVisibleTransmittance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setVisibleAbsorptance(double value) {
    return false;
  }

  bool ThermochromicGlazing_Impl::setVisibleReflectance(double value) {
    return false;
  }

  std::vector<Glazing> ThermochromicGlazing_Impl::mf_glazings() const {
    GlazingVector result;
    BOOST_FOREACH(const IdfExtensibleGroup& idfGroup,extensibleGroups()) {
      ModelExtensibleGroup group = idfGroup.cast<ModelExtensibleGroup>();
      OptionalWorkspaceObject owo = group.getTarget(OS_WindowMaterial_GlazingGroup_ThermochromicExtensibleFields::WindowMaterialGlazingName);
      if (owo) {
        OptionalGlazing og = owo->optionalCast<Glazing>();
        BOOST_ASSERT(og);
        result.push_back(*og);
      }
    }
    return result;
  }

} // detail

ThermochromicGlazing::ThermochromicGlazing(const Model& model)
  : Glazing(ThermochromicGlazing::iddObjectType(),model)
{
  BOOST_ASSERT(getImpl<detail::ThermochromicGlazing_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  bool ok = true;
  // ok = setHandle();
  BOOST_ASSERT(ok);
}

IddObjectType ThermochromicGlazing::iddObjectType() {
  return IddObjectType(IddObjectType::OS_WindowMaterial_GlazingGroup_Thermochromic);
}

/// @cond
ThermochromicGlazing::ThermochromicGlazing(boost::shared_ptr<detail::ThermochromicGlazing_Impl> impl)
  : Glazing(impl)
{}
/// @endcond

} // model
} // openstudio

