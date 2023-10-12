#include "Parser.h"
#include <vector>
#pragma once

class ParserPolandAlg : public Parser
{
	void addFunctionIntoResult(std::string&& current_fun, std::stack<std::string>& stack, std::vector<std::string>& result);
public:
	double parse(std::string const& expression) override;
	std::vector<std::string> convertIntoPoland(std::string const& expression_);
	ParserPolandAlg() : Parser() {};
};

