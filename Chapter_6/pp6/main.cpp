#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
void new_line(istream& myStream, string& line) {
    char symbol;

    myStream.get(symbol);
    line ="";
    while (symbol != '\n') {
        line += symbol;
        myStream.get(symbol);
        if(symbol =='#') {
            myStream.ignore();
            myStream.ignore();
            myStream.get(symbol);
        };
        if (!myStream) break;
    };
};

const int NUMBER_OF_CHAPTERS = 18;

int main() {
    fstream answers("answers.dat", ios::in);
    if(!answers) {
        cout << "File 'answers.dat' couldn't be found.";
        exit(1);
    }
    string answer, question;

    int answerCounter = 0;

    int chapterNumber = 18;

    while(true) {
        cout<<"\n\nAsk a question to get an 'answer'.\n";
        cin>>question;
        new_line(answers, answer);
        ++answerCounter;
        if(answerCounter!= 1 )cout<<answer;

        else {
            cout<<answer<<chapterNumber<<".";
            --chapterNumber;
            if (chapterNumber == 0) chapterNumber = NUMBER_OF_CHAPTERS;
        }
        if (answerCounter == 8) {
            answers.close();
            answers.open("answers.dat", ios::in);
            answerCounter=0;
        };
    };
    return 0;
}