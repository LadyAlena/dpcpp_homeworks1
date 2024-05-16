#pragma once

#include <string>
#include <vector>
#include <map>

#include "../SqlSelectQueryBuilder.h"

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
public:
	AdvancedSqlSelectQueryBuilder& AddWhereGreaterThan(const std::string& column, const std::string& value) noexcept;
	AdvancedSqlSelectQueryBuilder& AddWhereGreaterThan(const std::map<std::string, std::string>& kv) noexcept;

	AdvancedSqlSelectQueryBuilder& AddWhereLessThan(const std::string& column, const std::string& value) noexcept;
	AdvancedSqlSelectQueryBuilder& AddWhereLessThan(const std::map<std::string, std::string>& kv) noexcept;
};