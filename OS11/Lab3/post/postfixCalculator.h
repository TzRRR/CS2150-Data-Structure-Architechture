// Tianze Ren, tr2bx, 09/12/2022, postfixCalculator.h
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include "stack.h"
#include <vector>

#include <string>
using namespace std;

class postfixCalculator{
public:
    postfixCalculator();
    ~postfixCalculator();
    int cal (vector <string> input);
    stack element;

  friend class stack;
};

#endif
