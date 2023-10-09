#include "Operations.h"

Operations::Operations() : loader(Loader::getInstance()) {

	operations["+"] = (new Operation_binary([](double a, double b) {return a + b; }));
	operations["-"] = (new Operation_binary([](double a, double b) {return a - b; }));
	operations["*"] = (new Operation_binary([](double a, double b) {return a * b; }));
	operations["/"] = (new Operation_binary([](double a, double b) {return b != 0 ? (a / b) : INFINITY; }));

	operationstype["+"] = FunType::binary;
	operationstype["-"] = FunType::binary;
	operationstype["*"] = FunType::binary; 
	operationstype["/"] = FunType::binary;

	priority["+"] = 2;
	priority["-"] = 2;
	priority["*"] = 3;
	priority["/"] = 3;
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
}

bool Operations::isFunBinary(string const& name_of_function){
	if (isFunContains(name_of_function)) {
		return operationstype[name_of_function] == FunType::binary;
	}
	throw std::exception();
	return false;
}

bool Operations::isFunBinary(string const& name_of_function){
	if (isFunContains(name_of_function)) {
		return operationstype[name_of_function] == FunType::unary;
	}
	throw std::exception();
	return false;
}