#include "ParserPolandAlg.h"
#include <stack>
#include <sstream>
#include <vector>

std::string CatchNumber(std::string const& expression, int& index) {
	int counter_points = 0;
	std::string res = "";
	do {
		res += expression[index++];
		if (expression[index] == '.') counter_points++;
		if (counter_points > 1) {
			throw std::exception("Chislo nevalidno");
			return "";
		}
	} while ((isdigit(expression[index]) || expression[index] == '.'));
	return res;
}

std::string CatchFunction(std::string const& expression, int& index) {
	std::string res = "";
	do {
		res += expression[index++];
	} while (isalpha(expression[index]));

	if (expression[index] != '(') {
		throw std::exception("Function nonvalid");
		return "";
	}
	return res;
}
std::vector<std::string> ParserPolandAlg::convertIntoPoland(std::string const & expression_) {
    std::string expression = expression_;
	std::string res;
	std::string cur_number;
	std::string current_fun = "";
	std::string::size_type ind;
	std::vector<std::string> result;
	while ((ind = expression.find(' ')) != std::string::npos) expression.erase(ind, 1);

	for (int i = 0; i < expression.size(); ++i) { // (-num) to (0-num)
		if ((expression[i] == '+' || expression[i] == '-') && (0 == i || (!isdigit(expression[i - 1]) && expression[i - 1] != '.' && expression[i - 1] != ')'))) {
			auto it = std::find_if(expression.begin() + i + 1, expression.end(), [](char const c) {return !isdigit(c); });
			expression.insert(it, ')');
			expression.insert(i, "(0");
		}
	}
	int i = 0;
	char cur_symb;
	std::stack<std::string> stack;
	while (i < expression.size()) {
		cur_symb = expression[i];
		if (isdigit(cur_symb)){
			try {
				cur_number = CatchNumber(expression, i);
			}catch(std::exception&l) {
				throw std::exception(l.what());
				break;
			}
			result.push_back(cur_number);
		}
		else if (isalpha(cur_symb)) {

			try {
				current_fun = CatchFunction(expression, i);
			}
			catch (std::exception& l) {
				throw std::exception(l.what());
				break;
			}
			//thinking about downloading func
			try {
				list_of_operations.isFunContains(current_fun);
			}
			catch (std::exception& l) {
				throw std::exception(l.what());
				break;
			}
			

			while (!stack.empty()) {
				if (list_of_operations.getPriority(current_fun) <= list_of_operations.getPriority(stack.top())) {
					result.push_back(stack.top());
					stack.pop();
				}
				else {
					stack.push(std::move(current_fun));
					break;
				}
			}

			if (stack.empty()) {
				stack.push(std::move(current_fun));
			}

			
		}
		else if (cur_symb == '(') {
			stack.push({ cur_symb });
			i++;
		}
		else if(cur_symb == ')') {			
			while (!stack.empty() && stack.top() != "(") {
				result.push_back(stack.top());
				stack.pop();
			}

			if (stack.empty()) {
				throw std::exception("Not enough (");
				result.clear();
				return result;
			}
			stack.pop();
			i++;
		}		
		else if (list_of_operations.isFunContains({ cur_symb })){ // нашли оператор
			while (!stack.empty()) {
				if (list_of_operations.getPriority({ cur_symb }) <= list_of_operations.getPriority(stack.top())) {
					result.push_back(stack.top());
					stack.pop();
				}
				else {
					stack.push({ cur_symb });
					break;
				}
			}
			if (stack.empty()) {
				stack.push({ cur_symb });
			}
			i++;
		}			
	}
	while (!stack.empty()) {
		current_fun = stack.top();
		if ( current_fun == "(") {
			throw std::exception("Not enough )");
			result.clear();
			return result;
		}
		result.push_back(std::move(current_fun));
		stack.pop();
	}

	return result;
}


// если токен - оператор, выполняем соответствующую операцию над двумя верхними элементами стека
double ParserPolandAlg::parse(std::string const & expression_) {
    std::stack<double> arguments;
	std::vector<std::string> expression;
	try {
		expression = convertIntoPoland(expression_);
	}
	catch (std::exception& l) {
		throw std::exception(l.what());
		return 0;
	}
	
    double argument1 = 0, argument2 = 0;
    double result = 0;
	double number_of_iteration = 1;
	for (auto& token : expression) {
        if (isdigit(token[0])) arguments.push(std::stod(token));
        else {
			cout << "[" << number_of_iteration << "] ";
			argument1 = arguments.top();
			arguments.pop();
            if (list_of_operations.isFunBinary(token)) {
				argument2 = arguments.top();
				arguments.pop();
                result = list_of_operations.getValue(token)->getValue(argument2, argument1);
				arguments.push(result);
				cout << argument2 << " " << token << " " << argument1 << " = " << result << std::endl;
            }
            else if(list_of_operations.isFunUnary(token)) {
                result = list_of_operations.getValue(token)->getValue(argument1);
				arguments.push(result);
				cout << token << "(" << argument1 << ")" << " = " << result << std::endl;
            }
			number_of_iteration++;
        }
    }
	cout << "The result is " << arguments.top();
    return arguments.top();  // результат будет находиться на вершине стека
};