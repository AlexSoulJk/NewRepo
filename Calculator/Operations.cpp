#include "Operations.h"

Operations::Operations() {

	operations["+"] = (new Operation_binary([](double a, double b) {return a + b; },2));
	operations["-"] = (new Operation_binary([](double a, double b) {return a - b; }, 2));
	operations["*"] = (new Operation_binary([](double a, double b) {return a * b; }, 3));
	operations["/"] = (new Operation_binary([](double a, double b) {if (b != 0) return a / b; throw std::exception("Division by zero!");}, 3));
};

Operation* Operations::getValue(std::string const& name_of_function) noexcept{
	return operations[name_of_function];
};
bool Operations::isFunContains(std::string const& name_of_function) noexcept{
	std::map<std::string, Operation*>::iterator it;
	it = operations.find(name_of_function);
	return it != operations.end();
}

priority_t Operations::getPriority(std::string const& name_of_function) noexcept{
	return name_of_function != "(" ? operations[name_of_function]->getPriority() : 1;
}

void Operations::addFunction(Operation* function, std::string const& functionName) noexcept {
	operations[functionName] = function;
}
