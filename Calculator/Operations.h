#include <iostream>
#include <string>
#include <map>
#include "Operation_binary.h"
#include "Operation_unary.h"
#pragma once
using namespace std;
enum class FunType {unary, binary};
using priority_t = int;
class Operations
{

	map<string, Operation*> operations;
	map<string, FunType> operationstype;
	map<string, priority_t> priority;
public:	
	Operations();
	Operations(string const& name_of_function);
	Operation* getValue(string const& name_of_function);
	bool isFunBinary(string const& name_of_fun);
	bool isFunUnary(string const& name_of_fun);
	bool isFunContains(string const& name_of_fun);
	priority_t getPriority(string const& name_of_function);
	void addBinaryFunction(Operation*, priority_t priority, string const& functionName) noexcept;
	void addUnaryFunction(Operation*, priority_t priority, string const& functionName) noexcept;
};

