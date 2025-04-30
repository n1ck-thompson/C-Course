#include <iostream>
#include <string>
using namespace std;

string militaryHours(const string& ordinaryTime) {
    int hours = stoi(ordinaryTime.substr(0, ordinaryTime.find(':')));

    int minutes = stoi(ordinaryTime.substr(ordinaryTime.find(':')+1, ordinaryTime.find(' ') - ordinaryTime.find(':')-1));

    bool am = ordinaryTime.find("AM") < ordinaryTime.size();

    string toBeReturned;

    if (am&&hours<10) toBeReturned +="0"+to_string(hours);
    else if (am&&(hours==10||hours==11)) toBeReturned +=to_string(hours);
    else if (am&&(hours==12)) toBeReturned +="00";
    else toBeReturned +=to_string(hours+12);

    if (minutes<10) toBeReturned +="0"+to_string(minutes);
    else toBeReturned+=to_string(minutes);

    return toBeReturned+=" hours";
};

int main() {
    string ordinaryTime;

    cout<<"\nPlease enter your time in ordinary format ('2:30 PM'):\t";
    getline(cin, ordinaryTime);

    cout<<"\nThe military format of your time is: "<<militaryHours(ordinaryTime);

    return 0;
};