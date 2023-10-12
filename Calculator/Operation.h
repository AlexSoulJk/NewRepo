#include <iostream>
#include <stack>
#pragma once

//enum class FunType { unary, binary };
using priority_t = int;

class Operation
{
protected:
	priority_t priority;
public:
	virtual void getValue(std::stack<double>&, std::string const& token) const = 0;
	priority_t getPriority(void) const noexcept { return priority; };
	Operation(priority_t priority_) : priority(priority_) {};
};

