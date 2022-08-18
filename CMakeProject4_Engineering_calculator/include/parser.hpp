#pragma once

#include <istream>

#include "astnode.hpp"
#include "lexer.hpp"

class Parser {
public:
	explicit Parser(Lexer& lexer)
		: lexer_{ lexer } {}

	Parser(const Parser& other) = delete;

	Parser& operator=(const Parser& other) = delete;

	~Parser() = default;

	ASTNode* parse();

	static int get_no_of_errors() { return no_of_errors_; }

	static int no_of_errors_;	// Хранит количество встречаемых ошибок.

private:
	void next_token();

	ASTNode* expr();

	ASTNode* term();

	ASTNode* prim();

	ASTNode* ReturnNull(ASTNode* obj);

	Lexer& lexer_;
	Lexer::Token tok_{};
};
