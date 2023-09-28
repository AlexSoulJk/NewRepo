#include "Calculator.h"
#include <stack>

void Calculator::start() {
	cin >> expression;
}


double add(double a, double b) {
    return a + b;
};
double multy(double a, double b) {
    return a * b;
}
double devide(double a, double b) {
    return b != 0.0 ? a / b : INFINITY;
}
double substract(double a, double b) {
    return a - b;
};
double factorial(int a) {
    int res = 1, n = a;
    while (n) {
        res *= n;
        n--;
    }
    return res;
};
double Sin(double a) {
    return sin(a);
};
double Cos(double b) {
    return cos(b);
};



double applyOperation(double a, double b, char operation) {
    switch (operation) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b != 0) {
            return a / b;
        }
        else {
            throw std::runtime_error("Деление на ноль!");
        }
    default:
        throw std::runtime_error("Неподдерживаемая операция!");
    }
}

/*This is a function that will match the entered processed operations with mathematical operations.*/
double Calculator::Evalue() {
    double res = 0.0;
    stack<double> values;
    stack<char> operations;

    for (char c : expression) {
        if (std::isdigit(c)) {
            double value = 0.0;
            bool isDecimal = false;
            double decimalMultiplier = 0.1;
            int i = 0;
            while (std::isdigit(c) || c == '.') {
                if (c == '.') {
                    isDecimal = true;
                }
                else {
                    if (!isDecimal) {
                        value = value * 10 + (c - '0');
                    }
                    else {
                        value += (c - '0') * decimalMultiplier;
                        decimalMultiplier /= 10;
                    }
                }

                c = expression[++i];
            }

            values.push(value);
        }
        else if (c == '(') {
            operations.push(c);
        }
        else if (c == ')') {
            while (!operations.empty() && operations.top() != '(') {
                double b = values.top();
                values.pop();

                double a = values.top();
                values.pop();

                char operation = operations.top();
                operations.pop();

                double result = applyOperation(a, b, operation);
                values.push(result);
            }

            if (!operations.empty() && operations.top() == '(') {
                operations.pop();
            }
            else {
                throw std::runtime_error("Некорректные скобки!");
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operations.empty() && operations.top() != '(' &&
                ((c == '+' || c == '-') ||
                    (c == '*' || c == '/') &&
                    (operations.top() == '*'
                        || operations.top() == '/'))) {

                double b = values.top();
                values.pop();

                double a = values.top();
                values.pop();

                char operation = operations.top();
                operations.pop();

                double result = applyOperation(a, b, operation);
                values.push(result);
            }

            operations.push(c);
        }
    }

    while (!operations.empty()) {
        double b = values.top();
        values.pop();

        double a = values.top();
        values.pop();

        char operation = operations.top();
        operations.pop();

        double result = applyOperation(a, b, operation);
        values.push(result);
    }

    return values.top();
    return res;
}

