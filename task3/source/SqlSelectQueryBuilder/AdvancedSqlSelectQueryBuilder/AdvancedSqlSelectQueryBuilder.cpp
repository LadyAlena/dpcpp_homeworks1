#include "AdvancedSqlSelectQueryBuilder.h"

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereGreaterThan(const std::string& column, const std::string& value) noexcept {
	AddWhere(column, value);
	conditional_operators.back() = ">";
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereGreaterThan(const std::map<std::string, std::string>& kv) noexcept {
	AddWhere(kv);

	auto start_index = conditional_operators.size() - kv.size();

	std::fill(conditional_operators.begin() + start_index, conditional_operators.end(), ">");

	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereLessThan(const std::string& column, const std::string& value) noexcept {
	AddWhere(column, value);
	conditional_operators.back() = "<";
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereLessThan(const std::map<std::string, std::string>& kv) noexcept {
	AddWhere(kv);

	auto start_index = conditional_operators.size() - kv.size();

	std::fill(conditional_operators.begin() + start_index, conditional_operators.end(), "<");

	return *this;
}