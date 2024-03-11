// Tianze Ren, tr2bx, 09/12/2022, postfixCalculator.cpp
#include "postfixCalculator.h"
#include <stack>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

postfixCalculator:: postfixCalculator(){}

postfixCalculator:: ~postfixCalculator(){}

int postfixCalculator:: cal(vector <string> input){
    int result;
    for (int i = 0; i < input.size(); i++){
            if (input[i] == "+"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value1 + value2;
                element.push(result);
            }
            else if (input[i] == "-"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value2 - value1;
                element.push(result);
            }
            else if (input[i] == "*"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value1 * value2;
                element.push(result);
            }
            else if (input[i] == "/"){
                int value1 = element.top();
                element.pop();
                int value2 = element.top();
                element.pop();
                result = value2 / value1;
                element.push(result);
            }
            else if (input[i] == "~"){
                int value1 = element.top();
                element.pop();
                value1 = -value1;
                element.push(value1);
            }
            else{
                int p = stoi(input[i]);
                element.push(p);
            }
        }
    return result;
}