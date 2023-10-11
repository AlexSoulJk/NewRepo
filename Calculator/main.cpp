#include<iostream>
#include "Calculator.h"
#include "ParserPolandAlg.h"

using namespace std;


/* template of .dll

*/

/*This is a function that will check stop calculation*/
bool IsFinish(void) {
	cout << "Input S to stop calculation\n";
	char c;
	cin >> c;
	return c == 'S';
}
/*
bool is_finish = false;
	Calculator& app = Calculator::getInstance();
	while (!is_finish) {
		app.start();
		cout << "=" << app.Evalue() << endl;
		is_finish = IsFinish();
	}
	cout << "Hello wrld!";
*/

/*
HINSTANCE load;
	load = LoadLibrary(L"./config\\DLibtg.dll");
	FP tg = (FP)GetProcAddress(load, "uno");
	cout << tg(2);
	FreeLibrary(load);
*/
/*
try {
		res = pars.convertIntoPoland(expression);
	}
	catch (std::exception& l) {
		cout << l.what();
		exit(1);
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " " << endl;
	}
*/

/*
std::string expression = "sin(1/2))";
	ParserPolandAlg pars = ParserPolandAlg();
	try {
		pars.parse(expression);
	}
	catch (std::exception& l) {
		cout << l.what();
	}
*/
/* Test string:
"1/2 + sin(1/2)"

* 
*/

int main() {

	bool is_finish = false;
	Calculator& app = Calculator::getInstance();
	while (!is_finish) {
		app.start();
		cout << app.Evalue() << endl;
		is_finish = IsFinish();
	}
	
}