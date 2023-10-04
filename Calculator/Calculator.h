#include<iostream>
#include <string>
#include "Operations.h"
#pragma once
using namespace std;
/* 
This is a calculator class that is a singleton
*/
class Calculator
{
	string expression;
	Calculator() = default;
	Calculator(const Calculator&);
	Calculator& operator=(Calculator&);
	Operations list_of_operations;
public:
	static Calculator& getInstance() {
		static Calculator instance;
		return instance;
	}
	void start(void);
	double Evalue();
};

