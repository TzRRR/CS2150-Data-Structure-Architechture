// Tianze Ren, tr2bx, 10/31/2022, mathfun.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int main(){
  long a;
  long b;
  cout << "Enter integer 1: ";
  cin >> a;
  cout << "Enter integer 2: ";
  cin >> b;
  long product_ = product(a,b);
  long power_ = power(a,b);
  cout << "Product: " << product_ << endl;
  cout << "Power: " << power_ << endl;

}
