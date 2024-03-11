// Tianze Ren, tr2bx, 09/12/2022, testPostfixCalc.cpp
#include <iostream>
#include <string>
#include "postfixCalculator.h"
using namespace std;

int main(){
    string token;
    postfixCalculator* c = new postfixCalculator();
    while (cin >> token){
        c-> cal(token);
    }
    cout << c-> element.top() << endl;
    
    delete c;
    return 0;
}

