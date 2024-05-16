#pragma once

#include <string>
#include <vector>

class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string& table_name) noexcept;
	SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) noexcept;
	
	std::string BuildQuery() noexcept;

private:
	std::vector<std::string> selected_columns;
	std::string table_name;
	std::vector<std::string> columns;
	std::vector <std::string> values;
	std::vector<std::string> conditional_operators;
};