#include <iostream>
#include <string>
#include <stack>
#include "logic.h"

int main() {

	//Creating the main data structures that will be referenced
	std::string input;
	std::string token;
	std::stack<std::string> operands;
	std::stack<char> operators;
	
	
    std::cout << "Hello this is a calculator" << std::endl;

	std::cout << "Enter the calculation" << std::endl;



	getInput(input);

	parseInput(input,operators,operands,token);

	//toPostFix(operators, operands, token);

	

	
}


