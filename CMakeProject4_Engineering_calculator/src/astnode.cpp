#include "astnode.hpp"
#include "parser.hpp"

ASTNode::ASTNode(const std::string& repr)
	: repr_(repr)
	, lhs_{ nullptr }
	, rhs_{ nullptr } {}

ASTNode::ASTNode(const std::string& repr, ASTNode* lhs, ASTNode* rhs)
	: repr_(repr)
	, lhs_{ lhs }
	, rhs_{ rhs } {}

ASTNode::~ASTNode() {
	delete lhs_;
	delete rhs_;
}

void ASTNode::print(std::ostream& out) const {
	if (Parser::get_no_of_errors()) {
		std::cout << "Error Input!!!" << std::endl;
	}
	else {
		inner_print(out, 0);
	}
}

void ASTNode::inner_print(std::ostream& out, size_t indent) const {
	if (lhs_) {
		lhs_->inner_print(out, indent + 1);
	}
	for (size_t i = 0; i < indent; ++i) {
		out << "    ";
	}
	out << repr_ << '\n';
	if (rhs_) {
		rhs_->inner_print(out, indent + 1);
	}
}
