#include "Files.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void PrintHighScore(const std::string file_name) {
	try {
		// Read the high score file and print all results
		std::ifstream in_file{ file_name };
		if (!in_file.is_open()) {
			throw "Failed to open file for read: " + file_name + "!";
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

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen 
			std::cout << username << '\t' << high_score << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const char* msg_error) {
		std::cout << msg_error << std::endl;
	}
}

void SortUsers(std::vector<std::pair<std::string, int>>& usersTable) {
	// Sort users:
	std::sort(usersTable.begin(), usersTable.end(),
		[](std::pair<std::string, int>& elem1, std::pair<std::string, int>& elem2) {
			return elem1.first == elem2.first ? elem1.second < elem2.second : elem1.first < elem2.first;
		});
	// Delete duplicates:
	auto deleting_duplicates = std::unique(usersTable.begin(), usersTable.end(),
		[](std::pair<std::string, int>& elem1, std::pair<std::string, int>& elem2) {
			return elem1.first == elem2.first;
		});
	usersTable.erase(deleting_duplicates, usersTable.end());
}

void ReadFile(std::vector<std::pair<std::string, int>>& usersTable, const std::string file_name) {
	try {
		// Read the high score file and print all results
		std::ifstream in_file{ file_name, std::ios_base::app };
		if (!in_file.is_open()) {
			throw "Failed to open file for read: " + file_name + "!";
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
			usersTable.push_back(make_pair(username, high_score));
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const char* msg_error) {
		std::cout << msg_error << std::endl;
	}
}

void WriteFile(std::vector<std::pair<std::string, int>>& usersTable, const std::string file_name) {
	try {
		SortUsers(usersTable);
		// Write new high score to the records table
		{
			// We should open the output file in the append mode - we don't want
			// to erase previous results.
			std::ofstream out_file{ file_name, std::ios_base::out };

			if (!out_file.is_open()) {
				throw "Failed to open file for write: " + file_name + "!";
			}

			for (const auto& i : usersTable) {
				// Append new results to the table:
				out_file << i.first << ' ';
				out_file << i.second;
				out_file << std::endl;
			}
		} // end of score here just to mark end of the logic block of code
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const char* msg_error) {
		std::cout << msg_error << std::endl;
	}
}