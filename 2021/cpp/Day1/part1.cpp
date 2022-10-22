// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


vector<int> measurements;


int main () {
    string line;
    ifstream myfile ("input.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            measurements.push_back(stoi(line));
            // cout << line << '\n';
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }

    size_t numGreater = 0;
    for (size_t i = 1; i < measurements.size(); i++){
        if (measurements[i] > measurements[i-1]){
            numGreater++;
        }
    }
    std::cout << numGreater << std::endl;

  return 0;
}