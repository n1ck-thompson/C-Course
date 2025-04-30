#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    char next;
    string finalSentence;
    cout<<"Enter your sentence: \n";
    cin>>finalSentence;
    while ((next = cin.get())!='.') {
        if (!finalSentence.empty()&&iswspace(next)&&iswspace(finalSentence[finalSentence.size()-1])) continue;

        if (next =='\n') next = ' ';
        finalSentence+=tolower(next);
    };
    if (iswspace(finalSentence[0])) finalSentence.erase(0,1);

    if (iswspace(finalSentence[finalSentence.size()-1]))
        finalSentence.erase(finalSentence.size()-1,1);
    finalSentence[0] = toupper(finalSentence[0]);
    finalSentence+='.';
    cout<<"\n"<<finalSentence;

    return 0;
};