#include <iostream>
#include <cmath> //used for pow function
using namespace std;

int main() {

    int n; //order of approximation
    bool loop; //boolean to control loop

    do {
        cout << "Enter the value of n that determines the number of terms in the approximation to get PI approximation: ";
        cin >> n;

        double pi = 0;

        int i=0;

        while ( i <= n) {
            pi+=4 * pow(-1,i)/(2*i + 1);
            i++;
        };
        cout << "PI is " <<pi << endl;

        cout << "Enter 1 to start over or 0 to quit: ";
        cin >> loop;
    } while (loop);
    return 0;
}
