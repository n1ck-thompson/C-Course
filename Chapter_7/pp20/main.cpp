#include<iostream>
#include<cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

double menProb[120] ={0};
double womenProb[120]={0};

void arraysAssignment(double to[], double from[], int size) {
    for (int i=0;i<size;++i)
        to [i] = from[i];
}

void getProbabilities(istream& stream, double probabilities1[], double probabilities2[], int size = 120) {
    double ignore= 0;
    for (int i =0; i<size;i++)
        stream>>ignore>>probabilities1[i]>>probabilities2[i];
};

int main() {

    bool loop = true;
    cout<<"\n Press 1 to start, 2 to cancel ";
    cin>>loop;
    do {
        srand(100000*time(0));
        double maleDeathProb[120] = {0};
        double femaleDeathProb[120] = {0};

        double deathProbFocusOn[120] = {0};

        fstream myFile("LifeDeathProbability.txt", ios::in);
        if (!myFile) {
            cout<<"\nFile 'LifeDeathProbability.txt' not found, ensure file is in correct directory.";
            exit(1);

        };

        getProbabilities(myFile, maleDeathProb, femaleDeathProb);
        myFile.close();

        double randomNumber = static_cast<double>(rand())/RAND_MAX;

        char gender = ' ';
        int age = 0;

        cout<<"Enter gender (m for male and f for female) :\t";
        cin>>gender;
        cout<<"\nEnter age:\t";
        cin>>age;

        if (gender = 'f')
            arraysAssignment(deathProbFocusOn, femaleDeathProb, 120);
        else arraysAssignment(deathProbFocusOn, maleDeathProb, 120);

        while (age<120 && randomNumber > deathProbFocusOn[age]) {
            randomNumber = static_cast<double>(rand())/RAND_MAX;
            cout<<randomNumber;
            ++age;
        };

        cout<<"\nThe data shows that you would live to the age of "<<age<<"\n";
        cout<<randomNumber;
        cout<<"\nWould you like to continue? (enter 1 to continue or 0 to quit.) ";
        cin>>loop;

    }while (loop==true);
    return 0;

};