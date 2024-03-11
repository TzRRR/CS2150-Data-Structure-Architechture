#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;



// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    map <string, vector<string> > m;
    // read in two strings
    string s1, s2;
    while (s1 != "0" && s2 != "0"){
        file >> s1;
        file >> s2;
        m[s1];
        m[s2];
        m.find(s2)-> second.push_back(s1);
    }
    m.erase("0");
    
//    for (auto iter = m.begin(); iter != m.end(); iter++){
//        cout << iter-> first;
//        for (int x = 0; x < iter-> second.size(); x++){
//            cout << iter-> second[x];
//        }
//        cout << endl;
//    }
    
    /**
     * @brief Find all vertices that has in-degree 0
     *
     * This function finds all vertices that has in-degree 0 by looping through the map and check the size of value in each pair
     *
     * @return The average of the two passed values.
     * @param x The first value to average.
     * @param y The second value to average.
     * @todo Need to write acceptance tests for this function
     */
    string print = "";
    vector <string> zeroindegree;
    for (auto itr = m.begin(); itr != m.end(); itr++){
        if (itr-> second.size() == 0){
            print = print + itr-> first + " ";
            zeroindegree.push_back(itr-> first);
//            m.erase(itr-> first);
        }
    }
//    cout << zeroindegree[0] << endl;

    for (int i = 0; i < zeroindegree.size(); i++){
        for (auto itr = m.begin(); itr != m.end(); itr++){
            for (int j = 0; j < itr-> second.size(); j++){
                if (zeroindegree[i] == itr-> second[j]){
                    auto it = find(itr-> second.begin(), itr-> second.end(), zeroindegree[i]);
                    itr-> second.erase(it);
                    if (itr-> second.size() == 0){
                        zeroindegree.push_back(itr-> first);
                        print = print + itr-> first + " ";
                        itr-> second.clear();
                    }
                }
            }

        }
    }

    cout << print << endl;
//



    // close the file before exiting
    file.close();
}
