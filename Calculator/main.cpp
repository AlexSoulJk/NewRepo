#include<iostream>
#include "Calculator.h"
#include "ParserPolandAlg.h"

/* template of .dll

*/
/* Test string:

1/2 + sin(1/2)
1. 2 + 3  4
2. (5 - 2) / (3 + 1)
3. 4  (6 - 2)
4. 15 / (3 + 2)  4
5. sin(30) + cos(60)
6. cos(45) - tan(30)
7. tan(0) + log(1)
8. log(100) / log(10)
9. 8 + 2  (3 + 1)
10. (4 + 5) / (2 - 2)

*/

int main() {
	Parser* parser = new ParserPolandAlg();
	Calculator& app = Calculator::getInstance(parser);
	app.start();
}