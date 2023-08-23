#pragma once

#include "sql_select_query_builder.h"

class AdvancedSqlSelectQueryBuilder :public SqlSelectQueryBuilder {

public:

    AdvancedSqlSelectQueryBuilder& More(const std::string& column, const std::string& meaning) noexcept;

    AdvancedSqlSelectQueryBuilder& Less(const std::string& column, const std::string& meaning) noexcept;

protected:
    
    AdvancedSqlSelectQueryBuilder& Where(const std::string& column, const std::string& meaning, const std::string sign) noexcept;
};