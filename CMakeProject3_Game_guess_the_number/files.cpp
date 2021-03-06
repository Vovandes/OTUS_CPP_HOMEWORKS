#include "files.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void PrintHighScore(const std::string& file_name) {
	// Read the high score file and print all results
	std::ifstream in_file{ file_name, std::ios_base::app };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << file_name << "!" << std::endl;
		return;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username{};
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();
		if (username.empty()) {
			std::cout << "High Score is empty..." << std::endl;
			break;
		}
		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen 
		std::cout << username << '\t' << high_score << std::endl;
	}
}

void SortUsers(std::vector<std::pair<std::string, int>>& usersTable) {
	// Sort users:
	auto sort_predicate = [](std::pair<std::string, int>& elem1, std::pair<std::string, int>& elem2) {
		return elem1.first == elem2.first ? elem1.second < elem2.second : elem1.first < elem2.first;
	};
	std::sort(usersTable.begin(), usersTable.end(), sort_predicate);

	// Delete duplicates:
	auto deleting_duplicates = std::unique(usersTable.begin(), usersTable.end(),
		[](std::pair<std::string, int>& elem1, std::pair<std::string, int>& elem2) {
			return elem1.first == elem2.first;
		});
	usersTable.erase(deleting_duplicates, usersTable.end());
}

void ReadFile(std::vector<std::pair<std::string, int>>& usersTable, const std::string& file_name) {
	// Read the high score file and print all results
	std::ifstream in_file{ file_name, std::ios_base::app };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << file_name << "!" << std::endl;
		return;
	}

	std::string username{};
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}
		usersTable.emplace_back(make_pair(username, high_score));
	}
}

void WriteFile(std::vector<std::pair<std::string, int>>& usersTable, const std::string& file_name) {

	SortUsers(usersTable);
	// Write new high score to the records table
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{ file_name, std::ios_base::out };

		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << file_name << "!" << std::endl;
			return;
		}

		for (const auto& i : usersTable) {
			// Append new results to the table:
			out_file << i.first << ' ';
			out_file << i.second;
			out_file << std::endl;
		}
	} // end of score here just to mark end of the logic block of code
}
