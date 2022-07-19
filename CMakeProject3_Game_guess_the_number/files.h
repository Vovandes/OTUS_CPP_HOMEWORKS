#pragma once

#include <string>
#include <vector>

void PrintHighScore(const std::string& file_name);

void SortUsers(std::vector<std::pair<std::string, int>>& usersTable);

void ReadFile(std::vector<std::pair<std::string, int>>& usersTable, const std::string& file_name);

void WriteFile(std::vector<std::pair<std::string, int>>& usersTable, const std::string& file_name);