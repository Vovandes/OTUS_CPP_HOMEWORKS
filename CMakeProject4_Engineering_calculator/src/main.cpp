// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

void CinClear();

int main() {
	setlocale(LC_ALL, "");
	// TODO
	// Implement the next classes:
	// Add
	// Sub
	// Mul
	// Div
	// Variable

	// Without implementation that classes this application works only with numbers
	std::cout << "Enter example: ";

	Lexer lexer(std::cin);
	Parser parser(lexer);

	ASTNode* ast = parser.parse();
	if (ast) {
		ast->print(std::cout);
	}
	else {
		std::cout << "Error Input!!!" << std::endl;
	}

	delete ast;

	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cout << "Push Enter key..." << std::cin.get();

	return 0;
}