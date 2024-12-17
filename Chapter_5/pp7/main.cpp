#include <iostream>
#include <string>
using namespace std;

bool isLeapYear (int year) {
    return year%400 == 0 || (year%4==0 && year%100!= 0);
};

int getCenturyValue( int year) {
    return 2*(3 - (year/100)%4);
};
int getYearValue(int year) {
    return (year - 100*(year/100))/4 + year - 100 * (year/100);
};
int getMonthValue(int month, int year) {
    switch(month) {
        case 1: if (isLeapYear(year)) return 6; return 2;
        case 2: if (isLeapYear(year)) return 2; return 3;
        case 3: return 3;
        case 4: return 6;
        case 5: return 1;
        case 6: return 4;
        case 7: return 6;
        case 8: return 2;
        case 9: return 5;
        case 10: return 0;
        case 11: return 3;
        case 12: return 5;
    };
};
void getInputes(int& day, int & month, int &year) {
    string temp;
    cout << "Enter the date as DD MM YYYY.\nIf you prefer to enter the date as DD Month YYYY, type 0 and press enter:\t";
    cin >> day;

    if (day == 0) {
        cout<<"Enter the date as DD Month YYYY, then press enter:\t";
        cin>>day>>temp>>year;

        string subTemp = temp.substr(0,2);
        if (subTemp=="Ja"||subTemp=="ja") month =1;
        if (subTemp=="Fe" || subTemp=="fe") month =2;
        if (subTemp=="March"||temp=="march") month =3;
        if (subTemp=="Ap"||"ap") month =4;
        if (subTemp=="May"||"may") month =5;
        if (subTemp=="June"||"june") month=6;
        if (subTemp=="July"||"july") month=7;
        if (subTemp=="Au"||"au") month =8;
        if (subTemp=="Se"||"se") month =9;
        if (subTemp=="Oc"||"oc") month =10;
        if (subTemp=="No"||"no") month =11;
        if (subTemp=="De"||"de") month =12;
    }
    else cin>>month>>year;
};

int main() {
    bool loop;
    do {
        int day = 0, month =0, year = 0;
        getInputes(day, month, year);
        int theDayNumber = (day + getCenturyValue(year) + getYearValue(year) + getMonthValue(month, year))%7;
        cout<<"\nThe corresponding day to this date is:\t";
        switch(theDayNumber) {
            case 0: cout<<"Sunday";break;
            case 1: cout<<"Monday";break;
            case 2: cout<<"Tuesday";break;
            case 3: cout<<"Wednesday";break;
            case 4: cout<<"Thursday";break;
            case 5: cout<<"Friday";break;
            case 6: cout<<"Saturday";break;
        };
        cout << "\n enter 1 to continue or 0 to quit: \n";
        cin>>loop;
    } while (loop);
    return 0;
}
