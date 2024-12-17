#include <iostream>
using namespace std;

void input(int & currentHours, int & currentMinutes, int & hoursToWait, int & minutesToWait, char & character) {
    cout << "Enter the current hours in 12-hour notation:\t";
    cin>>currentHours;
    cout<<"\n Enter the current minutes:\t";
    cin >> currentMinutes;
    cout <<"\n Enter p/P for PM or a/A for AM:\t";
    cin >> character;
    cout<<"\n Enter the number of hours you will wait:\t";
    cin >> hoursToWait;
    cout<<"\n Enter the number of minutes you will wait:\t";
    cin >> minutesToWait;
};

void output(int& currentHours, int & currentMinutes, int & hoursToWait, int & minutesToWait, char &character) {
    int newHours = currentHours + hoursToWait;
    int newMinutes = currentMinutes + minutesToWait;
    if (newMinutes >= 60) {newMinutes = newMinutes%60; ++newHours;};
    if (newHours >=12) {
        if(((newHours -newHours%12)/12)%2 == 1) {
            if (character == 'a'||character == 'A') character = 'P';
            else character = 'A';
        };
        newHours%=12;}
    cout<<"\n The time after waiting will be " <<newHours<<":"<<newMinutes<<character<<"M.";
};

int main() {
    bool loop = true; int currentHours = 0, currentMinutes = 0, hoursToWait = 0, minutesToWait=0; char character;
    do {
        input (currentHours, currentMinutes, hoursToWait, minutesToWait, character);
        output (currentHours, currentMinutes, hoursToWait, minutesToWait, character);
        cout <<"\n Enter 1 to start over or 0 to quit:\t";
        cin >> loop;

    } while(loop);
    return 0;
}