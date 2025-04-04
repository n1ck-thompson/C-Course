#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

void junk(istream& inputFile, ostream& outputFile) {
    string fName, lName;
    int strangeCharsCounter = 0; //counts all "#N#"
    char next;
    while(inputFile.get(next)) {
        if(next == '#') {
            if(inputFile.peek() == 'N') {
                inputFile.ignore();

                if(inputFile.peek() == '#') {
                    inputFile.ignore();
                    ++strangeCharsCounter;
                    if (strangeCharsCounter == 1) {
                        cout <<"\nEnter First Name: \t";cin>>fName;
                        cout<<"\nEnter Last Name: \t";cin>>lName;
                    };
                    outputFile<<fName<<" "<<lName;continue;
                };
                if(inputFile){outputFile<<'#'<<'N'; continue;};
            };
            if(inputFile){outputFile<<'#'; continue;};
        };
        outputFile<<next;
    };
};