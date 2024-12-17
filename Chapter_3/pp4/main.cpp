// In this question we have to write a program that scores a blackjack hand

#include <iostream>

using namespace std;

int main() {
    // Here no_of_cards is an integer variable to store number of cards user has
    int no_of_cards;

    // Here n is an integer variable used to run while loop
    int n = 1;

    // score is defined to store the total sum of the cards
    int score = 0;

    // i is defined to store the points of a card from the character input given by the user
    int i = 0;

    // ace is defined to store the number of aces
    int ace = 0;

    int a = 0;

    cout << "\n\t\tBLACKJACK HAND GAME";
    cout << "\n\nINSTRUCTIONS:";
    cout << "\n-ACE: A/a\n-JACK: j/J\n-QUEEN: q/Q\n-KING: k/K\n-10: t/T\n-2 to 9: 2-9";




    do {
        int score = 0; //resets all of  ints defined earlier so score doesn't roll over from previous attempt
        int i = 1;
        int ace = 0;
        cout << "\n\nEnter number of cards?: ";
        cin >> no_of_cards;

        if (no_of_cards >=3 && no_of_cards <= 5 ) {
            while (n <= no_of_cards) {
                // Defining a character variable to store the value of card given by the user
                char c1;
                cout << "\n\n Enter value of card " << n << " :";
                cin >> c1;


                // Comparing the value of input data given by user with 2 3 4 5 6 7 8 9
                if ((c1 == '2') || (c1 == '3') || (c1 == '4') || (c1 == '5') ||
                    (c1 == '6') || (c1 == '7') || (c1 == '8') || (c1 == '9')) {
                    // **IMPORTANT**
                    // The formula used below is used for converting a single character input into integer
                    i = c1 - 48;


                    score = score + i;
                    }


                if ((c1 == 'j') || (c1 == 'J') || (c1 == 'q') || (c1 == 'Q') ||
                    (c1 == 'k') || (c1 == 'K') || (c1 == 't') || (c1 == 'T')) {
                    // Assigning these 10 points
                    i = 10;

                    // Incrementing score by i
                    score = score + i;
                    }

                // Checking if the card is ace
                if ((c1 == 'a') || (c1 == 'A')) {
                    // Incrementing ace by one in order to count the total number of aces
                    // Here, we are not directly adding value of ace to the score as we have another condition for the ace(s)
                    ace++;
                }

                // Incrementing n by one
                n++;
            }

            // As we know, the ace can count as either 1 or 11, whichever is better for the user
            // We have to consider the number of aces

            // If the number of aces is equal to one
            if (ace == 1) {
                // If number of aces is one and the score is greater than 11 then the program will count ace as 1
                // If we instead count it as 11 then the score will jump over 21 which is not suitable for the user
                // eg. if score is 12, 12+11=23 is worse off than 12+1=13
                if (score >= 11) {
                    score = score + 1;
                }
                // For rest of the values of the score, i.e. below 11, the program will count ace as 11
                // As we know having the score closer to 21 is favourable for the user
                //
                else {
                    score = score + 11;
                }
            }

            // Now, if user has 2 aces
            if (ace == 2) {

                if (score > 9) {
                    // Here, 2 (=1+1) will be the points for the two aces
                    score = score + 2;
                }
                // For rest of the values of score, i.e. below 12, we will count one ace as 11 and one ace as 1
                // As we know having the score closer to 21 is favourable for the user
                // eg. If score is 5, 5+11+1=17 (favourable) whereas 5+11+11=27 (unfavourable)
                else {
                    // Here, 12 (=11+1) are the total points for the two aces
                    score = score + 12;
                }
            }

            // Now, if we have 3 aces
            if (ace == 3) {
                // If number of aces is three and the score is greater than 8 then we will count all the three
                // aces as 1 each
                // if we count it as 11 then our score will jump over 21 which is not suitable for the user
                if (score > 8) {
                    // Here, 3 (=1+1+1) is the sum of points of all three aces
                    score = score + 3;
                }
                // For rest of the values of score, i.e. below 8, we will count one ace as 11 and other two aces as 1
                // As we know having the score closer to 21 is favourable for the user
                // eg. If score is 5, 5+11+1+1=18 (favourable) whereas 5+11+11+1=28 (unfavourable)
                else {
                    // Here 13 is of one ace counted as 11 and other two as 1
                    score = score + 13;
                }
            }

            // Now, if we have 4 aces
            if (ace == 4) {
                // If number of aces is four and the score is greater than 7 then we will count all the four
                // aces as 1 each
                // if we count any of the aces as 11, then our score will jump over 21 which is not suitable for the user
                // eg. for score=10, 10+1+1+1+1=14 (favourable) whereas 10+11+1+1+1=24 (unfavourable)
                if (score > 7) {
                    // Here, 4 is the sum of points of all four aces
                    score = score + 4;
                }
                // For rest of the values of score, i.e. below 7, we will count one ace as 11 and other three aces as 1
                // As we know having the score closer to 21 is favourable for the user
                // eg. If score is 5, 5+11+1+1+1=19 (favourable) whereas 5+11+11+1+1=29 (unfavourable)
                else {
                    // Here, 14 (=11+1+1+1) is the sum of points of 1 ace counted as 11 and other as 1
                    score = score + 14;
                }
            }

            // Checking if the score is more than 21
            // And if it is more than 21 telling the user that he is busted
            if (score > 21) {
                // Printing the score on the screen
                cout << "\n\nYOUR SCORE IS : " << score;
                cout << "\n--*BUSTED*--";
            }
            // else just printing the score
            else {
                cout << "\n\n\nYOUR SCORE IS : " << score;
            }

            // Asking the user if he wants to try again

        }
        else {
            cout << "\n\nToo many/too few cards, please pick a value between 3 and 5";
        };

        cout << "\n\n\tPRESS 1 TO TRY AGAIN";
        cout << "\n\tPRESS 2 TO EXIT";
        cin >> n;


        if (n == 2) {
            break;
        };



    } while (n == 1);

    return 0;
}

