//Tianze Ren, tr2bx, 11/29/2022, traveling.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 * @brief The main function that takes in 5 parameters to create a world and print the path
 *
 * @param width The width of the world
 * @param Height The height of the world
 * @param num_cities The number of cities in the world
 * @param seed The parameter that keeps the same random generation
 * @param cities_to_visit The number of cities to visit
 * @todo
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    
    float shortest = computeDistance(me, dests.front(), dests);
    float distance = 0.0;
    vector <string> shortestPath = dests;
    sort (dests.begin()+1, dests.end());
    while (next_permutation(dests.begin()+1, dests.end())){
        distance = computeDistance(me, *dests.begin(), dests);
        if (distance < shortest){
            shortest = distance;
            shortestPath = dests;
        }
    }
    cout << "Minimum path has distance " << shortest << ": ";
    printRoute(*shortestPath.begin(), shortestPath);
    cout << endl;

    // TODO: YOUR CODE HERE
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
/**
 * @brief Comput the distance of a whole
 *
 * @param me The world generated
 * @param start The start city
 * @param dests The cities to visit
 */
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    float dist=0;
    string s = start;
    for(auto i: dests) {
        dist += me.getDistance(s, i);
        s = i;
    }
    dist += me.getDistance(dests.front(), dests.back());
    return dist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/**
 * @brief Print the route of the cities to visit
 *
 * @param start The start city
 * @param dests The cities to visit
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    string print = "";
    for (auto itr = dests.begin(); itr != dests.end(); itr++){
        print = print + *itr + " -> ";
    }
    print = print + start;
    cout << print;
}
