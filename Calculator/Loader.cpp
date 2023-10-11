#include "Loader.h"
#include <Windows.h>
using prior = int(*)(void);
void Loader::loadFunction(std::string const& funName, Operations& operations) {
	HMODULE load;
	std::string path_ = (path + funName + ".dll");
	load = LoadLibraryA(path_.c_str());
	if (load) {
		prior priority = (prior)GetProcAddress(load, "priority");

		if (priority) {
			throw std::exception(("Problem with loading of priority in" + funName).c_str());
			return;
		}
		
		binary binaryFunction = (binary)GetProcAddress(load, "binary");

		if (!binaryFunction) {
			unary unaryFunction = (unary)GetProcAddress(load, "unary");

			if (!unaryFunction) { 
				Operation* tmp = new Operation_unary(unaryFunction);
				operations.addUnaryFunction(tmp, priority(), funName); 
			}

			throw std::exception(("Problem with loading" + funName).c_str());
			return;
		}
		Operation* tmp = new Operation_binary(binaryFunction);
		operations.addBinaryFunction(tmp, priority(), funName);
	}
}