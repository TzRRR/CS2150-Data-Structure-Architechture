#include <iostream>
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
using namespace std;

class BankAccount {
public:
  bankAcocunt();
  bankAccount(double amount);
  ~bankAccount();
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();

 private:
  double balance;

}
#endif
