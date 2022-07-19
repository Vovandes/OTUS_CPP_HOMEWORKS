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
	AtributeCmd Mode{ AtributeCmd::NONE };	// ������� �������� / �����
	int mode_atribut{};						// ������� ���������
	std::string user_name;					// ��� ������������ ���� ������� �����
	const std::string high_scores_filename = "high_scores.txt";	// ���� � ���������
	unsigned attempts_count{};				// ���������� ������ �������
	int max_value{ 31 };					// ���� ����� � ��������� �� 0 �� max_value - 1
};

