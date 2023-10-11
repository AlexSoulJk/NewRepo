#include "Calculator.h"

void Calculator::start() noexcept{
	std::getline(std::cin,expression);
}

void Calculator::Evalue(){
	double res;
	try {
		res = parser->parse(expression);
	}
	catch (std::exception& l) {
		std::cout << l.what() << std::endl;
		return;
	}
	//cout << res;
}
