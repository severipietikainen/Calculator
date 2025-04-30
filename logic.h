#pragma once
#include <string>
#include <stack>
#include <vector>

void getInput(std::string& input); //User input

void parseInput(const std::string& input, std::vector<std::string>& output); //parsing the user input into operators and operands

void handleExpressions(std::vector<std::string>& output);

static bool isOperator();

int precedence(char prec);