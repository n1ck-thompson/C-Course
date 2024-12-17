#include <iostream>
using namespace std;
int main()
{
    int max_room_capacity, meeting_attendees;
    char response;
    cout << "Meeting room calculator. Enter y to begin" << endl;
    cin >> response;
    do {
        cout << "How many people will attend your meeting?" << endl;
        cin >> meeting_attendees;
        cout << "What is the capacity of your room?" << endl;
        cin >> max_room_capacity;
        if (meeting_attendees > max_room_capacity)
            cout << "Maximum room capacity is exceeded!" << endl << meeting_attendees - max_room_capacity << " people must be removed to continue." << endl;
        else
            cout << "Meeting can be held!" << endl << max_room_capacity - meeting_attendees << " more people may attend." << endl;
        cout << "Do you want to continue? (y = yes, n = no)" << endl;
        cin >> response;
    } while (response == 'y');
    return 0;
}
