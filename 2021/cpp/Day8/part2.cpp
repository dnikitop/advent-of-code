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
    ifstream myfile ("input.txt");
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

    int total = 0;
    for (auto i: lines){
        vector<vector<char>> possibleCharacters;
        for (int i = 0; i < 7; i++){
            vector<char> chars;
            chars.push_back('a');
            chars.push_back('b');
            chars.push_back('c');
            chars.push_back('d');
            chars.push_back('e');
            chars.push_back('f');
            chars.push_back('g');
            possibleCharacters.push_back(chars);
        }

        for (auto j: i.first){ //step 1
            if (j.size() == 2){
                possibleCharacters[2].clear();
                possibleCharacters[5].clear();
                possibleCharacters[2].push_back(j[0]);
                possibleCharacters[5].push_back(j[0]);
                possibleCharacters[2].push_back(j[1]);
                possibleCharacters[5].push_back(j[1]);
            }
        }
        
        for (auto j: i.first){ //step 2
            if (j.size() == 3){
                for (auto k: j){
                    if(find(possibleCharacters[2].begin(), possibleCharacters[2].end(), k) == possibleCharacters[2].end()){
                        possibleCharacters[0].clear();
                        possibleCharacters[0].push_back(k);
                    }
                }
            }
        }

        for (auto j: i.first){ //step 3
            if (j.size() == 4){
                string temp = j;
                temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[2][0]), temp.end());
                temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[2][1]), temp.end());
                possibleCharacters[1].clear();
                possibleCharacters[1].push_back(temp[0]);
                possibleCharacters[1].push_back(temp[1]);
                possibleCharacters[3].clear();
                possibleCharacters[3].push_back(temp[0]);
                possibleCharacters[3].push_back(temp[1]);
            }
        }
        //step 4
        possibleCharacters[4].erase(std::remove(possibleCharacters[4].begin(), possibleCharacters[4].end(), possibleCharacters[0][0]), possibleCharacters[4].end());
        possibleCharacters[4].erase(std::remove(possibleCharacters[4].begin(), possibleCharacters[4].end(), possibleCharacters[1][0]), possibleCharacters[4].end());
        possibleCharacters[4].erase(std::remove(possibleCharacters[4].begin(), possibleCharacters[4].end(), possibleCharacters[1][1]), possibleCharacters[4].end());
        possibleCharacters[4].erase(std::remove(possibleCharacters[4].begin(), possibleCharacters[4].end(), possibleCharacters[2][0]), possibleCharacters[4].end());
        possibleCharacters[4].erase(std::remove(possibleCharacters[4].begin(), possibleCharacters[4].end(), possibleCharacters[2][1]), possibleCharacters[4].end());

        possibleCharacters[6].erase(std::remove(possibleCharacters[6].begin(), possibleCharacters[6].end(), possibleCharacters[0][0]), possibleCharacters[6].end());
        possibleCharacters[6].erase(std::remove(possibleCharacters[6].begin(), possibleCharacters[6].end(), possibleCharacters[1][0]), possibleCharacters[6].end());
        possibleCharacters[6].erase(std::remove(possibleCharacters[6].begin(), possibleCharacters[6].end(), possibleCharacters[1][1]), possibleCharacters[6].end());
        possibleCharacters[6].erase(std::remove(possibleCharacters[6].begin(), possibleCharacters[6].end(), possibleCharacters[2][0]), possibleCharacters[6].end());
        possibleCharacters[6].erase(std::remove(possibleCharacters[6].begin(), possibleCharacters[6].end(), possibleCharacters[2][1]), possibleCharacters[6].end());

        //step 5
        for (auto j: i.first){
            if (j.size() == 6){
                if( find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() && 
                    find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[2][1]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[4][0]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[4][1]) != j.end()){

                    string temp = j;
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[0][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[2][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[2][1]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[4][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[4][1]), temp.end());
                    possibleCharacters[3].erase(std::remove(possibleCharacters[3].begin(), possibleCharacters[3].end(), temp[0]), possibleCharacters[3].end());
                    possibleCharacters[1].clear();
                    possibleCharacters[1].push_back(temp[0]);
                }
            }
        }

        //step 6
        for (auto j: i.first){ 
            if (j.size() == 6){
                if( find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() && 
                    find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[2][1]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end()){

                    string temp = j;
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[0][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[2][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[2][1]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[1][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[3][0]), temp.end());
                    possibleCharacters[4].erase(std::remove(possibleCharacters[4].begin(), possibleCharacters[4].end(), temp[0]), possibleCharacters[4].end());
                    possibleCharacters[6].clear();
                    possibleCharacters[6].push_back(temp[0]);
                }
            }
        }

        //step 7
        for (auto j: i.first){ 
            if (j.size() == 6){
                if( find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() && 
                    find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[4][0]) != j.end() &&
                    find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end()){
                    
                    string temp = j;
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[0][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[1][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[3][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[4][0]), temp.end());
                    temp.erase(std::remove(temp.begin(), temp.end(), possibleCharacters[6][0]), temp.end());
                    possibleCharacters[5].clear();
                    possibleCharacters[5].push_back(temp[0]);
                }
            }
        }

        //step 7
        possibleCharacters[2].erase(std::remove(possibleCharacters[2].begin(), possibleCharacters[2].end(), possibleCharacters[5][0]), possibleCharacters[2].end());
        

        int subTotal = 0;
        int mult = 1000;
        for (auto j: i.second){
            //1
            int theNum;
            if(j.size() == 6 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[4][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end() ){
                theNum = 0;
            } else if(j.size() == 2 &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end()){
                theNum = 1;
            } else if(j.size() == 5 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[4][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end() ){
                theNum = 2;
            } else if(j.size() == 5 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end() ){
                theNum = 3;
            } else if(j.size() == 4 &&
                find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end() ){
                theNum = 4;
            } else if(j.size() == 5 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end() ){
                theNum = 5;
            } else if(j.size() == 6 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[4][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end() ){
                theNum = 6;
            } else if(j.size() == 3 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end()){
                theNum = 7;
            } else if(j.size() == 7 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[4][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end() ){
                theNum = 8;
            } else if(j.size() == 6 &&
                find(j.begin(), j.end(), possibleCharacters[0][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[1][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[2][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[3][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[5][0]) != j.end() &&
                find(j.begin(), j.end(), possibleCharacters[6][0]) != j.end() ){
                theNum = 9;
            } else {
                cout << "something went wrong" << endl;
                int count = 0;
                for(auto k: possibleCharacters){
                    cout << count << ": ";
                    for (auto j: k){
                        cout << j << " ";
                    }
                    cout << endl;
                    count++;
                }
                for(auto k: i.first){
                    cout << k << " ";
                }
                cout << "| ";
                for(auto k: i.second){
                    cout << k << " ";
                }
                cout << endl;
                return 0;
            }
            subTotal+=mult*theNum;
            mult/=10;
        }
        total+=subTotal;
    }
    cout << total << endl;
    
  return 0;
}