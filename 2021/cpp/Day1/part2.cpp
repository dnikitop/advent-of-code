// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


vector<int> measurements;
vector<int> newMeasurments;

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

    for (size_t i = 0; i < measurements.size() - 2; i++){
        newMeasurments.push_back(measurements[i] + measurements[i+1] + measurements[i+2]);
    }


    size_t numGreater = 0;
    for (size_t i = 1; i < newMeasurments.size(); i++){
        if (newMeasurments[i] > newMeasurments[i-1]){
            numGreater++;
        }
    }
    std::cout << numGreater << std::endl;

  return 0;
}