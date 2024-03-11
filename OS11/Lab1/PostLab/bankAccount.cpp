// Tianze Ren, tr2bx, 08/31/2022, bankAccount.cpp
#include "bankAccount.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

bankAccount::bankAccount(){
  balance = 0;
}

bankAccount::bankAccount(double amount){
  balance = amount;
}

bankAccount:: ~bankAccount(){};

double bankAccount:: withdraw(double amount){
    if (amount <= balance){
        balance = balance - amount;
        return balance;
    }
    else{
        return balance;
    }
}

double bankAccount:: deposit(double amount){
    balance = balance + amount;
    return balance + amount;
}

double bankAccount:: getBalance (){
    return balance;
}

  
