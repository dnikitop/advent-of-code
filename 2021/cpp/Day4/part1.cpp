// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> digitsChosen;
vector<vector<int>> boardLines;
vector<vector<vector<int>>> boards;

bool isWinner(vector<vector<int>> boardIn, vector<int> digitsChosenIn){
    for (size_t i = 0; i < boardIn.size(); i++){
        bool goodRow = true;
        bool goodCol = true;
        for (size_t j = 0; j < boardIn[i].size(); j++){
            if (std::find(digitsChosenIn.begin(), digitsChosenIn.end(), boardIn[i][j]) == digitsChosenIn.end()){
                goodRow = false;
            }
            if (std::find(digitsChosenIn.begin(), digitsChosenIn.end(), boardIn[j][i]) == digitsChosenIn.end()){
                goodCol = false;
            }
        }
        if(goodRow || goodCol){
            return true;
        }
    }
    return false;

}

int main () {
    string line;
    ifstream myfile ("input2.txt");
    if (myfile.is_open()){
        int index = 0;
        getline(myfile,line);
        string subStr = line;
        while(subStr.find(',')!=std::string::npos){
            index = subStr.find(',');
            digitsChosen.push_back(stoi(subStr.substr(0,index)));
            subStr = subStr.substr(index+1);
        }
        digitsChosen.push_back(stoi(subStr.substr(0)));
        while (getline(myfile,line)){
            if (line.empty()){
                //cout << "space" << endl;
            } else {
                vector<int> boardLine;
                for (size_t i = 0; i < 5; i++){
                    subStr = line.substr(i*3,2);
                    if (subStr[0] == ' '){
                        boardLine.push_back(stoi(subStr.substr(1,1)));
                    } else {
                        boardLine.push_back(stoi(subStr));
                    }
                }
                boardLines.push_back(boardLine);
            }
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }
    for(size_t i = 0; i < boardLines.size()/5; i++){
        vector<vector<int>> board;
        board.push_back(boardLines[i*5]);
        board.push_back(boardLines[i*5 + 1]);
        board.push_back(boardLines[i*5 + 2]);
        board.push_back(boardLines[i*5 + 3]);
        board.push_back(boardLines[i*5 + 4]);
        boards.push_back(board);
    }
    cout << boards.size() << endl;
    std::vector<int> newDigits;
    bool foundWinner = false;
    bool digitsIndex = 0;
    int winnerIndex = -1;
    for (size_t i = 0; !foundWinner && i < digitsChosen.size(); i++){
        newDigits.push_back(digitsChosen[i]);
        for (size_t j = 0; j < boards.size();j++){
            if(isWinner(boards[j],newDigits)){
                winnerIndex = j;
                foundWinner = true;
                digitsIndex = i;
                break;
            }
        }
    }
    int count = 0;
    for (size_t i = 0; i < boards[winnerIndex].size(); i++){
        for (size_t j = 0; j < boards[winnerIndex][i].size(); j++){
            if (std::find(newDigits.begin(), newDigits.end(), boards[winnerIndex][i][j]) == newDigits.end()){
                count+=boards[winnerIndex][i][j];
            }
        }
    }

    cout << count << endl;
    cout << count * newDigits[newDigits.size() - 1] << endl;





  return 0;
}