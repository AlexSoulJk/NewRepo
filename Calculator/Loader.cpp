#include "Loader.h"

using prior = int(*)(void);

void Loader::loadFunction(std::string const& funName, Operations& operations) {
	HMODULE load;

	std::string path_ = (path + funName + ".dll");
	load = LoadLibraryA(path_.c_str());
	if (load) {
		prior priority = (prior)GetProcAddress(load, "priority");

		if (!priority) {
			throw std::exception(("Problem with loading of priority in" + funName).c_str());
		}
		
		binary binaryFunction = (binary)GetProcAddress(load, "binary");

		if (!binaryFunction) {
			unary unaryFunction = (unary)GetProcAddress(load, "unary");

			if (unaryFunction) { 
				Operation* tmp = new Operation_unary(unaryFunction, priority());
				operations.addFunction(tmp,funName);
				return;
			}
			throw std::exception(("Problem with loading" + funName).c_str());
		}
		Operation* tmp = new Operation_binary(binaryFunction, priority());
		operations.addFunction(tmp,funName);
	}
	throw std::exception(("Problem with find Dlib" + funName + ".dll").c_str());
}