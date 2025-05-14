#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
    char input[101];       // To store input (max 100 characters + null terminator)
    char output[101];      // To store the corrected sentence
    char choice;           // To store user's choice to continue
    do {
        int outIndex = 0;
        bool inSpace = false;

        cout << "Enter a sentence (up to 100 characters, ending with a period):\n";
        cin.getline(input, 101);

        int len = strlen(input);
        bool started = false;  // To track the first alphabetic character

        for (int i = 0; i < len; ++i) {
            char c = input[i];

            // Treat newline and spaces the same
            if (isspace(c)) {
                if (!inSpace && outIndex > 0) {
                    output[outIndex++] = ' ';
                    inSpace = true;
                }
            } else if (c == '.') {
                // Skip it; we'll add it ourselves at the end
                break;
            } else {
                // First real character: capitalize
                if (!started && isalpha(c)) {
                    output[outIndex++] = toupper(c);
                    started = true;
                } else {
                    output[outIndex++] = tolower(c);
                }
                inSpace = false;
            }
        }

        // Remove trailing space if present
        if (outIndex > 0 && output[outIndex - 1] == ' ') {
            outIndex--;
        }

        output[outIndex++] = '.'; // Add period
        output[outIndex] = '\0';  // Null-terminate the string

        cout << "Corrected sentence:\n" << output << endl;

        cout << "Do you want to enter another sentence? (y/n): ";
        cin >> choice;
        cin.ignore();  // Clear newline left in buffer

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
