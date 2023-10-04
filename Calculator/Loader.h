#include "Operation.h"
class Loader {
	Loader() = default;
	Loader(Loader const &) = delete;
	Loader& operator=(Loader const&) = delete;
	Loader& operator=(Loader&&) = delete;
	Loader(Loader&&) = delete;

public:
	static Loader& getInstance() {
		static Loader instance;
		return instance;
	}
	std::function<double(double, double)> load(string const&);

};