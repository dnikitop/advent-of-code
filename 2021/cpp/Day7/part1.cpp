// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> positions;


int main () {



    string line;
    ifstream myfile ("input.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            string subString = line;
            while(subString.find(',') != std::string::npos){
                int index = subString.find(',');
                positions.push_back(stoi(subString.substr(0,index)));
                subString = subString.substr(index+1);
            }
            positions.push_back(stoi(subString.substr(0)));
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }

    int min = 1000;
    int max = 0;
    for(int i = 0; i < positions.size(); i++){
        if(positions[i] > max){
            max = positions[i];
        }
        if(positions[i] < min){
            min = positions[i];
        }
    }
    long fuelRequired = max * max * positions.size();
    int aligned = 0;
    for (int i = min; i <= max; i++){
        int fuel = 0;
        for (int j = 0; j < positions.size(); j++){
            fuel+=(abs(positions[j]-i) + 1)*(abs(positions[j]-i)) / 2;
            //cout << i << " " << positions[j] << " " << (abs(positions[j]-i) + 1)*(abs(positions[j]-i)) / 2 << endl;
        }
        //cout << i << " " << fuel << endl;
        if (fuel < fuelRequired){
            fuelRequired = fuel;
            aligned = i;
        }
    }

    int * temp = new int(5);
    

    std::cout << aligned << " " << fuelRequired <<endl;




  return 0;
}