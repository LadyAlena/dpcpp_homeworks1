#pragma once

#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept;
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string& table_name) noexcept;
	SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) noexcept;
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
	
	std::string BuildQuery() noexcept;

private:
	std::vector<std::string> selected_columns;
	std::string table_name;
	std::vector<std::string> columns;
	std::vector <std::string> values;
	std::vector<std::string> conditional_operators;
};