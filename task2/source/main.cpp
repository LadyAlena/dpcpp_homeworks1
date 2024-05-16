#include <iostream>
#include <vector>

#include "SqlSelectQueryBuilder/SqlSelectQueryBuilder.h"

int main(int argc, char** argv) {

	SqlSelectQueryBuilder query_builder;

	query_builder
		.AddColumn("name")
		.AddColumn("phone")
		.AddColumns({ "id", "age" })
		.AddFrom("students")
		.AddWhere({ std::make_pair("id", "42"), std::make_pair("name", "John") })
		.AddWhere("id", "12")
		.AddFrom("people");

	std::cout << query_builder.BuildQuery() << std::endl;

	return 0;
}