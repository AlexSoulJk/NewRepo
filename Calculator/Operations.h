#include <iostream>
#include <string>
#include <map>
#include "Loader.h"
#pragma once
using namespace std;
class Operations
{
	map<string, Operation*> operations;
	Loader& loader;
public:	
	Operations();
	Operations(string const& name_of_function);
	Operation* getResoult(string const& name_of_function) {
		std::map<string, Operation*>::iterator it;
		it = operations.find(name_of_function);
		if (it != operations.end()) {
			return operations[name_of_function];
		}
		else {
			cerr << "Exeption!" << endl;
			exit(1);
		}
	};
};

