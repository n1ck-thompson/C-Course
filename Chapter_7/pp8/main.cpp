#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void swapValues(int& value1, int& value2) {

    int temp;
    temp = value1;
    value1 = value2;
    value2 = temp;
};

void swapValues(char& value1, char& value2) {
    char temp;
    temp = value1;
    value1 = value2;
    value2 = temp;
}

int smallestValueIndex(const int a[], int start_index, int number_used) {
    int min = a[start_index],
    index_of_min = start_index;
    for (int index = start_index + 1; index < number_used; index++)
        if (a[index] < min) {
            min = a[index];
            index_of_min = index;
        }
    return index_of_min;
};

void sort(int a[], char charsArray[], int number_used) {
    int index_of_next_smallest;
    for (int index = 0; index < number_used - 1; index++) {
        index_of_next_smallest =
            smallestValueIndex(a, index, number_used);
        swapValues(a[index], a[index_of_next_smallest]);
        swapValues(charsArray[index], charsArray[index_of_next_smallest]);
    };
};

char charsArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
    bool loop=false;

    cout<<"enter 1 to begin. ";
    cin>>loop;
    do {
        char next;
        string txt;

        int userSelection=0;

        cout<<"\nTo enter your txt from a file enter 1 or 2 to write:\t";
        cin>>userSelection;

        if (userSelection == 1) {
            string fileName;
            cout<<"\nEnter the file name as 'my_file.txt'(no spaces):\t";
            cin>>fileName;

            fstream myFile (fileName, ios::in);
            if (!myFile) {
                cout<<"\nFile not found in directory. ";
                exit(1);
            };

            string temp;

            while (myFile) {
                myFile>>temp;
                if (myFile) txt += temp;
            };
        }
        else {
            cout<<"\nEnter your text (lowercase only)\nAfter entering text, enter any number to finish:\t";
            cin.get(next);
            while (!isdigit(next)) {
                txt+=next;
                cin.get(next);
            };
            cin.ignore();
        };

        int statistics[26]={0};

        for (int i=0; i <26; i++) {
            for (int j=0; j <txt.size(); ++j) {
                if (charsArray[i] == txt[j]) ++statistics[i];
            };
        };

        sort(statistics, charsArray, 26);
        cout<<"--------------------------------------\n";
        cout<<"| Letter || Number of Appearances ||\n";
        cout<<"--------------------------------------\n";

        for (int i=25;(i>=0&&statistics[i]!=0);--i) {
            cout<<"| "<<setw(3)<<charsArray[i]<<"    ||  "<<setw(10)<<statistics[i]<<setw(13)<<"  |\n";
        };
        cout<<"--------------------------------------\n";

        cout<<"\nPress 1 to continue or 0 to quit. ";
        cin>>loop;
    }while (loop);

    return 0;
}