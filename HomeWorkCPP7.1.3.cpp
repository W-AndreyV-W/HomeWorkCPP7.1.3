#include <iostream>
#include "advanced_sql_select_query_builder.h"

int main()
{
    AdvancedSqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddFrom("students");
    query_builder.More("id", "42");
    query_builder.AddWhere({ {"name", "John"} });

    std::cout << query_builder.BuildQuery() << std::endl;
}