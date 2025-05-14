#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Function to convert 12-hour time string to 24-hour military format
string convertToMilitaryTime(const string& timeStr) {
    int hour, minute;
    char colon, space;
    string meridian;

    istringstream iss(timeStr);
    iss >> hour >> colon >> minute >> meridian;

    // Convert to uppercase (just in case user types "am" or "pm")
    for (char &c : meridian) c = toupper(c);

    if (meridian == "AM") {
        if (hour == 12) hour = 0; // 12 AM is 00
    } else if (meridian == "PM") {
        if (hour != 12) hour += 12;
    }

    // Format with leading zeros
    ostringstream oss;
    oss << setw(2) << setfill('0') << hour
        << setw(2) << setfill('0') << minute
        << " hours";

    return oss.str();
}

int main() {
    string input;
    char choice;

    do {
        cout << "\nEnter a time in 12-hour format (e.g., 1:10 AM or 11:30 PM): ";
        getline(cin, input);

        string militaryTime = convertToMilitaryTime(input);
        cout << "Military time: " << militaryTime << endl;

        cout << "Would you like to convert another time? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear newline character from buffer

    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended." << endl;
    return 0;
}
