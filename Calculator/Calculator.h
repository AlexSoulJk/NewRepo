#include<iostream>
#include "Parser.h"
#include "Loader.h"
#pragma once
/* 
This is a calculator class that is a singleton
*/
class Calculator
{
	std::string expression;
	Parser* parser;
	Loader const& loader;
	Calculator() = default;
	Calculator(Parser* parser_): parser(parser_), loader(Loader::getInstance()) {};
	Calculator(const Calculator&) = default;
	Calculator& operator=(Calculator&) = default;
	
	
public:
	static Calculator& getInstance(Parser* parser_){
		try {
			if (!parser_) throw std::exception("Parser invalid");
		}
		catch (std::exception& l) {
			std::cout << l.what() << std::endl;
			//guess I can write exit(1) here!..
		}
		
		static Calculator instance = Calculator(parser_);
		return instance;
	}
	void start(void) noexcept;
	void Evalue(void);
};

