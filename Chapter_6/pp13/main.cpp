#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    string fileName, countingString;
    cout<<"Enter your text file name as \"my file.txt\":\t";
    cin>>fileName;
    fstream myFile(fileName, ios::in);

    if(!myFile) {
        cout<<"Current file not found in directory";
        exit(1);};

    int counter = -1;
    while(myFile){
        myFile>>countingString;
        ++counter;
    };

    cout<<"Your file contains "<<counter<<" words.";

    return 0;
}