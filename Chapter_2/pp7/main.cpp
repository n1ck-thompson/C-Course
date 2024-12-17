#include <iostream>
using namespace std;

int main() {
    double interest(0);
    double years, price, years2;
    cout << "200 Pencil Price Calculator" << endl << "Enter the current price of 200 pencils" << endl;
    cin >> price;
    cout << "enter the inflation rate you would like to have" << endl;
    cin >> interest;
    interest/=100;
    cout << "Enter how many years in the future you want to see the price" << endl;
    cin >> years;
    cout  << "Confirm how many years in the future you want to see the price" << endl;
    cin >> years2;
    while (years > 0) {
        price += (price * interest);
        years--;
    }
    cout.precision(3);
    cout << "In " << years2 << " years, 200 pencils will cost $" << price << endl;
    return 0;
}
