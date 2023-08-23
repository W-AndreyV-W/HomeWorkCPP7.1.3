#pragma once

#include <vector>
#include <map>
#include "sql_request.h"

class SqlSelectQueryBuilder {

public:

    SqlSelectQueryBuilder& AddColumn(const std::string& add_column) noexcept;

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;

    SqlSelectQueryBuilder& AddFrom(const std::string& add_from) noexcept;

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

    std::string BuildQuery() noexcept;

protected:

    SqlRequest sqlrequest;

    int num_column = 0;
    int num_where = 0;
};