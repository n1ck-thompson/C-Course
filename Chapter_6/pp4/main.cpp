#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

double average(istream& inputFile) {
    char next;
    int currentWordLength = 0;

    int wordsNumber = 0;
    double sum = 0;

    while(inputFile) {
        inputFile.get(next);
        if(next != ','&&next != ' '&&next != '\n'&&next != '.'&&inputFile) {
            ++currentWordLength;
        } else {
            if (currentWordLength!=0) {++wordsNumber; sum += currentWordLength;};
            currentWordLength = 0;
        };
    };
    return sum/wordsNumber;
};

int main() {
    fstream myFile("text.dat", ios::in);
    if(!myFile) {
        cout<<"File 'text.dat' cannot be found in directory";
        exit(1);};
    cout<<setprecision(3);
    cout<<"The average word length in your file is\t"<<average(myFile)<<".";
    return 0;
}
