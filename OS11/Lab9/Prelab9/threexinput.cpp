// Tianze Ren, tr2bx, 12/05/2022, threexinput.cpp
#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int num);

int main (){
    int integer = 0;
    int result = 0;
    cout << "Enter a number: ";
    cin >> integer;
    result = threexplusone(integer);
    
//    timer t;
//    t.start();
    int iteration = 0;
    cout << "Enter iterations of subroutine: ";
    cin >> iteration;
    for (int i = 0; i < iteration; i++){
        threexplusone(integer);
    }
//    t.stop();
//    float time = t.getTime();
//    time = time / iteration;
    
//    cout << time << endl;
    cout << "Steps: ";
    cout << result << endl;

    return 0;
}
