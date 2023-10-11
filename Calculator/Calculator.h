#include<iostream>
#include <string>
#include "Parser.h"
#include "Loader.h"
#pragma once
using namespace std;
/* 
This is a calculator class that is a singleton
*/
class Calculator
{
	string expression;
	Parser* parser;
	Loader& loader;
	Calculator() = default;
	Calculator(Parser* parser_): parser(parser_), loader(Loader::getInstance()) {};
	Calculator(const Calculator&) = default;
	Calculator& operator=(Calculator&) = default;
	
	
public:
	static Calculator& getInstance(Parser* parser_) {
		static Calculator instance = Calculator(parser_);
		return instance;
	}
	void start(void) noexcept;
	void Evalue(void);
};

