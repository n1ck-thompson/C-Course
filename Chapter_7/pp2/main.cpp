#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void getHexad10(istream& stream, char charArray[], int size=10) {
    //used to get inputs
    string temp;
    stream >> temp;
    for (int index = 0; index<size;++index ) charArray[index] = temp[index];
};

void convertCharToInt(char charArr[], int intArr[], int size=10) {
    //converts characters to integers

    for (int index = 0; index < size; ++index) {
        if (charArr[index] == '0') intArr[index] = 0;
        else if (charArr[index] == '1') intArr[index] = 1;
        else if (charArr[index] == '2') intArr[index] = 2;
        else if (charArr[index] == '3') intArr[index] = 3;
        else if (charArr[index] == '4') intArr[index] = 4;
        else if (charArr[index] == '5') intArr[index] = 5;
        else if (charArr[index] == '6') intArr[index] = 6;
        else if (charArr[index] == '7') intArr[index] = 7;
        else if (charArr[index] == '8') intArr[index] = 8;
        else if (charArr[index] == '9') intArr[index] = 9;
        else if (charArr[index] == 'a') intArr[index] = 10;
        else if (charArr[index] == 'b') intArr[index] = 11;
        else if (charArr[index] == 'c') intArr[index] = 12;
        else if (charArr[index] == 'd') intArr[index] = 13;
        else if (charArr[index] == 'e') intArr[index] = 14;
        else if (charArr[index] == 'f') intArr[index] = 15;
        else {
            cout<<"\nInvalid argument when converting characters to integers";
            exit(1);
        };
    };
};

bool sum2ArraysAsIf2Numbers(int intArr1[], int intArr2[], int sum[], int size=10) {

    int mind = 0;

    for (int index = size-1; index >=0;--index) {
        sum[index] = intArr1[index] + intArr2[index] + mind;

        mind = sum[index]/16;
        sum[index] = sum[index]%16;
    };
    if (mind == 0) return true;

    return false;
}

void convertIntToHexadChars (int intArr[], char charArr[], int size=10) {

    for (int index = 0; index < size;++index) {
        if (intArr[index] ==0) charArr[index] = '0';
        else if (intArr[index] == '1') charArr[index] = '1';
        else if (intArr[index] == '2') charArr[index] = '2';
        else if (intArr[index] == '3') charArr[index] = '3';
        else if (intArr[index] == '4') charArr[index] = '4';
        else if (intArr[index] == '5') charArr[index] = '5';
        else if (intArr[index] == '6') charArr[index] = '6';
        else if (intArr[index] == '7') charArr[index] = '7';
        else if (intArr[index] == '8') charArr[index] = '8';
        else if (intArr[index] == '9') charArr[index] = '9';
        else if (intArr[index] == '10') charArr[index] = 'a';
        else if (intArr[index] == '11') charArr[index] = 'b';
        else if (intArr[index] == '12') charArr[index] = 'c';
        else if (intArr[index] == '13') charArr[index] = 'd';
        else if (intArr[index] == '14') charArr[index] = 'e';
        else if (intArr[index] == '15') charArr[index] = 'f';
        //else {
            //cout<<"\nInvalid argument when converting integers to hexadecimal characters";
            //exit(1);
        //};
    };
};

int main() {
    char char1[10]={'0'};
    char char2[10]={'0'};
    int int1[10]={0};
    int int2[10]={0};
    int intResult[10]={0};
    char charResult[10]={'0'};

    bool loop;

    do {

        cout<<"\nEnter the first 10 digit hex number:\t";
        getHexad10(cin, char1, 10);

        cout<<"\nEnter the second 10 digit hex number:\t";
        getHexad10(cin, char2, 10);

        convertCharToInt(char1, int1);
        convertCharToInt(char2, int2);

        if (sum2ArraysAsIf2Numbers(int1, int2, intResult)) {
            convertIntToHexadChars(intResult, charResult);
            cout<<"\nThe addition result is ";
            for (char element:charResult)cout<<element;
        }else cout<<"\nAddition overflow";

        cout<<"\n To continue, enter 1; otherwise, enter 0:\t";
        cin>>loop;
    }while (loop);
    return 0;

}