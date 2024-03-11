#include <iostream>
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
