#include<iostream>
#include <string>
#include "Parser.h"
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
	
public:
	static Calculator& getInstance() {
		static Calculator instance;
		return instance;
	}
	void start(void);
	double Evalue();
};

