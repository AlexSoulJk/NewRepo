#include "Operations.h"

Operations::Operations() : loader(Loader::getInstance()) {
	operations["+"] = (new Operation(1, [](double a, double b) {return a + b; }));
	operations["-"] = (new Operation(1, [](double a, double b) {return a - b; }));
	operations["*"] = (new Operation(2, [](double a, double b) {return a * b; }));
	operations["/"] = (new Operation(2, [](double a, double b) {return b != 0 ? (a / b) : INFINITY; }));
};
