// OTUS C++ Basic course homework skeleton.
// Lexer implementation

#include "lexer.hpp"
#include "parser.hpp"

#include <cctype>
#include <iostream>

Lexer::Token Lexer::next_token() {

	for (;;) {
		switch (state_) {
		case State::End:
			return Token::End;
		case State::ReadNumber:
			if (end()) {
				state_ = State::End;
				return Token::Number;
			}
			if (std::isdigit(ch_)) {
				number_ = 10 * number_ + (ch_ - '0');
				state_ = State::ReadNumber;
				next_char();
				break;
			}
			if (std::isspace(ch_)) {
				clearIsSpace();
			}
			if(!isoperator(ch_) && ch_ != ')') {
				state_ = State::End;
				return Token::Error;
			}
			state_ = State::Empty;
			return Token::Number;
		case State::ReadName:
			if (end()) {
				state_ = State::End;
				return Token::Name;
			}
			if ((std::isalpha(ch_) || std::isdigit(ch_)) || end()) {
				name_ += ch_;
				next_char();
				break;
			}
			if (std::isspace(ch_)) {
				clearIsSpace();
			}
			if (!isoperator(ch_) && ch_ != ')') {
				state_ = State::End;
				return Token::Error;
			}
			state_ = State::Empty;
			return Token::Name;
		case State::Empty:
			if (end()) {
				state_ = State::End;
				return Token::End;
			}
			if (std::isspace(ch_)) {
				next_char();
				break;
			}
			if (isoperator(ch_)) {
				operator_ = ch_;
				next_char();
				return Token::Operator;
			}
			if (ch_ == '(') {
				next_char();
				if (std::isspace(ch_)) {
					clearIsSpace();
				}
				if (isoperator(ch_)) {
					state_ = State::End;
					return Token::Error;
				}
				return Token::Lbrace;
			}
			if (ch_ == ')') {
				next_char();
				return Token::Rbrace;
			}
			if (std::isdigit(ch_)) {
				number_ = ch_ - '0';
				state_ = State::ReadNumber;
				next_char();
				break;
			}
			if (std::isalpha(ch_)) {
				name_ = ch_;
				state_ = State::ReadName;
				next_char();
				break;
			}
		}
	}
}

Lexer::Lexer(std::istream& in)
	: state_(State::Empty)
	, number_(0)
	, in_(in) {
	next_char();
	if (std::isspace(static_cast<unsigned char>(ch_)) && !end()) {
		clearIsSpace();
	}
}

char Lexer::next_char() {
	in_.get(ch_);
	//tmpSTR_.push_back(ch_);
	return ch_;
}

bool Lexer::end() const { return in_.eof() || ch_ == '\n'; }

bool Lexer::isbrace(char ch) const { return ch == '(' || ch == ')'; }

bool Lexer::isoperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void Lexer::clearIsSpace() {
	while (std::isspace(static_cast<unsigned char>(ch_)) && !end()) {
		next_char();
	}
}