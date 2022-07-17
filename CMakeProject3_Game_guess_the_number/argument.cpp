#include "argument.h"

#include <algorithm>

void ReadArguments(int argc, char** argv, Gamer& temp) {
	Gamer::AtributeCmd temp_mode{ Gamer::AtributeCmd::ERROR };
	int parameter_value = 0;	// числовой аргумент
	if (argc == 1) {
		temp_mode = Gamer::AtributeCmd::NONE;
	}
	else if (argc >= 2 || argc <= 4) {	// If transmitted without error;
		std::cout << "argv[1] = " << argv[1] << std::endl;

		std::string arg1_value = argv[1];

		if (arg1_value == "-max" || arg1_value == "-table" || arg1_value == "-level") {		// We check for the correct parameter

			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:			
			if (argc < 3) {
				//std::cout << "Wrong usage! The argument '-parameter' requires some value!" << std::endl;
				arg1_value == "-table" ? temp_mode = Gamer::AtributeCmd::TABLE : temp_mode = Gamer::AtributeCmd::ERROR;
			}
			else {
				std::string temp_str = argv[2];
				// If missing/incorrect parameter for -max and -level (-1) in mypair
				if (std::find_if_not(temp_str.begin(), temp_str.end(), [](const char ch) { return (ch >= '0' && ch <= '9'); }) != temp_str.end()) {
					temp_mode = Gamer::AtributeCmd::ERROR;
				}
				// If all norms std::string -> int
				else {
					int tmp_param = std::stoi(argv[2]);
					if (arg1_value == "-max" && (tmp_param > 1 && tmp_param < 100)) {
						temp_mode = Gamer::AtributeCmd::MAX;
						parameter_value = tmp_param;
					}
					else if (arg1_value == "-level" && (tmp_param >= 1 && tmp_param <= 3)) {
						temp_mode = Gamer::AtributeCmd::LEVEL;
						parameter_value = tmp_param;
					}
					else { temp_mode = Gamer::AtributeCmd::ERROR; }
				}
			}
		}
		else {
			temp_mode = Gamer::AtributeCmd::ERROR;
		}
	}
	else {
		temp_mode = Gamer::AtributeCmd::ERROR;
	}
	// Set mode game:
	temp(temp_mode, parameter_value);
}