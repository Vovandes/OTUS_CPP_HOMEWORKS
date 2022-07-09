#include "argument.h"
#include "game.h"

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	std::cout << "> Games guess the number < " << std::endl;

	std::pair<std::string, int> mypair{};
	const std::string high_scores_filename = "high_scores.txt";

	if (argc >= 2) { Arguments(argc, argv, mypair); }

	if (mypair.first.empty() || mypair.second == -1) {
		std::cout << "Incorrect parametr!!!" << std::endl;
		system("pause");
		return -1;
	}

	std::cout << mypair.first << "\t" << mypair.second << std::endl;

	// Ask about name
	std::string user_name{};	// Имя пользователя
	std::cout << "Hi! Enter your name, please: ";
	std::cin >> user_name;

	unsigned attempts_count = 0;	// Количество попыток при угадывании



	system("pause");
	return 0;
}