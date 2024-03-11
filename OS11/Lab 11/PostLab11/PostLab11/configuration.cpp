// Tianze Ren, tr2bx, configuration.cpp, 12/02/2022
#include "configuration.h"
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * @brief The constructor that takes a vector as parameter
 *
 * @param input The vector used to initialize the object
 */
configuration:: configuration(vector <int> input){
    numbers = input;
}

/**
 * @brief Move the blankspace to other positions
 *
 * This function moves the blankspace in the puzzle to all possible positions
 * @sa generateNeighbors
 * @return A vector of configurations
 */
vector <configuration> configuration:: generateNeighbors(){
    vector <configuration> possibilities;
    if (numbers[0] == 0){
        vector <int> temp1 = numbers;
        swap(temp1[0], temp1[1]);
        configuration c1(temp1);
        c1.steps = steps+1;
        possibilities.push_back(c1);
        
        vector <int> temp2 = numbers;
        swap(temp2[0], temp2[3]);
        configuration c2(temp2);
        c2.steps = steps+1;
        possibilities.push_back(c2);
    }
    else if (numbers[1] == 0){
        vector <int> temp3 = numbers;
        swap(temp3[1], temp3[0]);
        configuration c3(temp3);
        c3.steps = steps+1;
        possibilities.push_back(c3);
        
        vector <int> temp4 = numbers;
        swap(temp4[1], temp4[2]);
        configuration c4(temp4);
        c4.steps = steps+1;
        possibilities.push_back(c4);
        
        vector <int> temp5 = numbers;
        swap(temp5[1], temp5[4]);
        configuration c5(temp5);
        c5.steps = steps+1;
        possibilities.push_back(c5);
    }
    else if (numbers[2] == 0){
        vector <int> temp6 = numbers;
        swap(temp6[2], temp6[1]);
        configuration c6(temp6);
        c6.steps = steps+1;
        possibilities.push_back(c6);
        
        vector <int> temp7 = numbers;
        swap(temp7[2], temp7[5]);
        configuration c7(temp7);
        c7.steps = steps+1;
        possibilities.push_back(c7);
    }
    else if (numbers[3] == 0){
        vector <int> temp8 = numbers;
        swap(temp8[3], temp8[0]);
        configuration c8(temp8);
        c8.steps = steps+1;
        possibilities.push_back(c8);
        
        vector <int> temp9 = numbers;
        swap(temp9[3], temp9[4]);
        configuration c9(temp9);
        c9.steps = steps+1;
        possibilities.push_back(c9);
        
        vector <int> temp10 = numbers;
        swap(temp10[3], temp10[6]);
        configuration c10(temp10);
        c10.steps = steps+1;
        possibilities.push_back(c10);
    }
    else if (numbers[4] == 0){
        vector <int> temp11 = numbers;
        swap(temp11[4], temp11[1]);
        configuration c11(temp11);
        c11.steps = steps+1;
        possibilities.push_back(c11);
        
        vector <int> temp12 = numbers;
        swap(temp12[4], temp12[3]);
        configuration c12(temp12);
        c12.steps = steps+1;
        possibilities.push_back(c12);
        
        vector <int> temp13 = numbers;
        swap(temp13[4], temp13[5]);
        configuration c13(temp13);
        c13.steps = steps+1;
        possibilities.push_back(c13);
        
        vector <int> temp14 = numbers;
        swap(temp14[4], temp14[7]);
        configuration c14(temp14);
        c14.steps = steps+1;
        possibilities.push_back(c14);
    }
    else if (numbers[5] == 0){
        vector <int> temp15 = numbers;
        swap(temp15[5], temp15[2]);
        configuration c15(temp15);
        c15.steps = steps+1;
        possibilities.push_back(c15);
        
        vector <int> temp16 = numbers;
        swap(temp16[5], temp16[4]);
        configuration c16(temp16);
        c16.steps = steps+1;
        possibilities.push_back(c16);
        
        vector <int> temp17 = numbers;
        swap(temp17[5], temp17[8]);
        configuration c17(temp17);
        c17.steps = steps+1;
        possibilities.push_back(c17);
    }
    else if (numbers[6] == 0){
        vector <int> temp18 = numbers;
        swap(temp18[6], temp18[3]);
        configuration c18(temp18);
        c18.steps = steps+1;
        possibilities.push_back(c18);
        
        vector <int> temp19 = numbers;
        swap(temp19[6], temp19[7]);
        configuration c19(temp19);
        c19.steps = steps+1;
        possibilities.push_back(c19);
    }
    else if (numbers[7] == 0){
        vector <int> temp20 = numbers;
        swap(temp20[7], temp20[4]);
        configuration c20(temp20);
        c20.steps = steps+1;
        possibilities.push_back(c20);
        
        vector <int> temp21 = numbers;
        swap(temp21[7], temp21[6]);
        configuration c21(temp21);
        c21.steps = steps+1;
        possibilities.push_back(c21);
        
        vector <int> temp22 = numbers;
        swap(temp22[7], temp22[8]);
        configuration c22(temp22);
        c22.steps = steps+1;
        possibilities.push_back(c22);
    }
    else if (numbers[8] == 0){
        vector <int> temp23 = numbers;
        swap(temp23[8], temp23[5]);
        configuration c23(temp23);
        c23.steps = steps+1;
        possibilities.push_back(c23);
        
        vector <int> temp24 = numbers;
        swap(temp24[8], temp24[7]);
        configuration c24(temp24);
        c24.steps = steps+1;
        possibilities.push_back(c24);
    }
    return possibilities;
}
