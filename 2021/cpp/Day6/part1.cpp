// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> fish;


int main () {



    string line;
    ifstream myfile ("input2.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            string subString = line;
            while(subString.find(',') != std::string::npos){
                int index = subString.find(',');
                fish.push_back(stoi(subString.substr(0,index)));
                subString = subString.substr(index+1);
            }
            fish.push_back(stoi(subString.substr(0)));
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }
            for(int j = 0; j < fish.size(); j++){
            cout << fish[j] << " ";
        }
        cout << endl;
    for (int i = 0; i < 130; i++){
        int size = fish.size();
        for (int j = 0; j < size; j++){
            fish[j]--;
            if(fish[j] < 0){
                fish[j] = 6;
                fish.push_back(8);
            }
        }
        for(int j = 0; j < fish.size(); j++){
            //cout << fish[j] << " ";
        }
        //cout << endl;
    }

    std::cout << fish.size() <<endl;




  return 0;
}