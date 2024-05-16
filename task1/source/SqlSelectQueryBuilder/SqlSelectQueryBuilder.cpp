#include "SqlSelectQueryBuilder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) noexcept {
	selected_columns.push_back(column);
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table_name) noexcept {
	this->table_name = table_name;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) noexcept {
	conditional_operators.push_back("=");
	columns.push_back(column);
	values.push_back(value);
	return *this;
}

std:: string SqlSelectQueryBuilder::BuildQuery() noexcept {

	if (selected_columns.empty()) {
		selected_columns.push_back("*");
	}

	std::string selected_column_names_str{};
	for (size_t i = 0; i < selected_columns.size(); ++i) {
		selected_column_names_str += selected_columns[i];
		if (i < selected_columns.size() - 1) {
			selected_column_names_str += ", ";
		}
	}

	std::string condition{};
	for (size_t i = 0; i < columns.size(); i++) {
		condition += columns[i] + conditional_operators[i] + values[i];
		if (i < columns.size() - 1) {
			condition += " AND ";
		}
	}

	return "SELECT " + selected_column_names_str + " FROM " + table_name + " WHERE " + condition + ";";
}