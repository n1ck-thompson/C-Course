#include <iostream>
using namespace std;
int main() {
    int number_1, number_2;
    cout << "Press return after entering a number.\n";
    cout << "Enter your first number: \n";
    cin >> number_1;
    cout << "Enter your second number: \n";
    cin >> number_2;
    const int sum_1 = number_1 + number_2;
    cout << "The sum of the two numbers is: " << sum_1 << endl;
    const int prod_1 = number_1 * number_2;
    cout << "The product of the two numbers is : " << prod_1 << endl;
    return 0;
}
