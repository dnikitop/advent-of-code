// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


vector<vector<int>> measurements;


int main () {
    string line;
    ifstream myfile ("input.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            vector<int> num;
            for (size_t i = 0; i < 12; i++){
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
    for(size_t i = 0; i < 12; i++){
        int count = 0;
        for(size_t j = 0; j < measurements.size(); j++){
            count+=measurements[j][i];
        }
        if (count > measurements.size()/2) {
            cout << "here" << endl;
            epsilon += 1 << (11 - i);
        } else {
            gamma += 1 << (11 - i);
        }
    }
    std::cout << epsilon << endl;
    std::cout << gamma << endl;
    std::cout << epsilon * gamma << std::endl;

  return 0;
}