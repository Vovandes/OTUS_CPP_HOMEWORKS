#pragma once

#include <string>
#include <iostream>

class Gamer {
	std::string mode{};			// входной параметр 
	int mode_atribut{};			// атрибут параметра
	std::string user_name{};	// имя пользователя если игровой режим
	const std::string high_scores_filename = "high_scores.txt";	// файл с рекордами
	unsigned attempts_count{};	// количество лучших попыток
	int max_value{ 30 };
public:
	void operator()(std::string param1, int param2);

	std::string GetMode();
	int GetModeAtribut();
	std::string GetUsername();
	const std::string GetFileName();
	unsigned GetAttemptsCount();
	int GetMaxValue();

	void SetUsername();
	void SetMaxValue(int value);
	void SetAttempCount(unsigned count);
};

