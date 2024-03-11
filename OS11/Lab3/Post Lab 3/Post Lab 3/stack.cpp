// Tianze Ren, tr2bx, 09/16/2022, stack.cpp
#include <iostream>
#include "stack.h"

using namespace std;

stack::stack(){
}

stack::~stack(){
}

void stack::push (int e){
    l.insertAtTail(e);
}

void stack::pop(){
    l.remove(l.last().current-> value);
    l.last();
}

int stack::top(){
    return l.last().current -> value;
}

bool stack::empty(){
    return l.isEmpty();
}
