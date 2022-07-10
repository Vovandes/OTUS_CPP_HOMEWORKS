#pragma once

#include <string>
#include <iostream>

class Gamer {
	std::string mode{};			// ������� �������� 
	int mode_atribut{};			// ������� ���������
	std::string user_name{};	// ��� ������������ ���� ������� �����
	const std::string high_scores_filename = "high_scores.txt";	// ���� � ���������
	unsigned attempts_count{};	// ���������� ������ �������
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

