#include "game.h"

#include <iostream>
#include <ctime>

void Game() {
	const int max_value = 100;

	unsigned short count = 0;

	std::srand(static_cast<unsigned>(std::time(nullptr))); // use current time as seed for random generator

	const int target_value = std::rand() % max_value;	// Значение поиска
	int current_value = 0;			// Значение вводимое пользователем
	bool not_win = true;		// bool на проверку победы

	do {
		std::cout << "Enter your guess:" << std::endl;
		while (!(std::cin >> current_value)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Incorrect input!!!" << std::endl;
		}

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while (true);
}