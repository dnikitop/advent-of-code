// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int getMostCommon(vector<vector<int>> input, size_t index){
    int count = 0;
    for(size_t i = 0; i < input.size(); i++){
        count+= input[i][index];
    }
    if (count*2 == input.size()){
        cout << "mostCommon: " << 2 << endl;
        return 2;
    } else if (count > input.size()/2){
        cout << "mostCommon: " << 1 << endl;
        return 1;
    } else {
        cout << "mostCommon: " << 0 << endl;
        return 0;
    }
}

vector<vector<int>> measurements;

int totalBits = 12;

int main () {
    string line;
    ifstream myfile ("input.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            vector<int> num;
            for (size_t i = 0; i < totalBits; i++){
                num.push_back(stoi(line.substr(i,1)));
            }
            measurements.push_back(num);
            // cout << line << '\n';
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }
    cout << measurements.size() << endl;
    int epsilon = 0;
    int gamma = 0;

    vector<int> mostCommon;
    for(size_t i = 0; i < totalBits; i++){
        int count = 0;
        for(size_t j = 0; j < measurements.size(); j++){
            count+=measurements[j][i];
        }
        if (count > measurements.size()/2) {
            epsilon += 1 << ((totalBits - 1) - i);
            mostCommon.push_back(1);
        } else {
            if(count == measurements.size()/2){
                gamma += 1 << ((totalBits - 1) - i);
                mostCommon.push_back(2);
            } else {
                gamma += 1 << ((totalBits - 1) - i);
                mostCommon.push_back(0);
            }

        }
    }

    vector<vector<int>> oxygenMeasurements(measurements);
    int oxygen = 0;

    int index = 0;
    while(oxygenMeasurements.size() >  1){
        int mostCommon = getMostCommon(oxygenMeasurements,index);
        for(size_t j = 0; j < oxygenMeasurements.size(); j++){
            if((mostCommon != 2 && oxygenMeasurements[j][index] != mostCommon) || (mostCommon == 2 && oxygenMeasurements[j][index] == 0)){
                oxygenMeasurements.erase(oxygenMeasurements.begin() + j);
                cout << "deleteing" << endl;
                j--;
            }
        }
        index++;
        cout << "size: " <<  oxygenMeasurements.size() << endl;
    }
    for (size_t j = 0; j < oxygenMeasurements[0].size(); j++){
        cout << oxygenMeasurements[0][j];
         if (oxygenMeasurements[0][j] == 1){
            oxygen += 1 << ((totalBits - 1) - j);
        }
        std::cout << endl;
    }

    vector<vector<int>> carbonMeasurements(measurements);
    int carbon = 0;
    index = 0;
    while(carbonMeasurements.size() > 1){
        int mostCommon = getMostCommon(carbonMeasurements,index);
        for(size_t j = 0; j < carbonMeasurements.size(); j++){
            if((mostCommon != 2 && carbonMeasurements[j][index] == mostCommon) || (mostCommon == 2 && carbonMeasurements[j][index] == 1)){
                carbonMeasurements.erase(carbonMeasurements.begin() + j);
                j--;
            }
        }
        index++;
    }
    for (size_t j = 0; j < carbonMeasurements[0].size(); j++){
        cout << carbonMeasurements[0][j];
         if (carbonMeasurements[0][j] == 1){
            carbon += 1 << ((totalBits - 1) - j);
        }
    }


    std::cout << epsilon << endl;
    std::cout << gamma << endl;
    std::cout << oxygen << endl;
    std::cout << carbon << endl;
    std::cout << oxygen * carbon << std::endl;

  return 0;
}