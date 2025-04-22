#include <iostream>
#include "logic.h"
#include <string>
#include <sstream>


//Getting the user input
std::string getInput()
{
	std::string input;

	std::getline(std::cin, input);

	return input;
	
}

//parsing the input
void parseInput(const std::string& userinput)
{
	std::string token;

	std::stringstream ss(userinput);

	while (std::getline(ss, token, ' '))
	{
		std::cout << "token:" << token << std::endl;
	}
}