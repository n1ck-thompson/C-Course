#include <iostream>
#include <string>

using namespace std;

int main() {
    string fullName;

    cout<<"Enter your full name and then press enter:\t";
    getline(cin, fullName);

    string firstName(fullName.substr(0, fullName.find(" ")));
    firstName+=" ";
    fullName.erase(0, fullName.find(" ")+1);

    string secondInitial;
    size_t secondSpaceIndex = fullName.find(" ");
    if (secondSpaceIndex < fullName.size()) {
        secondInitial = fullName[0];
        secondInitial+=".";
        fullName.erase(0, secondSpaceIndex+1);

    };

    string lastName(fullName);
    lastName+= ", ";

    cout<<lastName<<firstName<<secondInitial;

    return 0;
}