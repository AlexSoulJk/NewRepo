#include "ParserPolandAlg.h"
#include <stack>
#include <sstream>

std::string convertIntoPoland(std::string const & expression_) {
    std::string expression = expression_;
    return expression;
}


// ���� ����� - ��������, ��������� ��������������� �������� ��� ����� �������� ���������� �����
double ParserPolandAlg::parse(std::string const & expression_) {
    std::stack<double> stack;
    std::string expression = convertIntoPoland(expression_);
    std::istringstream iss(expression);

    std::string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {  // ���� ����� - �����, ����������� ��� � ����� � ��������� � ����
            stack.push(std::stod(token));
        }
        else {
            
            double y = stack.top();
            stack.pop();
            double x = stack.top();
            stack.pop();
            double result;
            result = list_of_operations.getResoult(token)->getValue(x,y);
            stack.push(result);
        }
    }

    return stack.top();  // ��������� ����� ���������� �� ������� �����
};