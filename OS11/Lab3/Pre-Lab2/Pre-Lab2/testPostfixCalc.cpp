#include <iostream>
#include <string>
#include <vector>
#include "postfixCalculator.h"
using namespace std;

int main(){
    vector <string> tokens;
    string token;
    while (cin >> token){
        tokens = tokens + token;
    }
    
    cout << cal(tokens) << endl;
}

