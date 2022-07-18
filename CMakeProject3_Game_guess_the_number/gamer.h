#pragma once

#include <string>
#include <iostream>

class Gamer {
public:
	enum class AtributeCmd {
		ERROR = -1,	// Error;
		NONE,		// Standart Mode;
		MAX,		// Max Mode;
		LEVEL,		// Level Mode;
		TABLE		// Output High Scores
	};

	void operator()(Gamer::AtributeCmd param1, int param2);

	const std::string& GetUsername() const;
	const std::string& GetFileName() const;
	int GetModeAtribut() const;
	unsigned GetAttemptsCount() const;
	int GetMaxValue() const;
	AtributeCmd GetMode() const;

	void InputGamerName();

	void SetModeAtribute(int value);
	void SetMaxValue(int value);
	void SetAttempCount(unsigned count);
	void SetMode(AtributeCmd mode);

private:
	AtributeCmd Mode{ AtributeCmd::NONE };	// входной параметр / режим
	int mode_atribut{};						// атрибут параметра
	std::string user_name;					// имя пользователя если игровой режим
	const std::string high_scores_filename = "high_scores.txt";	// файл с рекордами
	unsigned attempts_count{};				// количество лучших попыток
	int max_value{ 31 };					// макс число в диапазоне от 0 до max_value - 1
};

