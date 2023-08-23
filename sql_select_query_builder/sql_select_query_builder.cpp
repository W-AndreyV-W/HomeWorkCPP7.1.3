#include "sql_select_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& add_column) noexcept {

    if (num_column == 0) {

        sqlrequest.table_columns = add_column;
        num_column++;
    }
    else {

        sqlrequest.table_columns += ", " + add_column;
    }

    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {

    for (const auto& column : columns) {

        if (num_column == 0) {

            sqlrequest.table_columns = column;
            num_column++;
        }
        else {

            sqlrequest.table_columns += ", " + column;
        }
    }

    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& add_from) noexcept {

    sqlrequest.table = add_from;

    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {

    for (const auto& cond : kv) {

        if (num_where == 0) {

            sqlrequest.condition = cond.first + "=" + cond.second;
            num_where++;
        }
        else {

            sqlrequest.condition += " AND " + cond.first + "=" + cond.second;
        }
    }

    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() noexcept {

    return sqlrequest.construction();
}