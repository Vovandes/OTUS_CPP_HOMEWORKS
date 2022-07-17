#include "gamer.h"

void Gamer::operator()(AtributeCmd param1, int param2) {
	SetMode(param1);
	SetModeAtribute(param2);
	if (GetMode() == AtributeCmd::LEVEL) {
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
	if (GetMode() == AtributeCmd::MAX) {
		SetMaxValue(GetModeAtribut());
	}
}

int Gamer::GetModeAtribut() const {
	return this->mode_atribut;
}

const std::string& Gamer::GetUsername() {
	return this->user_name;
}

const std::string& Gamer::GetFileName() {
	return this->high_scores_filename;
}

unsigned Gamer::GetAttemptsCount() const {
	return this->attempts_count;
}

int Gamer::GetMaxValue() const {
	return this->max_value;
}

Gamer::AtributeCmd Gamer::GetMode() const {
	return this->Mode;
}

void Gamer::InputGamerName() {
	std::cout << "Hi! Enter your name, please: ";
	std::cin >> this->user_name;
}

void Gamer::SetModeAtribute(int value) {
	this->mode_atribut = value;
}

void Gamer::SetMaxValue(int value) {
	this->max_value = value;
}

void Gamer::SetAttempCount(unsigned count) {
	this->attempts_count = count;
}

void Gamer::SetMode(AtributeCmd mode) {
	this->Mode = mode;
}
