
#pragma once
using Number = double;
#include <string>

bool ReadNumber(Number& result);
void TypeError(bool was_error_in_operand = true, std::string command = "Error: Unknown token");
bool RunCalculatorCycle();