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

#ifndef PROJECT_STANDARDSATTRIBUTECHECKRULERECORD_IMPL_HPP
#define PROJECT_STANDARDSATTRIBUTECHECKRULERECORD_IMPL_HPP

#include "ProjectAPI.hpp"
#include <project/StandardsRuleRecord_Impl.hpp>

#include <utilities/core/Logger.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/optional/optional.hpp>

class QSqlDatabase;

namespace openstudio {

namespace ruleset {
  class StandardsAttributeCheckRule;
}

namespace project {

namespace detail {

  class PROJECT_API StandardsAttributeCheckRuleRecord_Impl : public StandardsRuleRecord_Impl {
    Q_OBJECT;
    public:

    /// constructors
    StandardsAttributeCheckRuleRecord_Impl(
        const openstudio::ruleset::StandardsAttributeCheckRule& standardsAttributeCheckRule, 
        const ProjectDatabase& projectDatabase);

    /// constructor from query, throws if bad query
    StandardsAttributeCheckRuleRecord_Impl(const QSqlQuery& query, 
                                           const ProjectDatabase& projectDatabase);

    virtual ~StandardsAttributeCheckRuleRecord_Impl() {}
    
    /// get the standards rule
    virtual openstudio::ruleset::StandardsRule standardsRule() const;

    /// save the row for just this object in the database
    /// requires ProjectDatabase as called in ProjectDatabase ctor/dtor
    virtual void saveRow(const boost::shared_ptr<QSqlDatabase> &database);

   protected:

    /// bind values to a query for saving
    /// override in derived classes
    virtual void bindValues(QSqlQuery& query) const;

    /// set the last state of this object from the query (including id)
    /// override in derived classes
    virtual void setLastValues(const QSqlQuery& query, ProjectDatabase& projectDatabase);

    /// check that values (except id) are same as query
    /// override in derived classes
    virtual bool compareValues(const QSqlQuery& query) const;

    /// save values to last state
    /// override in derived classes
    virtual void saveLastValues();

    /// revert values back to last state
    /// override in derived classes
    virtual void revertToLastValues();

    private:

    REGISTER_LOGGER("openstudio.project.StandardsAttributeCheckRuleRecord");

  };

} // detail
} // project
} // openstudio

#endif // PROJECT_STANDARDSATTRIBUTECHECKRULERECORD_IMPL_HPP
