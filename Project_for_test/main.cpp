// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

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
		//std::cout << "You input: " << lexer.get_STR() << std::endl;
		ast->print(std::cout);
	}

	std::system("pause");
	return 0;
}
