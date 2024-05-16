#include <iostream>
#include <vector>

#include "SqlSelectQueryBuilder/SqlSelectQueryBuilder.h"
#include "SqlSelectQueryBuilder/AdvancedSqlSelectQueryBuilder/AdvancedSqlSelectQueryBuilder.h"

int main(int argc, char** argv) {

	AdvancedSqlSelectQueryBuilder query_builder;
	query_builder
		.AddColumns({ "name", "phone" })
		.AddFrom("students");
	query_builder.AddWhereLessThan("id", "42");
	query_builder.AddWhere("name", "Maria");

	std::cout << query_builder.BuildQuery() << std::endl;

	return 0;
}