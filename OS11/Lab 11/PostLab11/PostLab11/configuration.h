#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class configuration{
public:
    configuration(vector <int> input);
    vector <configuration> generateNeighbors();
    int steps = 0;
    vector <int> numbers;
};
#endif


