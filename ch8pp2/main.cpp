#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string line;
    char choice;

    do {
        int letterCount[26] = {0};
        int wordCount = 0;
        bool inWord = false;

        cout << "\nEnter a line of text:\n";
        getline(cin, line);

        for (char c : line) {
            if (isalpha(c)) {
                // Count letter (case-insensitive)
                letterCount[tolower(c) - 'a']++;

                // Word boundary logic
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else if (isspace(c) || c == ',' || c == '.') {
                inWord = false;  // End of word
            }
        }

        // Output results
        cout << "\n" << wordCount << " words\n";
        for (int i = 0; i < 26; ++i) {
            if (letterCount[i] > 0) {
                cout << letterCount[i] << " " << static_cast<char>('a' + i) << "\n";
            }
        }

        cout << "\nWould you like to enter another line? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer

    } while (tolower(choice) == 'y');

    cout << "Goodbye!\n";
    return 0;
}
