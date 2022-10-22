// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int horizontal = 0;
int vertical = 0;

int main () {
    string line;
    ifstream myfile ("input.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line[0] == 'f'){
                horizontal+=stoi(line.substr(8));
            } else if(line[0] == 'u') {
                vertical-=stoi(line.substr(3));
            } else if(line[0] == 'd') {
                vertical+=stoi(line.substr(5));
            }
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }
    std::cout <<horizontal * vertical << std::endl;

  return 0;
}