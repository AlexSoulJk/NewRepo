#include <iostream>
#include <string>
#pragma once
using namespace std;

class Operation
{
public:
	Operation() = default;
	Operation(Operation const&) = default;
	Operation(Operation&&) = default;
	Operation& operator=(Operation const&) = default;
	Operation& operator=(Operation&&) = default;
	~Operation(void) = default;
	virtual double getValue(double a, double b) const {
		throw std::exception();
		return INFINITY;
	}
	virtual double getValue(double a) const {
		throw std::exception();
		return INFINITY;
	}
};

