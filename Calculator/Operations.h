#pragma once
#include <map>
#include "Operation_binary.h"
#include "Operation_unary.h"


class Operations
{
	std::map<std::string, Operation*> operations;
public:	
	Operations();
	Operations(Operations const&) = default;
	Operations(Operations&&) = default;
	Operations& operator=(Operations&&) = default;
	Operations& operator=(Operations const&) = default;
	~Operations() = default;
	Operation* getValue(std::string const& name_of_function) noexcept;
	bool isFunContains(std::string const& name_of_fun) noexcept;
	priority_t getPriority(std::string const& name_of_function) noexcept;
	void addFunction(Operation*, std::string const& functionName) noexcept;
};

