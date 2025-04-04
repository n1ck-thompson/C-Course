#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int PIN_SIZE = 5;
int originalPIN[]={9, 9, 3, 4, 5};

int getIndex(int array[], int size, int target ,int exclude = -1) {
    for (int index = 0; index<size;++index)
        if (index!=exclude && target==array[index]) return index;
    return INT_MIN;
};

int main() {
    srand(100000*time(0));
    int displayedNum[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    int enteredNum[5];
    for (int index=0;index<10;++index) {
        displayedNum[index] = rand()%10;
    };

    cout<<"PIN:\t"; for (int index=0;index<10;++index)cout<<setw(3)<<index;
    cout<<"\nNUM:\t"; for (int element : displayedNum) cout<<setw(3)<<element;

    cout<<"\n Enter your PIN:\t";

    for (int index=0;index<PIN_SIZE;++index) cin>>enteredNum[index];

    int test = 0;

    for (int index=0; index <PIN_SIZE; ++index)
        if (getIndex(displayedNum, 10, enteredNum[index])==originalPIN[index])
            ++test;

    if (test==PIN_SIZE)cout<<"\nCorrect!";
    else cout<<"\nWrong! Try again.";

    return 0;

};