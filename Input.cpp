#include <iostream>
#include "Logic.h"
#include <string>
#include <sstream>
#include <stack>
#include <ctype.h>
#include <cmath>
#include <vector>


//Getting the user input
void getInput(std::string& input)
{

	std::getline(std::cin, input);

}

// operator check
bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char prec)
{
	if (prec == '+' || prec == '-')
	{
		return 1;
	}
	if (prec == '*' || prec == '/')
	{
		return 2;
	}
	if (prec == '^')
	{
		return 3;
	}
	return 0;
}


//Parsing the input
void parseInput(const std::string& input, std::vector<std::string>& output)
{
	
	std::stringstream ss(input);
	std::string token;
	std::stack<char> operators;

	while (std::getline(ss, token, ' ')) //reading the user input and creating tokens
	{
		if (token.empty()) // skip empty tokens
		{
			continue;
		}
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
				output.push_back(token); // pushing it to the output stack
			}
		}
		if (isOperator(token[0]) || token[0] == '(' || token[0] == ')') // looking for one character operators in tokens
		{
			if (token[0] == ')') // parentheses handling
			{
				while (!operators.empty() && operators.top() != '(')
				{
					output.push_back(std::string(1, operators.top()));
					operators.pop();
				}
				operators.pop();
			}
			while (!operators.empty() && precedence(operators.top()) >= precedence(token[0]) && token[0] != ')' && token[0] != '(') // implementing the Shunting Yard algorithm for correct postfix
				{
					output.push_back(std::string(1, operators.top()));
					operators.pop();
				}
			if (isOperator(token[0]) || token[0] == '(')
			{
				operators.push(token[0]);

			}	
		}		
	}

	while (!operators.empty()) // final flush of remaining operators
	{
		output.push_back(std::string(1, operators.top()));
		operators.pop();
	}
	

	for (const auto& elem : output)
	{
		std::cout << elem << " " << std::endl;
	}


}



