#include <iostream>
using namespace std;

void input(int& hours, int & minutes) {
    cout <<"Enter hours in 24-hour notation:\t"; cin >> hours;
    cout <<"Enter minutes only as single number (i.e. 23:05 = 5 for minutes, 23:13 = 13):\t"; cin >> minutes;
};

void convert(int & hours, char & note) {
    note = 'A';
    if (hours - hours%12 > 0) note = 'P';
};

void output(int& hours, int & minutes, char & note) {
    if (minutes < 10)
        if (hours == 0)
            cout << "\nThe equivalent time of "<<"0"<<":0"<<minutes<<" in 12-hour notation is "<<"12"<<":0"<<minutes<<" "<<note<<"M.";
        else
            cout << "\nThe equivalent time of "<<hours<<":0"<<minutes<<" in 12-hour notation is "<<hours%12<<":0"<<minutes<<" "<<note<<"M.";
    else
        if (hours ==0)
            cout<<"\nThe equivalent time of "<<"0"<<":"<<minutes<<" in 12-hour notation is "<<"12"<<":"<<minutes<<" "<<note<<"M.";
        else
            cout<<"\nThe equivalent time of "<<hours<<":"<<minutes<<" in 12-hour notation is "<<hours%12<<":"<<minutes<<" "<<note<<"M.";

}

int main() {
    bool loop = true;int hours, minutes; char note;
    do {
        input(hours, minutes);
        convert(hours, note);
        output(hours, minutes, note);
        cout<<"\nEnter 1 to start over or 0 to quit: ";
        cin>>loop;
    }while(loop);
    return 0;
}