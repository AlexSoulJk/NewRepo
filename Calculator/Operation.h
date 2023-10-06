#include <iostream>
#include <string>
#include <functional>
#pragma once
using namespace std;

class Operation
{
	unsigned short priority;
	std::function<double(double, double)> operation;
	
public:
	Operation() = default;
	Operation(unsigned short priority_, std::function<double(double, double)> operation_) : priority(priority_), operation(operation_) {};
	Operation(Operation const&) = default;
	Operation(Operation&&) = default;
	Operation& operator=(Operation const&) = default;
	Operation& operator=(Operation&&) = default;
	~Operation(void) = default;
	double getValue(double a, double b) {
		return operation(a, b);
	};
	bool isBinary() { return true; };
};

