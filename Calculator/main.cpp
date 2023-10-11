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
Parser* parser = new ParserPolandAlg();
	bool is_finish = false;
	Calculator& app = Calculator::getInstance(parser);
	while (!is_finish) {
		app.start();
		app.Evalue();
		is_finish = IsFinish();
	}
*/

/*
HINSTANCE load;
	load = LoadLibrary(L"./config\\DLibtg.dll");
	FP tg = (FP)GetProcAddress(load, "uno");
	cout << tg(2);
	FreeLibrary(load);
*/
/*
	std::string expression = "log(0) + sin(1/2)";
	ParserPolandAlg pars = ParserPolandAlg();
	try {
		pars.parse(expression);
	}
	catch (std::exception& l) {
		cout << l.what();
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
	Parser* parser = new ParserPolandAlg();
	bool is_finish = false;
	Calculator& app = Calculator::getInstance(parser);
	while (!is_finish) {
		app.start();
		app.Evalue();
		//is_finish = IsFinish();
	}
}