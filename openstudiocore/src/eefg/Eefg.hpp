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

#ifndef EEFG_EEFG_HPP
#define EEFG_EEFG_HPP

#include "EefgAPI.hpp"
#include <string>

/// Read in an idd, input idf and write out a "safe" idf
/// the function is declared to be "__stdcall" for compatibility with Delphi
extern "C" __declspec( dllexport ) void __stdcall eefgValidateIdf(const char* iddPath, const char* idfPath, const char* outPath);

#endif //EEFG_EEFG_HPP