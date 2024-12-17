#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int number_of_quarters, number_of_dimes, number_of_nickels;
    cout << "please press return after entering each value\n";
    cout << "enter your number of quarters\n";
    cin >> number_of_quarters;
    float quarters_value = number_of_quarters * 0.25;
    cout << "enter your number of dimes\n";
    cin >> number_of_dimes;
    float dimes_value = number_of_dimes * 0.1;
    cout << "enter your number of nickels\n";
    cin >> number_of_nickels;
    float nickels_value = number_of_nickels * 0.05;
    float total_value = quarters_value + dimes_value + nickels_value;
    cout << fixed << setprecision(2) << "the total value of your coins is : " << total_value << " dollar(s)" << endl;
    return 0;
}
