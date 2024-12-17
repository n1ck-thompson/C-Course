#include <iostream>
using namespace std;

int computeDifference(
    int s_hours, int s_minutes, bool s_isAM,
    int f_hours, int f_minutes, bool f_isAM
    ) {
    int total_start_minutes = (
        s_hours!=12?s_hours*60:0
        ) + s_minutes;
    int total_future_minutes = (
        f_hours!=12?f_hours*60:0
        ) + f_minutes;

    int tot_min_in_24_hrs = 24*60;
    int diff=0;
    if(s_isAM==f_isAM) {
        diff = (
            (total_future_minutes-total_start_minutes)
            +tot_min_in_24_hrs
            )%tot_min_in_24_hrs;
    }
    else {
        diff = (
            12*60-total_start_minutes+
            total_future_minutes
            );
    }
    return diff;
}

int main() {
    bool loop;
    do {
        int s_hours, s_minutes, f_hours, f_minutes;
        bool s_isAM, f_isAM;
        char s_am_pm, f_am_pm;

        cout << "Start Time Details\n";
        cout << "Enter Hours: ";
        cin >> s_hours;
        cout << "\nEnter minutes: ";
        cin >> s_minutes;
        cout << "\nEnter A for AM, or P for PM: ";
        cin >> s_am_pm;

        cout << "\nFuture Time Details";
        cout << "\nEnter Hours: ";
        cin >> f_hours;
        cout << "\nEnter minutes: ";
        cin >> f_minutes;
        cout << "\nEnter A for AM, or P for PM: ";
        cin >> f_am_pm;

        if(s_am_pm=='A') s_isAM=true;
        else s_isAM=false;

        if(f_am_pm=='A') f_isAM=true;
        else f_isAM=false;

        cout << "Time Difference: ";
        cout << computeDifference(
            s_hours, s_minutes, s_isAM,
            f_hours, f_minutes, f_isAM
            ) <<" minutes." << endl;
        cout << "\n enter 1 to continue or 0 to quit: \n";
        cin >> loop;
    } while(loop);
    return 0;
}
