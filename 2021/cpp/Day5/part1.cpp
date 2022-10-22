// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> field;


int main () {

    for (int i = 0; i < 1000; i++){
        vector<int> row;
        for (int j = 0; j < 1000; j++){
            row.push_back(0);
        }
        field.push_back(row);
    }


    string line;
    ifstream myfile ("input.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            string subString = line;
            int index = subString.find(',');
            int x1 = stoi(subString.substr(0,index));
            subString = subString.substr(index+1);
            index = subString.find(' ');
            int y1 = stoi(subString.substr(0,index));
            subString = subString.substr(index+4);

            index = subString.find(',');
            int x2 = stoi(subString.substr(0,index));
            subString = subString.substr(index+1);
            int y2 = stoi(subString.substr(0));
            // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            if (x1 == x2){
                for (int i = min(y1, y2); i <= max(y1,y2); i++){
                    field[x1][i]++;
                }
            } else if (y1 == y2){
                for (int i = min(x1, x2); i <= max(x1,x2); i++){
                    field[i][y1]++;
                }
            } else {
                int dist = abs(x1 - x2) + 1;
                if (x2 > x1 && y2 > y1){
                    for (int i = 0; i < dist; i++){
                        field[x1+i][y1+i]++;
                    }
                } else if (x2 > x1 && y1 > y2){
                    for (int i = 0; i < dist; i++){
                        field[x1+i][y1-i]++;
                    }
                } else if (x1 > x2 && y1 > y2){
                    for (int i = 0; i < dist; i++){
                        field[x1-i][y1-i]++;
                    }
                } else if (x1 > x2 && y2 > y1){
                    for (int i = 0; i < dist; i++){
                        field[x1-i][y1+i]++;
                    }
                }
            }
            
        
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }
    int count = 0;
    for (int i = 0; i < 1000; i++){
        vector<int> row;
        for (int j = 0; j < 1000; j++){
            if(field[i][j] >=2){
                count++;
            }
        }
    }


    std::cout << count <<endl;




  return 0;
}