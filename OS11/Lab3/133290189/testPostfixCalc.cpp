// Tianze Ren, tr2bx, 09/12/2022, testPostfixCalc.cpp
#include <iostream>
#include <string>
#include <vector>
#include "postfixCalculator.h"
using namespace std;

int main(){
    vector <string> tokens;
    string token;
    while (cin >> token){
        tokens.push_back(token);
    }
    postfixCalculator* c = new postfixCalculator();
    
    cout << c-> cal(tokens) << endl;
    
    delete c;
    return 0;
}

