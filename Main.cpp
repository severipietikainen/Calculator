#include <iostream>
#include <string>
#include <stack>
#include "Logic.h"
#include <vector>

int main() {

	//Creating the main data structures that will be referenced
	std::string input;
	std::vector<std::string> output;
	
	
    std::cout << "Hello this is a calculator" << std::endl;

	std::cout << "Enter the calculation" << std::endl;



	getInput(input);

	parseInput(input,output);

}


