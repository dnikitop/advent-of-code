// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


long int horizontal = 0;
long int vertical = 0;
long int aim = 0;
int main () {
    string line;
    ifstream myfile ("input.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line[0] == 'f'){
                horizontal+=stoi(line.substr(8));
                vertical+=aim*stoi(line.substr(8));
            } else if(line[0] == 'u') {
                aim-=stoi(line.substr(3));
            } else if(line[0] == 'd') {
                aim+=stoi(line.substr(5));
            }
            cout << horizontal << " " << vertical << " " << aim << endl;
        }
        
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }
    std::cout <<horizontal * vertical << std::endl;

  return 0;
}