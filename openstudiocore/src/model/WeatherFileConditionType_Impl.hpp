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

#ifndef MODEL_WEATHERFILECONDITIONTYPE_IMPL_HPP
#define MODEL_WEATHERFILECONDITIONTYPE_IMPL_HPP

#include <model/SizingPeriod_Impl.hpp>

namespace openstudio {
namespace model {

namespace detail {

  class MODEL_API WeatherFileConditionType_Impl : public SizingPeriod_Impl {
    Q_OBJECT;
   public:

    // constructor
    WeatherFileConditionType_Impl(const IdfObject& idfObject, Model_Impl* model, bool keepHandle);

    // construct from workspace
    WeatherFileConditionType_Impl(const openstudio::detail::WorkspaceObject_Impl& other, 
                   Model_Impl* model, 
                   bool keepHandle);

    // clone copy constructor
    WeatherFileConditionType_Impl(const WeatherFileConditionType_Impl& other,Model_Impl* model,bool keepHandle);

    // virtual destructor
    virtual ~WeatherFileConditionType_Impl(){}

    // Get all output variable names that could be associated with this object.
    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;
  
   private:

    REGISTER_LOGGER("openstudio.model.WeatherFileConditionType");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_WEATHERFILECONDITIONTYPE_IMPL_HPP
