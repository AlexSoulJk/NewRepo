#include<iostream>
#include "Calculator.h"
using namespace std;

/*This is a function that will check stop calculation*/
bool IsFinish(void) {
	cout << "Input S to stop calculation\n";
	char c;
	cin >> c;
	return c == 'S';
}
int main() {
	bool is_finish = false;
	Calculator& app = Calculator::getInstance();
	while (!is_finish) {
		app.start();
		cout << "=" << app.Evalue() << endl;
		is_finish = IsFinish();
	}
	cout << "Hello wrld!";
}