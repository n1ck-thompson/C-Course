#include <iostream>
using namespace std;

int main() {
    int weight(0), height(0), age(0);
    double bmr(0);
    char gender(' ');
    cout << "BMR Calculator" << endl;
    cout << "Enter your weight in pounds: " << endl;
    cin >> weight;
    cout << "Enter your height in inches: " << endl;
    cin >> height;
    cout << "Enter your age in years: " << endl;
    cin >> age;
    cout << "Enter your gender (M for male, F for female): " << endl;
    cin >> gender;
    if (gender == 'M') bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age); // formula for males

    else bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age); // formula for females

    bmr /= 230; //230 is the amount of calories in the average chocolate bar

    cout.precision(5); //makes program look tidier
    cout << "To maintain your current weight of" << weight <<  " you would need to eat " << bmr << " chocolate bars a day";
    return 0;
}
