#include<iostream>
#include "Calculator.h"
#include "ParserPolandAlg.h"
using namespace std;

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
int main() {
	Parser* p = new ParserPolandAlg();
	std::string expression = "-4.7 2.7 3 sin *";
	cout << p->parse(expression);
}