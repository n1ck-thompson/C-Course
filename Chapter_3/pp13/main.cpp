#include <iostream>
using namespace std;

int main() {
    int number = 1000;
    int thd = int(number/1000.0);
    int hd = int(number/100.0)-10*thd;
    int ted = int(number/10.0)-10*hd-100*thd;
    int od = number%10;

    while(!
        ((thd!=hd&&thd!=ted&&thd!=od&&hd!=ted&&hd!=od&&ted!=od)&&(thd == 3 * ted)&&(number%2 == 1)&&(thd+hd+ted+od == 27))){

        number++;

        thd = int(number/1000.0);
        hd = int(number/100.0)-10*thd;
        ted = int(number/10.0)-10*hd-100*thd;
        od = number%10;
    };

    cout<<"The number is: "<<number << endl;
    cout << thd << endl;
    cout << hd << endl;
    cout << ted << endl;
    cout << od << endl;
    return 0;
}