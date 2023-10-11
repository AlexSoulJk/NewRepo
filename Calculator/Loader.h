#pragma once
#include "Operations.h"

class Loader {
	Loader() = default;
	Loader(Loader const &) = delete;
	Loader& operator=(Loader const&) = delete;
	Loader& operator=(Loader&&) = delete;
	Loader(Loader&&) = delete;
	string const path = "./config\\DLib";
public:
	static Loader& getInstance() {
		static Loader instance;
		return instance;
	}
	void loadFunction(string const& dllname, Operations& operations);
};