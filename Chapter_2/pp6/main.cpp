#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    bool loop = true; // boolean for looping function


    float numHours(0); // number of hours worked in a week (set to zero to prevent errors)
    int numDependents(0); // number of dependents (also set to zero to prevent errors)

    float grossPay(0); // gross pay; set as a float as opposed to a double to prevent errors if decimal place is larger
    float socialSecurity(0);
    float federalTax(0);
    float stateTax(0);
    float unionDues(10);
    float healthInsurance(0);
    float netPay(0);

    const float normalPay = 16.78f; // rate of pay during normal 40 hour week
    const float overtime =  normalPay*1.5f;// overtime pay


    while(loop) {
        cout<<"Enter the number of hours you worked this week: ";
        cin>>numHours;
        cout<<"Enter the number of dependents you have: ";
        cin>>numDependents;

        if (numHours>40) grossPay = 40*normalPay+(numHours-40)*overtime;
        else grossPay = numHours*normalPay;




        socialSecurity = 0.06f*grossPay;
        federalTax = 0.14f*grossPay;
        stateTax = 0.05f*grossPay;
        if (numDependents>=3) healthInsurance = 35;
        else healthInsurance = 0;

        netPay = (((((grossPay - socialSecurity) - federalTax) - stateTax) - unionDues) - healthInsurance);
        cout << fixed << setprecision(2) <<
        "Gross Pay: $" << grossPay << endl
        <<"Social Security: $" << socialSecurity << endl
        <<"Fed Tax: $" << federalTax << endl
        <<"State Tax: $" << stateTax << endl
        <<"Union Dues: $" << unionDues << endl
        << "Health Insurance: $" << healthInsurance << endl
        <<"Net Pay: $" << netPay << endl;

        cout<<"Enter 1 to start over or 0 to quit: ";
        cin>>loop;

    }

return 0;}