#include <iostream>
using namespace std;

int main() {

    int possum = 0, negsum = 0, numholder = 0;
    int counter = 1 ;

    cout << "10 number calculator" << endl << "press enter after each number: "<< endl;
    while(counter < 11) {
        counter += 1;
        cin >> numholder;
        if (numholder > 0) possum += numholder;

        else negsum += numholder;
    }
    cout << "the sum of all positive numbers: " << possum << endl
    << "the sum of all negative numbers: " << negsum << endl
    << "the sum of all numbers: " << possum + negsum << endl;

    return 0;
}
