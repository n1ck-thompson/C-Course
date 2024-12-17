#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int assignmentNumber = 0;
    int points(0);
    int totalPoints(0);

    cout<<"Enter the number of assignments: ";
    cin >> assignmentNumber;

    int i = 1; // used to loop for the number of assignments
    double tempPoints(0), tempTotalPoints(0);
    // temp variable are used to take in each individual score, then are added to total points to get an overall score
    while (i <= assignmentNumber) {
        cout<<"Enter the points for assignment " <<i<<endl;
        cin>>tempPoints;

        cout<<"Enter the total points for assignment "<<i<<endl;
        cin>>tempTotalPoints;

        points += tempPoints;
        totalPoints += tempTotalPoints;
        i++;
    }
    double temp2Points(points), temp2TotalPoints(totalPoints);

    cout <<fixed << cout.precision(2)<< "\n\n Your total grade for the class is " << points << " out of " << totalPoints << ", or " << 100 * (temp2Points/temp2TotalPoints) << "%. "<< endl;




    return 0;}
