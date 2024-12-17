#include <iostream>
#include <iomanip>
using namespace std;

double addCoin(int coin, double pTotal) {
    switch(coin) {
        case 1: return pTotal+1;
        case 2: return pTotal+.25;
        case 3: return pTotal+.1;
        case 4: return pTotal+.05;
    };
};

int main() {

    bool loop;
    do {
        int coin = 0;

        double total=0;

        while(total < 3.5) {
            cout<<"Enter your next coin. \n1 for a dollar, 2 for a quarter, 3 for a dime, and 4 for a nickel: ";
            cin>>coin;
            total = addCoin(coin, total);



        }
        double change = total - 3.5;
        cout<<"\nEnjoy your deep-fried twinkie\n";
        cout << fixed << setprecision(2) << change << " is your change.\n";
        cout << "enter 1 to continue or 0 to quit: ";
        cin >> loop;
    }while (loop);
    return 0;
}