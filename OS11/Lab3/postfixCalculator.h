// Tianze Ren, tr2bx, 09/12/2022, postfixCalculator.h
#include <iostream>
#include <stack>
#include <vector>
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
using namespace std;

class postfixCalculator{
public:
    postfixCalculator();
    ~postfixCalculator();
    int cal (vector <string> input);
    stack<int> element;
    
};

#endif
