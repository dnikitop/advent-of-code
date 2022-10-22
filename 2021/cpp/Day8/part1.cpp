// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//for (char i: path)
//    std::cout << i << ' ';

vector<pair<vector<string>, vector<string>>> lines;


int main () {

    string line;
    ifstream myfile ("input2.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            string subString = line;
            vector<string> uniques;
            for(int i = 0; i < 10; i++){
                int index = subString.find(' ');
                uniques.push_back(subString.substr(0,index));
                subString = subString.substr(index+1);
            }
            subString = subString.substr(2);
            vector<string> digits;
            for(int i = 0; i < 3; i++){
                int index = subString.find(' ');
                digits.push_back(subString.substr(0,index));
                subString = subString.substr(index+1);
            }
            digits.push_back(subString);
            lines.push_back(make_pair(uniques,digits));
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }
    int countUniqueDigits = 0;
    for (auto i: lines){
        for(auto j: i.first){
            cout << j << " ";
        }
        cout << "| ";
        for(auto j: i.second){
            if (j.size() == 2 || j.size() == 3 || j.size() == 4 || j.size() == 7){
                countUniqueDigits++;
            }
            cout << j << " ";
        }
        cout << endl;
    }
    cout << countUniqueDigits << endl;
  return 0;
}