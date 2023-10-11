#include <iostream>
#include <string>
#include "Operations.h"
#include "Loader.h"
#pragma once
class Parser
{
	
protected:
	Operations& list_of_operations;
	Loader& loader;

public:
	virtual double parse(std::string const& expression) { return INFINITY; };
};

