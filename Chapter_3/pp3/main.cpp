#include <iostream>
using namespace std;

int main()
{

    int arabicYear; // year that will be converted
    bool loop; //boolean to control loop

    do {

        cout << "Enter a four digit Arabic year to convert into roman numerals: ";
        cin >> arabicYear;


        //defining ints to get each digit from user input
        int thousandsDigit = arabicYear - arabicYear%1000;
        int hundredsDigit = (arabicYear - arabicYear%100)-thousandsDigit;
        int tensDigit = (arabicYear-arabicYear%10)-thousandsDigit-hundredsDigit;
        int onesDigit = arabicYear - thousandsDigit - hundredsDigit - tensDigit;

        //displays the thousands digit in roman numerals

        for (int i = 1;i<=thousandsDigit/1000;i++) cout<<"M";

        int temp(0);//used for loop

        switch(hundredsDigit) {
            case 100:
            case 200:
            case 300:
                temp = hundredsDigit/100;
                while (temp > 0) {cout<<"C";temp--;};
                break;
            case 400: cout<<"CD";break;
            case 500:
            case 600:
            case 700:
            case 800:
                cout<<"D";
                temp =hundredsDigit/100 -5;
                while (temp > 0) {cout<<"C"; temp--;};
                break;
            case 900: cout<<"CM";
        }

        switch(tensDigit) {
            case 10:
            case 20:
            case 30:
                temp =tensDigit/10;
                while (temp > 0) {cout<<"X";temp--;};
                break;
            case 40: cout<<"XL";break;
            case 50:
            case 60:
            case 70:
            case 80:
                cout<<"L";
                temp =tensDigit/10 -5;
                while (temp > 0) {cout<<"X";temp--;};
                break;
            case 90: cout<<"XC";
        }

        switch(onesDigit) {

            case 1:
                break;
            case 2:
                break;
            case 3:
                temp =onesDigit;
                while (temp > 0) {cout<<"I";temp--;};
                break;
            case 4: cout<<"IV";break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                cout<<"V";
                temp =onesDigit -5;
                while (temp >0) {cout<<"I";temp--;};
            case 9: cout<<"IX";
        }
        cout << endl;
        cout << "Enter 1 to start over or 0 to exit: ";
        cin >> loop;
    }
    while(loop);

    return 0;
}
