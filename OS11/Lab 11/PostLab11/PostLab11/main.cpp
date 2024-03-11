// Tianze Ren, tr2bx, main.cpp, 12/02/2022
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include "configuration.h"
using namespace std;

/**
 * @brief Solve the puzzle
 *
 * This function takes a puzzle and calculates the steps required to solve it or prints IMPOSSIBLE if it is unsolvable
 *
 * @return The default value 0
 */
int main(){
    cout << "Enter puzzle" << endl;
    vector <int> tokens;
    string token;
    while (cin >> token){
        tokens.push_back(stoi(token));
    }
    
    cout << "Solving puzzle" << endl;
    
    configuration c (tokens);
    
    vector <int> infinity = c.numbers;
    int counter = 0;
    for (int i = 0; i < infinity.size()-1; i++){
        for (int j = i+1; j < infinity.size(); j++){
            if (infinity[i] != 0 && infinity[j] != 0){
                if (infinity[i] > infinity[j]){
                    swap(infinity[i], infinity[j]);
                    counter++;
                }
            }
            
        }
    }
    
    if (counter % 2 == 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    queue <configuration> q;
    q.push(c);
    vector <configuration> neighbors;
    vector <int> answer;
    answer.push_back(1);
    answer.push_back(2);
    answer.push_back(3);
    answer.push_back(4);
    answer.push_back(5);
    answer.push_back(6);
    answer.push_back(7);
    answer.push_back(8);
    answer.push_back(0);
    set<vector <int> > visited;
    while (!q.empty()){
        if (q.front().numbers != answer){
            neighbors = q.front().generateNeighbors();
            q.pop();
            for (int k = 0; k < neighbors.size(); k++){
                if (visited.find(neighbors[k].numbers) == visited.end()){
                    q.push(neighbors[k]);
                    visited.insert(neighbors[k].numbers);
                }
            }
        }
        else {
            cout << q.front().steps << endl;
            return 0;
        }
        
    }
    
    
    return 0;
}
