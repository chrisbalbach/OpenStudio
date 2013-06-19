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

#include <energyplus/ForwardTranslator.hpp>

#include <model/Blind.hpp>
#include <utilities/idd/OS_WindowMaterial_Blind_FieldEnums.hxx>

#include <utilities/idd/WindowMaterial_Blind_FieldEnums.hxx>
#include <utilities/idd/IddEnums.hxx>

using namespace openstudio::model;

namespace openstudio {

namespace energyplus {

boost::optional<IdfObject> ForwardTranslator::translateBlind( model::Blind & modelObject )
{
  IdfObject idfObject(openstudio::IddObjectType::WindowMaterial_Blind);

  m_idfObjects.push_back(idfObject);

  idfObject.setString(WindowMaterial_BlindFields::Name, modelObject.name().get());

  OptionalString s = modelObject.getString(OS_WindowMaterial_BlindFields::SlatOrientation, false, true);
  if (s){
    idfObject.setString(WindowMaterial_BlindFields::SlatOrientation, *s);
  }

  OptionalDouble d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatWidth, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatWidth, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatSeparation, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatSeparation, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatThickness, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatThickness, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatAngle, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatAngle, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatConductivity, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatConductivity, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatBeamSolarTransmittance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatBeamSolarTransmittance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::FrontSideSlatBeamSolarReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::FrontSideSlatBeamSolarReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BackSideSlatBeamSolarReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BackSideSlatBeamSolarReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatDiffuseSolarTransmittance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatDiffuseSolarTransmittance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::FrontSideSlatDiffuseSolarReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::FrontSideSlatDiffuseSolarReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BackSideSlatDiffuseSolarReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BackSideSlatDiffuseSolarReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatBeamVisibleTransmittance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatBeamVisibleTransmittance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::FrontSideSlatBeamVisibleReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::FrontSideSlatBeamVisibleReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BackSideSlatBeamVisibleReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BackSideSlatBeamVisibleReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatDiffuseVisibleTransmittance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatDiffuseVisibleTransmittance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::FrontSideSlatDiffuseVisibleReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::FrontSideSlatDiffuseVisibleReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BackSideSlatDiffuseVisibleReflectance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BackSideSlatDiffuseVisibleReflectance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::SlatInfraredHemisphericalTransmittance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::SlatInfraredHemisphericalTransmittance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::FrontSideSlatInfraredHemisphericalEmissivity, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::FrontSideSlatInfraredHemisphericalEmissivity, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BackSideSlatInfraredHemisphericalEmissivity, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BackSideSlatInfraredHemisphericalEmissivity, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BlindtoGlassDistance, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BlindtoGlassDistance, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BlindTopOpeningMultiplier, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BlindTopOpeningMultiplier, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BlindBottomOpeningMultiplier, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BlindBottomOpeningMultiplier, *d);
  }
  
  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BlindLeftSideOpeningMultiplier, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BlindLeftSideOpeningMultiplier, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::BlindRightSideOpeningMultiplier, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::BlindRightSideOpeningMultiplier, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::MinimumSlatAngle, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::MinimumSlatAngle, *d);
  }

  d = modelObject.getDouble(OS_WindowMaterial_BlindFields::MaximumSlatAngle, false);
  if (d){
    idfObject.setDouble(WindowMaterial_BlindFields::MaximumSlatAngle, *d);
  }

  return boost::optional<IdfObject>(idfObject);
}

} // energyplus

} // openstudio

