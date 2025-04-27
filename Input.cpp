#include <iostream>
#include "logic.h"
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
void parseInput(const std::string& input, std::stack<char>& operators, std::stack<std::string>& operands, std::string& token)
{
	
	std::stringstream ss(input);
	std::vector<std::string> output;

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
		if (isOperator(token[0])) // looking for one character operators in tokens
		{
			if (token[0] == '(')
			{
				operators.push(token[0]);
			}

			if (token[0] == ')')
			{
				while (!operators.empty() && operators.top() != '(')
				{
					output.push_back(std::string(1, operators.top()));
					operators.pop();
				}
				operators.pop();
			}

			while (!operators.empty() && precedence(operators.top()) >= precedence(token[0]))
			{
				output.push_back(std::string(1, operators.top()));
				operators.pop();
			}
			operators.push(token[0]);
		}		
	}

	while (!operators.empty())
	{
		output.push_back(std::string(1, operators.top()));
		operators.pop();
	}
	

	for (const auto& elem : output)
	{
		std::cout << elem << " ";
	}


}



