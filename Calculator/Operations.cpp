#include "Operations.h"

Operations::Operations() {

	operations["+"] = (new Operation_binary([](double a, double b) {return a + b; }));
	operations["-"] = (new Operation_binary([](double a, double b) {return a - b; }));
	operations["*"] = (new Operation_binary([](double a, double b) {return a * b; }));
	operations["/"] = (new Operation_binary([](double a, double b) {return b != 0 ? (a / b) : INFINITY; }));

	priority["+"] = 2;
	priority["-"] = 2;
	priority["*"] = 3;
	priority["/"] = 3;
	priority["("] = 1;

};

Operation* Operations::getValue(std::string const& name_of_function) {
	return isFunContains(name_of_function) ? operations[name_of_function] : nullptr;
};
bool Operations::isFunContains(std::string const& name_of_function) {
	std::map<std::string, Operation*>::iterator it;
	it = operations.find(name_of_function);
	return it != operations.end();
}

priority_t Operations::getPriority(std::string const& name_of_function) {
	return priority[name_of_function];
}

bool Operations::isFunBinary(std::string const& name_of_function){
	if (isFunContains(name_of_function)) {
		return operationstype[name_of_function] == FunType::binary;
	}
	throw std::exception();
	return false;
}

bool Operations::isFunUnary(std::string const& name_of_function){
	if (isFunContains(name_of_function)) {
		return operationstype[name_of_function] == FunType::unary;
	}
	throw std::exception();
	return false;
}

void Operations::addUnaryFunction(Operation* function, priority_t priority_, std::string const& functionName) noexcept {
	operations[functionName] = function;
	operationstype[functionName] = FunType::unary;
	priority[functionName] = priority_;
}

void Operations::addBinaryFunction(Operation* function, priority_t priority_, std::string const& functionName) noexcept {
	operations[functionName] = function;
	operationstype[functionName] = FunType::binary;
	priority[functionName] = priority_;
}