#ifndef OPENSTUDIO_SUMMARYDATA
#define OPENSTUDIO_SUMMARYDATA

#include <utilities/units/Unit.hpp>
#include <utilities/data/DataEnums.hpp>
#include "SqlFileEnums.hpp"

namespace openstudio
{
  struct SummaryData
  {
    SummaryData(double t_value, Unit t_units, ReportingFrequency t_reportingFrequency, FuelType t_fuelType, 
        InstallLocationType t_installLocationType)
      : value(t_value), units(t_units), reportingFrequency(t_reportingFrequency), fuelType(t_fuelType), installLocationType(t_installLocationType)
    {
    }

    double value;
    Unit units;
    ReportingFrequency reportingFrequency;
    FuelType fuelType;
    InstallLocationType installLocationType;
  };

}

#endif

