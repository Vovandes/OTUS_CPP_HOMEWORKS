// OTUS C++ Basic course homework skeleton.
// Lexer interface

#pragma once

#include <istream>
#include <string>
#include <vector>

class Lexer {
public:
	enum class Token {
		Number,
		Operator,
		End,
		Lbrace,
		Rbrace,
		Name,
		Error,
	};

	explicit Lexer(std::istream& in);

	Lexer(const Lexer& other) = delete;

	Lexer& operator=(const Lexer& other) = delete;

	Token next_token();

	int get_number() const { return number_; }

	std::string get_operator() const { return operator_; }

	std::string get_brace() const { return brace_; }

	std::string get_name() const { return name_; }

	bool get_sight_value() const { return isNegative_; }

	//std::string get_STR() const { return tmpSTR_; }

protected:
	bool isbrace(char ch) const;

	bool isoperator(char ch) const;

private:
	enum class State {
		Empty,
		ReadNumber,
		ReadName,
		End,
	};
	char next_char();
	bool end() const;

	void clearIsSpace();

	State state_;
	std::string name_;
	int number_;
	std::string operator_;
	std::string brace_;
	char ch_;
	std::istream& in_;
	bool isNegative_;

	//std::string tmpSTR_;
};
