#include <iostream>
#include "logic.h"
#include <string>
#include <sstream>
#include <stack>
#include <ctype.h>
#include <cmath>



void handleExpressions(std::stack<char>& operators, std::stack<std::string>& operands)
{




















	while (!operands.empty()) {
		std::cout << "Top: " << operands.top() << std::endl;
		operands.pop();
	}

	while (!operators.empty()) {
		std::cout << "Top: " << operators.top() << std::endl;
		operators.pop();
	}
}