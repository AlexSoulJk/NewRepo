#include "Operations.h"
#include "Loader.h"
#include <string>
#pragma once
class Parser
{
protected:
	Operations list_of_operations;
	Loader& loader;
public:
	virtual double parse(std::string const& expression) = 0;
	Parser() : list_of_operations(), loader(Loader::getInstance()){};
};

