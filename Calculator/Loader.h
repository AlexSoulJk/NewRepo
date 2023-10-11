#pragma once
#include "Operations.h"
#include <Windows.h>
class Loader {
	Loader() = default;
	Loader(Loader const &) = delete;
	Loader& operator=(Loader const&) = delete;
	Loader& operator=(Loader&&) = delete;
	Loader(Loader&&) = delete;
	std::string const path = "./config\\DLib";
public:
	static Loader& getInstance() {
		static Loader instance;
		return instance;
	}
	void loadFunction(std::string const& dllname, Operations& operations);
};