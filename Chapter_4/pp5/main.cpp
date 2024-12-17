#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double BMR(double weight) {
    return 70 * pow((weight / 2.2),0.756);
}

double physicalActivityCal(int intensity, double weight, int minutes) {
    return 0.0385 * intensity * weight * minutes;
}

int main() {
    double weight, servingCals;
    int intensity=0, minutes=0;


    cout << "Enter your weight in pounds: ";
    cin >> weight;

    cout<<"\nHere are some sample values for intensity" << endl <<
        "Activity: Intensity" << endl <<
            "Running 10 MPH: 17" << endl <<
                "Running 6 MPH: 10" << endl <<
                    "Playing Basketball: 8" << endl <<
                        "Walking 1 MPH: 1" << endl;
    cout << "Enter an estimated intensity for your activity: ";
    cin >> intensity;

    cout << "Enter the number of minutes that you spent exercising: ";
    cin >> minutes;
    cout << "\nEnter the estimated caloric content in one serving of your favorite meal: ";
    cin >> servingCals;

    double consumedCals = BMR(weight) + physicalActivityCal(intensity, weight, minutes);


    double neededCals = consumedCals + (servingCals * 0.1);
    double neededServings = neededCals/servingCals;
    cout << fixed << setprecision(3) << "\nYou need " <<neededServings << " servings of your favorite food to sustain yourself. ";
    neededCals = 0;
    neededServings = 0;
    return 0;
}