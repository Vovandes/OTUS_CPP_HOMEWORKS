#include "Gamer.h"

void Gamer::operator()(std::string param1, int param2) {
	this->mode = param1;
	this->mode_atribut = param2;
	if (GetMode() == "-level") {
		switch (GetModeAtribut()) {
		case 1:
			SetMaxValue(10);
			break;
		case 2:
			SetMaxValue(50);
			break;
		case 3:
			SetMaxValue(100);
			break;
		}
	}
	if (GetMode() == "-max") {
		SetMaxValue(GetModeAtribut());
	}
}

std::string Gamer::GetMode() {
	return this->mode;
}

int Gamer::GetModeAtribut() {
	return this->mode_atribut;
}

std::string Gamer::GetUsername() {
	return this->user_name;
}

const std::string Gamer::GetFileName() {
	return this->high_scores_filename;
}

unsigned Gamer::GetAttemptsCount() {
	return this->attempts_count;
}

int Gamer::GetMaxValue() {
	return this->max_value;
}

void Gamer::SetUsername() {
	std::cout << "Hi! Enter your name, please: ";
	std::cin >> this->user_name;
}

void Gamer::SetMaxValue(int value) {
	this->max_value = value;
}

void Gamer::SetAttempCount(unsigned count) {
	this->attempts_count = count;
}
