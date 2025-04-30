#include<iostream>
using namespace std;
void delete_repeats(char array[], int &size) {

    for (int i = 0;i <size;++i) {
        for (int j = 0;j<size;++j) {
            if (i==j) continue;
            if (array[i] == array[j]) {
                for (int k=j; k<size-1;++k) {
                    array[k] = array[k+1];
                };
                --size;
                --j;}
        };
    };
};

int main() {
    char a[12];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'a';
    a[3] = 'c';
    a[4] = 'd';
    a[5] = 'b';
    a[6] = 'e';
    a[7] = 'c';
    a[8] = 'a';
    a[9] = 'b';
    a[10] = 'e';
    a[11] = 'f';

    int size = 12;

    cout<<"The original array is {"; for (int i=0; i<size; i++) cout<<a[i]; cout<<"}. After applying the function the array is of size ";
    delete_repeats(a,size);
    cout<<size<<" and its values are {";
    for (int i=0; i<size; ++i) cout<<a[i];
    cout<<"}.";

};