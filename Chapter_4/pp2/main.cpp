#include <iostream>
using namespace std;

double hatSize(double height, double weight) {

    return 2.9*weight/height;
};

double jacketSize(double height, double weight, double age) {
    double jacketSize = height*weight/288;
    if (age < 40)
        return jacketSize;
    else
        return jacketSize + 1.0/8 * int((age - 30)/10);
};

double waist(double weight, double age) {
    double waist = weight/5.7;
    if (age < 30)
        return waist;
    else
        return waist + 1.0/10 * int((age - 28)/2);
};

int main( ) {
    double height, weight, age;
    bool loop;

    do {
        cout<<"Enter your height in inches, your weight in pounds, and your age in years: ";
        cin>>height>>weight>>age;

        cout<<"\nYour hat size is "<<hatSize(height, weight)<<" inches. " << endl <<
            "Your jacket size is " << jacketSize(height,weight,age)<<" inches." << endl <<
                "Your waist size is "<<waist(weight,age) <<" inches." << endl;

        cout<<"\nEnter 1 to start over or 0 to quit: "<< endl;
        cin>>loop;
    } while (loop);
    return 0;
}