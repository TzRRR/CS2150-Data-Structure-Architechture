// Tianze Ren, tr2bx, 09/16/2022, stack.h
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;


class stack{
public:
    stack();
    ~stack();
    void push (int e);
    void pop();
    int top();
    bool empty();

private:
    List l;
    
    friend class postfixCalculator;
};
#endif
