#include <iostream>
using namespace std;

int main() {

    int t; //user temperature input

    bool loop;

    do {

        t = 0;
        cout << "Enter the desired temperature: ";
        cin >> t;
        if (t > 0 && t < 999) {
            int t1 = t, t2 = t;

            int firstD=1, secondD=0, thirdD=0;

            firstD = (t - t%100)/100;
            secondD = ((t-firstD*100) - (t - firstD*100)%10)/10;
            thirdD = t - firstD*100 - secondD*10;

            while( firstD == 1 || firstD == 4 || firstD == 7 || secondD == 1 || secondD == 4 || secondD == 7 || thirdD == 1 || thirdD == 4 || thirdD == 7) {
                t1--;
                firstD = (t1 - t1%100)/100;
                secondD = ((t1 - firstD*100) - (t1 - firstD*100)%10)/10;
                thirdD = t1 - firstD*100 - secondD*10;
            };

            if(t1!=t) firstD =1;

            while( firstD == 1 || firstD == 4 || firstD == 7 || secondD == 1 || secondD == 4 || secondD == 7 || thirdD == 1 || thirdD == 4 || thirdD == 7) {
                t2++;
                firstD = (t2 - t2%100)/100;
                secondD = ((t2 - firstD*100) - (t2 - firstD*100)%10)/10;
                thirdD = t2 - firstD*100 - secondD*10;
            };

            if(t==t1 && t1 == t2) cout<<"The entered temperature ("<<t<<") is fine."<<endl;
            else
                cout << "The nearest two temperatures are "<<t2<<" and "<<t1<<"."<<endl;


        }
        else {
            cout << "please enter a valid temperature. ";
        }

        cout << "Enter 1 to start over or 0 to quit: ";
        cin >> loop;
        if (loop > 1) {
            loop = 1;
        }

    } while (loop);
return 0;}