//Tianze Ren, tr2bx, 10/19/2022, hashTable.cpp
#include <iostream>
#include <string>
#include <math.h>
#include "hashTable.h"
using namespace std;

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

hashTable::hashTable(int size){
  if (checkprime(size*5)){
    bucket.resize(size*5);
  }
  else{
    bucket.resize(getNextPrime(size*5));
}
}

hashTable::~hashTable(){

}

void hashTable::insert(string s){
    int position = hashFunction(s);
    position %= size;
    for (int i = 0; i < bucket.size(); i++){
        int newp = (position + i*i) % bucket.size();
        if (bucket[newp] == ""){
            bucket[newp] = s;
            break;
        }
    }
}


bool hashTable::find(string s){
    int position = hashFunction(s);
    position %= size;
    for (int i = 0; i < bucket.size(); i++){
        int newp = (position + i*i) % bucket.size();
        if (bucket[newp] == s){
            return true;
        }
        else if (bucket[newp] == ""){
            return false;
        }
    }
    return false;
}

int hashTable::hashFunction(string s){
    int c = 17;
    int position = 0;
    for (int i = 0; i<s.size(); i++){
        position = position + c^i*s[i];
    }
    return position;
}
