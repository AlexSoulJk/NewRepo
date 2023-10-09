#include "Operation.h"

#pragma once
using binary = double(*)(double, double);
class Operation_binary : public Operation
{
private:
	binary operation;
public:
	Operation_binary() = default;
	Operation_binary(Operation_binary const&) = default;
	Operation_binary(Operation_binary&&) = default;
	Operation_binary& operator=(Operation_binary const&) = default;
	Operation_binary& operator=(Operation_binary&&) = default;
	~Operation_binary(void) = default;
	Operation_binary(binary operation_) : operation(operation_) {};
	double getValue(double a, double b) const { return operation(a, b); };


};

