#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

void copyRecordAndAverage(istream& inputFile, ostream& outputFile) {
    string fName, lName;
    int currentScore = 0;double scoresSum = 0;

    while(!inputFile.eof()) {

        inputFile>>lName; inputFile>>fName;
        outputFile<<lName; outputFile<<" "; outputFile<<fName;
        for(int i =0; i<10; ++i) {
            inputFile>>currentScore;
            outputFile<<" ";
            outputFile<<currentScore;
            scoresSum+=currentScore;
        };
        outputFile<<" "<<scoresSum/10;
        currentScore=0;
        scoresSum=0;
        if(inputFile.peek()!=EOF) outputFile<<"\n";
    };
};

int main() {
    fstream originalFile("record.dat", ios::in);

    if(!originalFile) {
        cout<<"File 'record.dat' not found in directory";
        exit(1);};
    fstream editedFile("edited record.dat", ios::out);
    copyRecordAndAverage(originalFile, editedFile);
}