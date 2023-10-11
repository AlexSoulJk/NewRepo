#include "Operations.h"

Operations::Operations() {

	operations["+"] = (new Operation_binary([](double a, double b) {return a + b; }));
	operations["-"] = (new Operation_binary([](double a, double b) {return a - b; }));
	operations["*"] = (new Operation_binary([](double a, double b) {return a * b; }));
	operations["/"] = (new Operation_binary([](double a, double b) {return b != 0 ? (a / b) : INFINITY; }));
	operations["sin"] = (new Operation_unary([](double a) {return sin(a); }));

	operationstype["+"] = FunType::binary;
	operationstype["-"] = FunType::binary;
	operationstype["*"] = FunType::binary; 
	operationstype["/"] = FunType::binary;
	operationstype["sin"] = FunType::unary;

	priority["+"] = 2;
	priority["-"] = 2;
	priority["*"] = 3;
	priority["/"] = 3;
	priority["sin"] = 4;
	priority["("] = 1;

};

Operation* Operations::getValue(string const& name_of_function) {
	return isFunContains(name_of_function) ? operations[name_of_function] : nullptr;
};
bool Operations::isFunContains(string const& name_of_function) {
	std::map<string, Operation*>::iterator it;
	it = operations.find(name_of_function);

	if (it == operations.end()) {
		string const& msg = "The function is not found" + name_of_function;
		throw std::exception();
		return false;
	}
	return true;
}

priority_t Operations::getPriority(string const& name_of_function) {
	return priority[name_of_function];
}

bool Operations::isFunBinary(string const& name_of_function){
	if (isFunContains(name_of_function)) {
		return operationstype[name_of_function] == FunType::binary;
	}
	throw std::exception();
	return false;
}

bool Operations::isFunUnary(string const& name_of_function){
	if (isFunContains(name_of_function)) {
		return operationstype[name_of_function] == FunType::unary;
	}
	throw std::exception();
	return false;
}

void Operations::addUnaryFunction(Operation* function, priority_t priority_, string const& functionName) noexcept {
	operations[functionName] = function;
	operationstype[functionName] = FunType::unary;
	priority[functionName] = priority_;
}

void Operations::addBinaryFunction(Operation* function, priority_t priority_, string const& functionName) noexcept {
	operations[functionName] = function;
	operationstype[functionName] = FunType::binary;
	priority[functionName] = priority_;
}