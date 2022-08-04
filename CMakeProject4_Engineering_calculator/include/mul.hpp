#pragma once

#include "astnode.hpp"

class Mul : public ASTNode {
public:
	Mul(ASTNode* lhs, ASTNode* rhs)
		: ASTNode("*", lhs, rhs) {}
};