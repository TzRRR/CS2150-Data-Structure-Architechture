//Tianze Ren, tr2bx, 09/21/2022, bitCount.cpp
#include <iostream>
#include <string>
using namespace std;


int bitCounter(int num){
    if (num == 0){
        return 0;
    }
    else{
        if (num % 2 == 0){
            return 1 + bitCounter(num/2);
        }
        else{
            return 1 + bitCounter(num/2);
        }
    }
}

string baseConverter(string num, int before, int after){
    bool isNegative = num[0] == '-';
    int position = 1;
    int b10 = 0;
    string baseAfter = "";
    int endi = isNegative ? 1 : 0; // learned from github
    for (int i = num.length() - 1; i >= endi; i-- ){
        char c = num[i];
        if (c >= '0' && c<= '9'){
            c = c - '0';
        }
        else{
            c = c - 55;
        }
        b10 = b10 + c * position;
        position  = position * before;
    }
    
    while (b10 != 0){
        baseAfter = baseAfter + to_string(b10 % after);
        b10 = (b10 - (b10 % after))/after;
    }
    
    int front = 0;
    int back = baseAfter.length() - 1;
    while (front <= back){
        swap(baseAfter[front], baseAfter[back]);
        front++;
        back--;
    }
    
    if (isNegative){
        baseAfter.insert(0, "-");
    }
    
    return baseAfter;
}

int main(int argc, char * argv[]) {
    int bitC = 0;
    string conversion;
    if (argv[1] == NULL){
        cout << "Invalid Input" << endl;
        exit(0);
    }
    else{
        bitC = bitCounter(stoi(argv[1]));
    }
    
    int b = stoi(argv[3]);
    int a = stoi(argv[4]);
    conversion = baseConverter(argv[2], b, a);
    
    cout
    << argv[1] << " has " << bitC << " bit(s)" << endl
    << argv[2] << " (base " << b << ") = " << conversion << " (base" << a << ")";
    return 0;
}
