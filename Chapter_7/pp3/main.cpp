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
    char a[10];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'a';
    a[3] = 'c';
    int size = 4;
    delete_repeats(a,size);
    cout<<"after applying the function {'a', 'b', 'a', 'c'} is an array of size "<<size<<" and its values are {";
    for (int i=0; i<size; ++i) cout<<a[i];
    cout<<"}.";

};