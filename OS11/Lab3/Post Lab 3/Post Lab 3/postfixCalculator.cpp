// Tianze Ren, tr2bx, 09/12/2022, postfixCalculator.cpp
#include "postfixCalculator.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

postfixCalculator:: postfixCalculator(){}

postfixCalculator:: ~postfixCalculator(){
}

int postfixCalculator:: cal(string input){
    int result = 0;
            if (input == "+"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value1 + value2;
                element.push(result);
            }
            else if (input == "-"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value2 - value1;
                element.push(result);
            }
            else if (input == "*"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value1 * value2;
                element.push(result);
            }
            else if (input == "/"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value2 / value1;
                element.push(result);
            }
            else if (input == "~"){
                int value1 = element.top();
                element.pop();
                value1 = -value1;
                result = value1;
                element.push(value1);
            }
            else{
                int p = stoi(input);
                element.push(p);
            }
    return result;
}
