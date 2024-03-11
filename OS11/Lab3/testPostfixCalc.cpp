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
    postfixCalculator c = new postfixCalculator();
    
    cout << c.cal(tokens) << endl;
    
    return 0;
}

