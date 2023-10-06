#include "Parser.h"
#pragma once

class ParserPolandAlg : public Parser
{
public:
	double parse(std::string const& expression) override;
};

