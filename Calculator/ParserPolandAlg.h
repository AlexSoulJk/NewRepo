#include "Parser.h"
#include <vector>
#pragma once

class ParserPolandAlg : public Parser
{
	
public:
	double parse(std::string const& expression) override;
	std::vector<std::string> convertIntoPoland(std::string const& expression_);
	ParserPolandAlg() : Parser() {};
};

