#include <string>
#include <cctype>
#include <iostream>
using namespace std;

string change(string myString) {
    string originalCopy(myString);
    string newString;

    while (myString.size()>0) {
        while (!isdigit(myString[0])&&myString.size()>0) {
            if (myString[0] == 'x') newString += '*';
            else newString += myString[0];
            myString.erase(0,1);
        };

        while (isdigit(myString[0])&&myString.size()>0) {
            if (iswspace(newString[newString.size()-1])|| newString[newString.size()-1]=='X')
                newString += 'X';
            else newString += myString[0];
            myString.erase(0,1);
        };
    };

    while (newString.find('*')<newString.size()&&
        originalCopy[newString.find('*')]=='X')
        newString[newString.find('*')] = 'X';

    return newString;
};

int main() {
    string myLine;
    bool loop;
    do {
        cout<<"Enter your line of words:\n";
        getline(cin, myLine);

        cout<< "Your result is\n"<<change(myLine);

        cout<<"\n To continue, enter 1; otherwise enter 0:\t";
        cin>>loop;
        cin.ignore();
    }while (loop);
    return 0;
}