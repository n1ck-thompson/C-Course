#include <string>
#include <vector>
#include<cctype>
#include <iostream>
using namespace std;

void sortByInsertion(string & myString) {

    char temp;

    for (size_t i =1; i<myString.size();++i) {
        for (size_t j = i ; j > 0; --j) {
            if (myString[j] < myString[j-1]) {
                temp = myString[j];
                myString[j] = myString[j-1];
                myString[j-1] = temp;
            }
            else break;
        };
    };
};

string nextWord(string& myString) {
    size_t firstDelimiterIndex = myString.find_first_of(" ,.\n");

    string returnedWord( myString.substr(0, firstDelimiterIndex));

    myString.erase(0, firstDelimiterIndex+1);

    while (myString.find_first_of(" ,.\n") == 0) myString.erase(0,1);

    return returnedWord;
};

int main() {

    string myLine;

    cout<<"Enter a Sentence:\n";
    getline(cin, myLine);
    myLine+=" ";
    while (myLine.find_first_of(" ,.\n") == 0) myLine.erase(0,1 );
    string clearedLine;
    size_t wordsNumber = 0;
    while (myLine!="") {

        clearedLine+= nextWord(myLine);
        ++wordsNumber;
    };

    for (size_t index = 0; index<clearedLine.size();++index)
        clearedLine[index] = tolower(clearedLine[index]);

    sortByInsertion(clearedLine);
    vector<string> charactersVector;
    while (clearedLine!="") {
        charactersVector.push_back(
            clearedLine.substr(0,
                clearedLine.find_first_not_of(clearedLine[0])));

        clearedLine.erase(0,clearedLine.find_first_not_of(clearedLine[0]));
    };
    cout<<wordsNumber<<" "<<"words";
    for (string charactersString: charactersVector)
        cout<<"\n"<<charactersString.size()<<" "<<charactersString[0];

    return 0;
};