#include "parser.hpp"
#include "number.hpp"

#include "add.hpp"
#include "sub.hpp"
#include "mul.hpp"
#include "div.hpp"
#include "variable.hpp"

#include <limits>

int Parser::no_of_errors_ = 0;

using Token = Lexer::Token;

ASTNode* Parser::parse() { return expr(); }

void Parser::next_token() { tok_ = lexer_.next_token(); }

ASTNode* Parser::expr() {
	// parse addition and subsctruction
	ASTNode* root = term();
	for (;;) {
		switch (tok_) {
		case Token::Operator: {
			std::string op = lexer_.get_operator();
			switch (op.front()) {
			case '+':
				// Implement Add class and uncomment this line
				root = new Add(root, term());
				break;
			case '-':
				// Implement Sub class and uncomment this line
				root = new Sub(root, term());
				break;
			default:
				return root;
			}
			break;
		}
		default:
			return root;
		}
	}
}

ASTNode* Parser::term() {
	// parse multiplication and division
	ASTNode* root = prim();
	for (;;) {
		switch (tok_) {
		case Token::Operator: {
			std::string op = lexer_.get_operator();
			switch (op.front()) {
			case '*':
				// Implement Mul class and uncomment this line
				root = new Mul(root, prim());
				break;
			case '/':
				// Implement Div class and uncomment this line
				root = new Div(root, prim());
				break;
			default:
				return root;
			}
			break;
		}
		default:
			return root;
		}
	}
}

ASTNode* Parser::prim() {
	// parse numbers and names
	ASTNode* node = nullptr;
	next_token();
	switch (tok_) {
	case Token::Lbrace:
		node = expr();
		if (tok_ != Token::Rbrace) {
			++no_of_errors_;
		}
		break;
	case Token::Number:
		node = new Number(lexer_.get_number());
		if (tok_ == Token::Error) {
			return ReturnNull(node);
		}
		break;
	case Token::Name:
		node = new Variable(lexer_.get_name());
		if (tok_ == Token::Error) {
			return ReturnNull(node);
		}
		break;
	case Token::Rbrace:
		if (lexer_.get_brace().front() != '(') {
			++no_of_errors_;
		}
		break;
	case Token::Operator:
		if (lexer_.get_operator() != "-") {
			++no_of_errors_;
		}
		break;
	case Token::Error:
		++no_of_errors_;
		break;
	default:
		++no_of_errors_;
		return ReturnNull(node);
		break;
	}
	if (!no_of_errors_) {
		next_token();
		if (tok_ == Token::Error) {
			return ReturnNull(node);
		}
	}
	else {
		return ReturnNull(node);
	}
	return node;
}

ASTNode* Parser::ReturnNull(ASTNode* obj) {
	if (obj) {
		delete obj;
		obj = nullptr;
	}
	return obj;
}