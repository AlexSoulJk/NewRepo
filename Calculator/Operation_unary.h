#include "Operation.h"
#pragma once
using unary = double(*)(double);

class Operation_unary : public Operation
{
private:
	unary operation;
public:
	Operation_unary() = default;
	Operation_unary(Operation_unary const&) = default;
	Operation_unary(Operation_unary&&) = default;
	Operation_unary& operator=(Operation_unary const&) = default;
	Operation_unary& operator=(Operation_unary&&) = default;
	~Operation_unary(void) = default;
	Operation_unary(unary operation_) : operation(operation_) {};
	double getValue(double a) const { return operation(a); };

};

