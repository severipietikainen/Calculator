#include <iostream>
#include <string>
#include "logic.h"

int main() {

	std::cout << "Hello this is a calculator" << std::endl;

	std::cout << "Enter the calculation" << std::endl;

	std::string input = getInput();
	parseInput(input);
	
}


