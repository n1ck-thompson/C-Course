#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// String splitting utility
vector<string> split(const string& target, const string& delimiter) {
    vector<string> toBeReturned;
    size_t start = 0;
    size_t end = target.find(delimiter);
    while (end != string::npos) {
        toBeReturned.push_back(target.substr(start, end - start));
        start = end + delimiter.length();
        end = target.find(delimiter, start);
    }
    toBeReturned.push_back(target.substr(start));
    return toBeReturned;
}

// Extract data into structured format
vector<vector<vector<string>>> racersDataExtractor(const vector<string>& myFileLast9Lines) {
    vector<vector<vector<string>>> toBeReturned;
    for (size_t j = 0; j < 3; ++j) {
        toBeReturned.push_back(vector<vector<string>>());
        for (size_t i = 0; i < 3; ++i)
            toBeReturned[j].push_back(split(myFileLast9Lines[i + 3 * j], ","));

        if (j > 0) {
            vector<string> temp;
            for (size_t k1 = 0; k1 < 3; ++k1) {
                for (size_t k2 = 0; k2 < 3; ++k2) {
                    if (toBeReturned[j][k1][1] == toBeReturned[j - 1][k2][1]) {
                        temp = toBeReturned[j][k1];
                        toBeReturned[j][k1] = toBeReturned[j][k2];
                        toBeReturned[j][k2] = temp;
                    }
                }
            }
        }
    }
    return toBeReturned;
}

// Convert "H M S" string to minutes
double timeToMinutes(const string& timeStr) {
    vector<string> parts = split(timeStr, " ");
    return stod(parts[0]) * 60 + stod(parts[1]) + stod(parts[2]) / 60.0;
}

int main() {
    fstream myData("racers' data.dat", ios::in);
    if (!myData) {
        cout << "I couldn't find \"racers' data.dat\" in the current directory.\n";
        system("pause");
        exit(1);
    }

    string myFileString, nextLine;
    char next;
    while (myData.get(next)) myFileString += next;

    string startTime = myFileString.substr(0, myFileString.find("\n"));
    string dataLines = myFileString.substr(myFileString.find("\n") + 1);
    vector<string> dataLinesVect = split(dataLines, "\n");
    vector<vector<vector<string>>> racersData = racersDataExtractor(dataLinesVect);

    // Build a map of racer ID to overall race time
    vector<pair<string, double>> racerTimes;
    for (int i = 0; i < 3; ++i) {
        double start = timeToMinutes(racersData[0][i][2]);
        double end = timeToMinutes(racersData[2][i][2]);
        racerTimes.push_back({ racersData[0][i][1], end - start });
    }

    // Sort racers by total time (ascending)
    sort(racerTimes.begin(), racerTimes.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });

    // LOOP: allow multiple racer lookups
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        cout << "Enter the racer's ID: ";
        string racerID;
        cin >> racerID;

        int racerNumber = -1;
        for (size_t i = 0; i < 3; ++i)
            if (racersData[0][i][1] == racerID) racerNumber = i;

        if (racerNumber < 0) {
            cout << "\nInvalid ID.\n";
        } else {
            double startTimeMin = timeToMinutes(racersData[0][racerNumber][2]);
            double secondTimeMin = timeToMinutes(racersData[1][racerNumber][2]);
            double thirdTimeMin = timeToMinutes(racersData[2][racerNumber][2]);

            // Find overall place
            int overallPlace = -1;
            for (size_t i = 0; i < racerTimes.size(); ++i) {
                if (racerTimes[i].first == racerID) {
                    overallPlace = i + 1;
                    break;
                }
            }

            cout << "The racer's overall place is: " << overallPlace << "\n";
            cout << "Race split times in minutes/mile for split1 is "
                 << (secondTimeMin - startTimeMin) / 7
                 << "\nRace split times in minutes/mile for split2 is "
                 << (thirdTimeMin - secondTimeMin) / 6.1
                 << "\nThe overall race time (minutes) is "
                 << (thirdTimeMin - startTimeMin)
                 << "\nOverall race pace (minutes/mile) is "
                 << (thirdTimeMin - startTimeMin) / 13.1
                 << ".\n";
        }

        cout << "\nDo you want to check another racer? (y/n): ";
        cin >> choice;
    }

    return 0;
}
