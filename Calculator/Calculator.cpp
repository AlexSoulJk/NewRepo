#include "Calculator.h"

bool IsFinish(void) {
	std::cout << "Input S to stop calculation or anything else to continue\n";
	std::string expression;
	std::getline(std::cin, expression);
	return expression == "S";
}


void Calculator::start() noexcept{
	bool is_finish = false;
	while (!is_finish) {
		std::cout << "Input your expression" << std::endl;
		std::getline(std::cin, expression);
		Evalue();
		is_finish = IsFinish();
	}
	
}

void Calculator::Evalue(){
	double res;
	try {
		res = parser->parse(expression);
	}
	catch (const std::exception& l) {
		std::cout << l.what() << std::endl;
		return;
	}
}
