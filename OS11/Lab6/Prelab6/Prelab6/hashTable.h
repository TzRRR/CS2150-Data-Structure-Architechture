//Tianze Ren, tr2bx, 10/19/2022, hashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class hashTable{
public:
    hashTable(int size);
    ~hashTable();
    void insert (string s);
    bool find (string s);
    int hashFunction (string s);
    
private:
    vector <string> bucket;
    int size;

};

bool checkprime(unsigned int p);
int getNextPrime(unsigned int n);

#endif
