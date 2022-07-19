#include <iostream>
#include <vector>

#include "argument.h"
#include "game.h"
#include "files.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	std::cout << "> Games guess the number < " << std::endl;

	Gamer gamer;

	std::vector<std::pair<std::string, int>> users_container;

	ReadArguments(argc, argv, gamer);

	switch (gamer.GetMode()) {
	case Gamer::AtributeCmd::ERROR:
		std::cout << "Incorrect parametr!!!" << std::endl;
		system("pause");
		return -1;
	case Gamer::AtributeCmd::TABLE:
		PrintHighScore(gamer.GetFileName());
		system("pause");
		return 0;
	default:
		RunGame(gamer);
		users_container.emplace_back(make_pair(gamer.GetUsername(), gamer.GetAttemptsCount()));
		break;
	}

	// Read hight_score.txt
	ReadFile(users_container, gamer.GetFileName());
	// Write in hight_score.txt
	WriteFile(users_container, gamer.GetFileName());

	system("pause");
	return 0;
}