
#include "calculator.h"
#include <iostream>
#include <cmath>
#include <optional>
void TypeError(bool was_error_in_operand, std::string command) {
    if(was_error_in_operand){
        std::cerr << "Error: Numeric operand expected" << std::endl;
    } else {
        std::cerr << "Error: Unknown token " << command << std::endl;
    }
    
    
}
bool ReadNumber(Number& result){
    if(std::cin >> result){
        return true;
    } else {
        TypeError();
        return false;
    }
}

bool RunCalculatorCycle(){
    bool was_error = false;
    Number result;
    std::string command;
    Number operand;
    std::optional<Number> memory;
    if(!(ReadNumber(result))){
        return false;
    }
    while(std::cin >> command){
        if(command == "+"){
            if(!(ReadNumber(operand))){
                was_error = true;
                break;
            } else {
                result += operand;
            }
        } else if (command == "-"){
            if(!(ReadNumber(operand))){
                was_error = true;
                break;
            } else {
                result -= operand;
            }
        } else if (command == "*"){
            if(!(ReadNumber(operand))){
                was_error = true;
                break;
            } else {
                result *= operand;
            }
        } else if (command == "/"){
            if(!(ReadNumber(operand))){
                was_error = true;
                break;
            } else {
                result /= operand;
            }
        } else if (command == "**"){
                if(!(ReadNumber(operand))){
                was_error = true;
                break;
            } else {
                result = std::pow(result, operand);
            }
        } else if(command == ":"){
            if(!(ReadNumber(operand))){
                was_error = true;
                break;
            } else {
                result = operand;
            }
        } else if (command == "c"){
            result = 0;
        } else if (command == "q"){
            break;
        } else if (command == "="){
            std::cout << result << std::endl;
        } else if(command == "s"){
            memory = result;
        } else if(command == "l"){
            if(!memory.has_value()){
                was_error = true;
                std::cerr << "Error: Memory is empty" << std::endl;
            } else {
                result = memory.value();
            }
        }
        else {
            TypeError(was_error, command);
            was_error = true;
            break;
        }
    }

    if(was_error){
        return false;
    } else {
        return true;
    }

}