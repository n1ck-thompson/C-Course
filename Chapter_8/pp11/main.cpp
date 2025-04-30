#include <string>
#include <iostream>
using namespace std;

string decrypt(const string& message, int key) {

    string toBeReturned{message};
    for (size_t i =0; i< message.size();++i) {
        if (static_cast<int>(message[i]) <32) toBeReturned[i] = static_cast<char>(static_cast<int>(message[i]) - key);
        else {
            toBeReturned[i] =
                static_cast<char>(static_cast<int>(message[i]) +95 -key);
            if (static_cast<int>(message[i]) + key <127) toBeReturned[i] = static_cast<char>(static_cast<int>(message[i]) -key);
        };
    };

    return toBeReturned;
};

int main() {
    for (size_t key = 1; key<101;++key)
        cout<<"key of number "<<key<<" result is:\t"<<decrypt(":mmZ\\dxZmx]Zpgy", key)<<"\n";
    return 0;
}