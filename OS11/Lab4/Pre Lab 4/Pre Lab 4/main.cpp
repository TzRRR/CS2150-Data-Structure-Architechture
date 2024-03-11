#include <iostream>
#include <string>
using namespace std;

void sizeOfTest(){
    cout
    << "Size of int: "<< sizeof(int)<< endl
    << "Size of unsigned int: "<< sizeof(unsigned int)<< endl
    << "Size of float: "<< sizeof(float)<< endl
    << "Size of double: "<< sizeof(double)<< endl
    << "Size of char: "<< sizeof(char)<< endl
    << "Size of bool: "<< sizeof(bool)<< endl
    << "Size of int*: "<< sizeof(int*)<< endl
    << "Size of char*: "<< sizeof(char*)<< endl
    << "Size of double*: "<< sizeof(double*)<< endl;
}

void overflow(){
    unsigned int max_number = 0xffffffff;
    int result = max_number + 1;
    cout<< "<" << max_number << "> + 1 = <" << result << ">" << endl;
}

void outputBinary(unsigned int x){
    string output = "";
    int itr1 = 0;
    int itr2 = 0;
    while (x != 0){
        if (itr1 == 4){
            output = " " + output + to_string(x % 2);
            itr1 = 0;
            itr2++;
            x = (x - (x % 2))/2;
        }
        else{
            output = output + to_string(x % 2);
            itr1++;
            itr2++;
            x = (x - (x % 2))/2;
        }
    }
    while (itr2 < 32){
        if (itr2 % 4 == 0){
            output = output + " " + "0";
            itr2++;
        }
        else{
            output = output + "0";
            itr2++;
        }
    }
    
    int front = 0;
    int back = output.length() - 1;
    while (front <= back){
        swap(output[front], output[back]);
        front++;
        back--;
    }
    
    cout<< output << endl;
}

int main(){
    int x;
    cin >> x;
    sizeOfTest();
    overflow();
    outputBinary(x);
    return 0;
}


