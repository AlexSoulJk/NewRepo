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
	Operation_unary(unary operation_, priority_t priority_) : Operation(priority_), operation(operation_){};
	void getValue(std::stack<double>& values, std::string const& token) const override {
		if (values.empty()) throw std::exception("Not enough input arguments");
		double argument1 = values.top();
		values.pop();
		double result = operation(argument1);
		std::cout << token << "(" << argument1 << ")" << " = " << result << std::endl;
		values.push(result);
	};

};

