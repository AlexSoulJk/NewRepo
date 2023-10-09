#include <iostream>
#include <string>
#include <map>
#include "Loader.h"
#include "Operation_binary.h"
#pragma once
using namespace std;
enum class FunType {unary, binary};
using priority_t = int;
class Operations
{

	map<string, Operation*> operations;
	map<string, FunType> operationstype;
	map<string, priority_t> priority;

	Loader& loader;

	bool isFunContains(string const& name_of_fun);
public:	
	Operations();
	Operations(string const& name_of_function);
	Operation* getValue(string const& name_of_function);
	bool isFunBinary(string const& name_of_fun);
	bool isFunUnary(string const& name_of_fun);
};

