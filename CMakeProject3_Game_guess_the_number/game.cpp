#include "game.h"

#include <ctime>

void RunGame(Gamer& gamer) {
	// Ask about name	
	gamer.InputGamerName();

	auto x = gamer.GetMaxValue();

	unsigned count = 0;

	std::srand(static_cast<unsigned>(std::time(nullptr))); // use current time as seed for random generator

	const int target_value = std::rand() % x;	// Значение поиска
	int current_value = 0;			// Значение вводимое пользователем

	do {
		std::cout << "Enter your guess from 0 to " << x - 1 << ": ";
		while (!(std::cin >> current_value) || current_value < 0 || current_value >= x) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Incorrect input!!!" << std::endl;
			std::cout << "Enter your guess from 0 to " << x - 1 << ": ";
		}

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			gamer.SetAttempCount(++count);
			break;
		}
		++count;
	} while (true);
}