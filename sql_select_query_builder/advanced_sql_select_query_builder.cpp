#include "advanced_sql_select_query_builder.h"

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::More(const std::string& column, const std::string& meaning) noexcept {

    Where(column, meaning, ">");

    return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::Less(const std::string& column, const std::string& meaning) noexcept {

    Where(column, meaning, "<");

    return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::Where(const std::string& column, const std::string& meaning, const std::string sign) noexcept {

    if (SqlSelectQueryBuilder::num_where == 0) {

        sqlrequest.condition = column + sign + meaning;
        num_where++;
    }
    else {

        sqlrequest.condition += " AND " + column + sign + meaning;
    }

    return *this;
}