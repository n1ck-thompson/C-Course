#include <iostream>
#include <string>
using namespace std;

int main() {

    string day;// allows program to identify day
    int startTimeH(0), startTimeM(0); // defines start time, H and M stand for hours and minutes, obviously

    char nothing; // used to absorb colon in the input

    int callLength(0);
    bool loop; // boolean to control loop
    double minuteCost; // allows program to identify cost of minute according to call time

    do {
        cout<<"Enter the day as a two-letter abbreviation (i.e. Sa for saturday):  ";
        cin>>day;

        cout <<"Enter the call time in 24 hour notation: ";
        cin>>startTimeH>>nothing>>startTimeM; // takes inputs and assigns to 3 different variables

        cout << "Enter the call length in minutes rounded to the nearest whole number: ";
        cin>>callLength;

        if (day == "Sa" || day == "Su" || day == "sa" || day == "su" || day == "sU" || day =="sA" || day =="SU" || day == "SA") {
            minuteCost = .15;
        }
        else {
            if (8 <= startTimeH && startTimeH < 18) minuteCost = .4;

            else minuteCost = .25;
        }; // if else statement used to switch between cases of a call.
        cout.precision(3);

        cout << "The cost of the call is: $" << minuteCost * callLength << endl;
        cout<< "Enter 1 to start over, or 0 to quit: ";
        cin>>loop;
    }
    while(loop);

    return 0;
}
