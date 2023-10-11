#pragma once
#include <map>
#include "Operation_binary.h"
#include "Operation_unary.h"


class Operations
{
	std::map<std::string, Operation*> operations;

public:	
	Operations();
	Operations(std::string const& name_of_function);
	Operation* getValue(std::string const& name_of_function);
	bool isFunBinary(std::string const& name_of_fun);
	bool isFunUnary(std::string const& name_of_fun);
	bool isFunContains(std::string const& name_of_fun);
	priority_t getPriority(std::string const& name_of_function);
	void addBinaryFunction(Operation*, priority_t priority, std::string const& functionName) noexcept;
	void addUnaryFunction(Operation*, priority_t priority, std::string const& functionName) noexcept;
};

