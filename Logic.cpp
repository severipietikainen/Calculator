#include <iostream>
#include "Logic.h"
#include <string>
#include <sstream>
#include <stack>
#include <ctype.h>
#include <cmath>
#include <vector>



void handleExpressions(std::vector<std::string>& output)
{

	std::stack<double> operands;
	double operand;
	double a;
	double b;
	
	for (const std::string& token : output)
	{

		if (isdigit(token[0])) // inspects the first character of the token as number
		{
			bool isValid = true;

			for (int i = 0; i < token.size(); i++) // looping through the rest of the characters in a token
			{
				if (!isdigit(token[i]))
				{
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				operand = std::stod(token);
				operands.push(operand); // pushing it to the operands stack
			}
		}

		if (isOperator(token[0])) // perform calculations and push to the operands stack
		{
			double b = operands.top();
			operands.pop();
			double a = operands.top();
			operands.pop();
			double result;

			if (token[0] == '+')
			{
				result = a + b;
				operands.push(result);
			}
			else if (token[0] == '-')
			{
				result = a - b;
				operands.push(result);
			}
			else if (token[0] == '*')
			{
				result = a * b;
				operands.push(result);
			}
			else if (token[0] == '/')
			{
				result = a / b;
				operands.push(result);
			}
			else if (token[0] == '^')
			{
				result = pow(a, b);
				operands.push(result);
			}
		}

	}

	std::cout << "Result: " << operands.top() << std::endl;

}