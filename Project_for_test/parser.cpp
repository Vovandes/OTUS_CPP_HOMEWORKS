#include "parser.hpp"
#include "number.hpp"

#include "add.hpp"
#include "sub.hpp"
#include "mul.hpp"
#include "div.hpp"
#include "variable.hpp"

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
				++operatorCount;
				break;
			case '-':
				// Implement Sub class and uncomment this line
				root = new Sub(root, term());
				++operatorCount;
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
				++operatorCount;
				break;
			case '/':
				// Implement Div class and uncomment this line
				root = new Div(root, prim());
				++operatorCount;
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
		if (tok_ == Token::Name) {
			++no_of_errors_;
		}
		break;
	case Token::Name:
		// Implement Variable class and uncomment this line
		node = new Variable(lexer_.get_name());
		if (tok_ == Token::Number) {
			++no_of_errors_;
		}
		break;
	case Token::Rbrace:
		break;
	case Token::Operator:
		++no_of_errors_;
	case Token::Error:
		++no_of_errors_;
	default:
		++no_of_errors_;
		node = new ASTNode("Error", nullptr, nullptr);
		return node;
		break;
	}
	next_token();
	if (tok_ == Token::Error) {
		++no_of_errors_;
		node = new ASTNode("Error");
		return node;
	}
	return node;
}