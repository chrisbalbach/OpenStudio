/**********************************************************************
*  Copyright (c) 2008-2010, Alliance for Sustainable Energy.
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

#include <ESPR/Test/ESPRFixture.hpp>

#include <resources.hxx>

void ESPRFixture::SetUp() {}

void ESPRFixture::TearDown() {}

void ESPRFixture::SetUpTestCase() {
  // set up logging
  openstudio::Logger::instance().standardOutLogger().disable();
  logFile = boost::shared_ptr<openstudio::FileLogSink>(new openstudio::FileLogSink(openstudio::toPath("./ESPRFixture.log")));
}

void ESPRFixture::TearDownTestCase() {
  logFile->disable();
}

boost::shared_ptr<openstudio::FileLogSink> ESPRFixture::logFile;