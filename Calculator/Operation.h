#include <iostream>
#include <stack>
#pragma once

enum class FunType { unary, binary };
using priority_t = int;

class Operation
{
	priority_t priority;
public:
	Operation() = default;
	Operation(Operation const&) = default;
	Operation(Operation&&) = default;
	Operation& operator=(Operation const&) = default;
	Operation& operator=(Operation&&) = default;
	~Operation(void) = default;
	virtual double getValue(std::stack<double>&) const = 0;
};

