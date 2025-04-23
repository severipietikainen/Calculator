#pragma once
#include <string>
#include <stack>

void getInput(std::string& input); //User input

void parseInput(const std::string& userinput,std::stack<char>& operators, std::stack<std::string>& operands ,std::string& token); //parsing the user input into operators and operands

void handleExpressions(std::stack<char>& operators,std::stack<std::string>& operands);

void toPostFix(std::stack<char>& operators, std::stack<std::string>& operands, std::string& token);

bool isOperator();

int precedence(char prec);