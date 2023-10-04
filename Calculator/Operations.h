#include <iostream>
#include <string>
#include <map>
#include "Loader.h"
#pragma once
using namespace std;
class Operations
{
	map<string, Operation&> operations;
	Loader& loader;
public:	
	Operations();
	Operations(string const& name_of_function);
};

