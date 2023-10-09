#include<iostream>
#include "Calculator.h"
#include "ParserPolandAlg.h"
#include <Windows.h>
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
typedef double (*FP) (double);
int main() {
	HINSTANCE load;
	load = LoadLibrary(L"./config\\DLibtg.dll");
	FP tg = (FP)GetProcAddress(load, "uno");
	cout << tg(2);
	FreeLibrary(load);
}