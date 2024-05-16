#include <iostream>
#include <vector>

#include "SqlSelectQueryBuilder/SqlSelectQueryBuilder.h"

int main(int argc, char** argv) {

	SqlSelectQueryBuilder query_builder;

	query_builder
		.AddColumn("name")
		.AddColumn("phone")
		.AddFrom("students")
		.AddWhere("id", "42").AddWhere("name", "John");

	std::cout << query_builder.BuildQuery() << std::endl;

	return 0;
}