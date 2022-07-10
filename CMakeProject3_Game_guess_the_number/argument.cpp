#include "argument.hpp"

#include <algorithm>

void Arguments(int argc, char** argv, Gamer& _temp) {
	if (argc >= 2 || argc <= 4) {	// If transmitted without error;
		std::cout << "argv[1] = " << argv[1] << std::endl;

		std::string arg1_value = argv[1];
		int parameter_value = -1;
		if (arg1_value == "-max" || arg1_value == "-table" || arg1_value == "-level") {		// We check for the correct parameter

			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:			
			if (argc < 3) {
				//std::cout << "Wrong usage! The argument '-parameter' requires some value!" << std::endl;
				arg1_value == "-table" ? parameter_value = 0 : parameter_value = -1;
			}
			else {
				std::string _temp_str = argv[2];
				// If missing/incorrect parameter for -max and -level (-1) in mypair
				if (std::find_if_not(_temp_str.begin(), _temp_str.end(), [](const char ch) { return (ch >= '0' && ch <= '9'); }) != _temp_str.end()) {
					parameter_value = -1;
				}
				// If all norms std::string -> int
				else {
					int _tmp = std::stoi(argv[2]);
					if (arg1_value == "-max" && (_tmp > 1 && _tmp < 100)) { parameter_value = _tmp; }
					else if (arg1_value == "-level" && (_tmp >= 1 && _tmp <= 3)) { parameter_value = _tmp; }
					else { parameter_value = -1; }
				}
			}
		}
		else {
			arg1_value = "";
			parameter_value = -1;
		}
		_temp(arg1_value, parameter_value);
	}
	else { _temp("", -1); }
}