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
	Operation_binary(binary operation_, priority_t priority_) : Operation(priority_, FunType::binary), operation(operation_) {};
	void getValue(std::stack<double>& values, std::string const & token ) const override {
		if (values.empty()) throw std::exception("Not enough input arguments");
		double argument1 = values.top();
		values.pop();
		if (values.empty()) throw std::exception("Not enough input arguments");
		double argument2 = values.top();
		values.pop();
		double result = operation(argument2, argument1);
		std::cout << argument2 << " " << token << " " << argument1 << " = " << result << std::endl;
		values.push(result);
	};
};

