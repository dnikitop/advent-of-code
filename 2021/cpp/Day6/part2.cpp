// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<long long unsigned int> fish;


vector<vector<long long unsigned int>> cache;


long long unsigned int calculateHowManyItWillCreate(int cycleIn, size_t daysLeft){
    if(cache[daysLeft][cycleIn] != 0){
        return cache[daysLeft][cycleIn] - 1;
    }
    long totalFish = 0;
    int cycle = cycleIn;
    for (int i = daysLeft; i > 0; i--){
        cycle--;
        if (cycle < 0){
            totalFish++;
            totalFish+=calculateHowManyItWillCreate(8,max(i-1,0));
            cycle = 6;
        }
    }
    cache[daysLeft][cycleIn] = totalFish + 1;
    return totalFish;
}

int main () {
    for (int i = 0; i < 257; i++){
        vector<long long unsigned int > row;
        for (int j = 0; j < 9; j++){
            row.push_back(0);
        }
        cache.push_back(row);
    }
    string line;
    ifstream myfile ("input.txt");
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
    long long unsigned int count = 0;
    for ( int i = 0; i < fish.size(); i++){
        count += (1 + calculateHowManyItWillCreate(fish[i], 256));
    }
    //cout << 1 + calculateHowManyItWillCreate(4, 220) << endl;
    std::cout << count <<endl;

    for (int i = 0; i < 257; i++){
        vector<long long unsigned int > row;
        for (int j = 0; j < 9; j++){
            cout << cache[i][j] << " ";
        }
        cout << endl;
        cache.push_back(row);
    }




  return 0;
}