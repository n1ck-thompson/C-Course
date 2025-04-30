#include <iostream>
using namespace std;
bool changeAndDisplay(char playingBoard[], char player, int selection) {
    playingBoard[selection-1] = player;

    for (int i = 0;i<3;++i) {
        for (int j = 0; j<3;++j) cout<<playingBoard[j+3*i]<<" ";
        cout<<"\n";
    };

    if (playingBoard[0] == playingBoard[1] &&playingBoard[1] == playingBoard[2]||
        playingBoard[3] == playingBoard[4] && playingBoard[4] == playingBoard[5]||
        playingBoard[6] == playingBoard[7] && playingBoard[7] == playingBoard[8]||
        playingBoard[0] == playingBoard [3]&& playingBoard[3] == playingBoard[6]||
        playingBoard[1] == playingBoard [4]&& playingBoard[4] == playingBoard[7]||
        playingBoard[2] == playingBoard [5]&& playingBoard[5] == playingBoard[8]||
        playingBoard[0] == playingBoard [4]&& playingBoard[4] == playingBoard[8]||
        playingBoard[2] == playingBoard [4]&& playingBoard[4] == playingBoard[6]) {

        cout<<"\nWinner: "<<player;
        return true;
    };

    cout<<"\n No winner yet.";
    return false;
};

int main() {
    char playingBoard[]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int selection = 0;

    cout<<"Board: \n";
    for (int i = 0;i<3;++i) {
        for (int j = 0;j<3;++j) cout<<playingBoard[j+3*i]<<" ";
        cout<<"\n";
    };

    cout<<"\n Player X, Enter a number to place X: ";
    cin>>selection;

    int counter = 1;

    while (!changeAndDisplay(playingBoard, 'X', selection)) {
        if (counter == 9) {
            cout<<"\nA draw";
            break;
        };

        cout<<"\nPlayer O, Enter a number to place O: ";
        cin>>selection;
        ++counter;

        if (changeAndDisplay(playingBoard, 'O', selection)) break;

        if (counter == 9) {
            cout<<"\nA draw";
            break;
        };

        cout<<"\nPlayer X, Enter a number to place X: ";
        cin>>selection;
        ++counter;
    };

    return 0;
}