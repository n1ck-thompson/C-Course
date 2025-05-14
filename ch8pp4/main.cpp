#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    string fullName;
    bool loop;
    do {
        cout<<"Enter your full name and then press enter:\t";
        getline(cin, fullName);
        cin.get();

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

        cout<<"\nEnter 1 to continue or 0 to quit:\t";
        cin>>loop;
    } while (loop);

    return 0;
}