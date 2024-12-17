#include <iostream>
using namespace std;

void input(int&amount_left) {
    cout<<" Enter an amount of money between 1 and 99 cents to get it as quarters, dimes, and pennies:\t";



};
void compute_coins(int coin_value, int&num, int& amount_left) {
    num = (amount_left - amount_left%coin_value)/coin_value;
    amount_left%=coin_value;
};
void output(int& num, int& amount_left) {
    compute_coins(25, num, amount_left);
    cout <<" You have "<<num<<" Quarters,";
    compute_coins(10, num, amount_left);
    cout<<"\n "<<num<<" Dimes,";
    compute_coins(1, num, amount_left);
    cout<<"\n and "<<num<<" pennies.";

};

int main() {
    bool loop = true;
    int num = 0, amount_left = 0;
    do {
        input(amount_left);
        output(num, amount_left);

        cout<<"\n Enter 1 to start over or 0 to quit:\t";
        cin>>loop;
    } while(loop);
    return 0;
}
