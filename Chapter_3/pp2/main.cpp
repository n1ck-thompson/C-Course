#include <iostream>
#include<cmath> // used for sqrt function
using namespace std;

int main() {

    double a(0), b(0), c(0); // coefficient of x^2, x^1, and x^0, respectively
    double discriminant(0);
    bool loop; //boolean to control loop
    double r1(0);
    double r2(0);
    double real_part(0);
    double imaginary_part(0);


    do {
        cout << "Enter the values of a, b, and c, then press enter: ";
        cin >> a >> b >> c;

        if (b*b >= 4*a*c) { //real roots case
            discriminant = b*b - 4*a*c;
            if (discriminant < 0) {
                discriminant *= -1;
            }
            discriminant == sqrt(discriminant);

            if (discriminant == 0)
                cout<<"The root is "<<-b/(2*a) << endl;
            else
                cout << "The two roots are: "<<(-b + discriminant)/(2*a)<< " and "<<(-b - discriminant)/(2*a) << endl;
        }
        else
            discriminant = (b*b - 4*a*c);
            if (discriminant < 0) {
                discriminant *= -1;
            }
            discriminant == sqrt(discriminant);

            if(-b/(2*a) != 0) {

                real_part = (-b/(2*a));
                imaginary_part = (discriminant/(2*a));
                //r2 = (b/(2*a))-(discriminant/(2*a));


                cout <<"The two complex roots are: "<< real_part << " + " << imaginary_part <<
                " * i and " << real_part <<" - "<< imaginary_part << " * i "<< endl;
            }

            else {
                r1 = discriminant/(2*a);
                r2 = discriminant/(2*a);
                cout << discriminant << endl
                << "The two complex roots are: "<< r1 << " * i" << " and " << r2 << " * -i"<< endl;
            };



        cout << "enter 1 to start over or 0 to quit ";
        cin >> loop;
    }
    while(loop);

    return 0;
}
