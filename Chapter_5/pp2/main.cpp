#include <iostream>
using namespace std;

void input(int& currentHours, int & currentMinutes, int & hoursToWait, int & minutesToWait) {
    cout<<"Enter the current hour in 24 hour notation:\t";
    cin>>currentHours;
    cout<<"Enter the current minute:\t";
    cin>>currentMinutes;
    cout<<"Enter how many hours you will wait for:\t";
    cin>>hoursToWait;
    cout<<"Enter how many minutes you will wait for:\t";
    cin>>minutesToWait;
};

void output(int& currentHours, int & currentMinutes, int & hoursToWait, int & minutesToWait) {
    int newHours = currentHours + hoursToWait;
    int newMinutes = currentMinutes + minutesToWait;
    if (newMinutes >= 60) {newMinutes = newMinutes%60; ++newHours;};
    if (newHours >= 24 ) newHours%=24;
    if (newMinutes < 10)
        cout<<"\nThe time after waiting will be "<<newHours<<":0"<<newMinutes<<".";
    else
        cout<<"\nThe time after waiting will be "<<newHours<<":"<<newMinutes<<".";


};

int main() {
    bool loop = true;int currentHours = 0, currentMinutes = 0, hoursToWait = 0, minutesToWait = 0;
    do {
        input(currentHours, currentMinutes, hoursToWait, minutesToWait);
        output(currentHours, currentMinutes, hoursToWait, minutesToWait);
        cout<<"\nEnter 1 to start over or 0 to quit:\t";
        cin>>loop;
    } while(loop);
    return 0;
}

