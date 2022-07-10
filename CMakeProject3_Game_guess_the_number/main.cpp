#include <iostream>
#include <vector>

extern std::vector<std::pair<std::string, int>> users_container;

#include "argument.hpp"
#include "game.hpp"
#include "Files.hpp"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	std::cout << "> Games guess the number < " << std::endl;

	Gamer gamer;


	if (argc >= 2) {
		Arguments(argc, argv, gamer);
		if (gamer.GetMode().empty() || gamer.GetModeAtribut() == -1) {
			std::cout << "Incorrect parametr!!!" << std::endl;
			system("pause");
			return -1;
		}
		if (gamer.GetMode() == "-table") {
			PrintHighScore(gamer.GetFileName());
			system("pause");
			return 0;
		}
	}

	Game(gamer);
	users_container.emplace_back(make_pair(gamer.GetUsername(), gamer.GetAttemptsCount()));

	// Read hight_score.txt
	ReadFile(users_container, gamer.GetFileName());
	// Write in hight_score.txt
	WriteFile(users_container, gamer.GetFileName());

	system("pause");
	return 0;
}