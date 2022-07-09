#include "argument.h"

#include <iostream>
#include <algorithm>

void Arguments(int argc, char** argv, std::pair<std::string, int>& _temp) {
	if (argc >= 2 || argc <= 4) {	// Если передали без ошибки;
		std::cout << "We have one more argument!" << std::endl;
		std::cout << "argv[1] = " << argv[1] << std::endl;

		std::string arg1_value = argv[1];
		int parameter_value = -1;
		if (arg1_value == "-max" || arg1_value == "-table" || arg1_value == "-level") {		// Проверяем на корректный параметр
			std::cout << "argument was detected!" << std::endl;

			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:			
			if (argc < 3) {
				//std::cout << "Wrong usage! The argument '-parameter' requires some value!" << std::endl;
				arg1_value == "-table" ? parameter_value = 0 : parameter_value = -1;
			}
			else {
				std::string _temp_str = argv[2];
				// Если отсутствует/некорректный параметр для -max и -level (-1) в mypair
				if (std::find_if_not(_temp_str.begin(), _temp_str.end(), [](const char ch) { return (ch >= '0' && ch <= '9'); }) != _temp_str.end()) {
					parameter_value = -1;
				}
				// Если все норм std::string -> int
				else {
					int _tmp = std::stoi(argv[2]);
					if (arg1_value == "-max" && (_tmp > 1 && _tmp < 100)) {
						parameter_value = _tmp;
					}
					else if (arg1_value == "-level" && (_tmp >= 1 && _tmp <= 3)) {
						parameter_value = _tmp;
					}
					else {
						parameter_value = -1;
					}
				}
			}
		}
		else {
			arg1_value = "";
			parameter_value = -1;
		}
		_temp = std::make_pair(arg1_value, parameter_value);
	}
	else {
		_temp = std::make_pair("", -1);
	}
}