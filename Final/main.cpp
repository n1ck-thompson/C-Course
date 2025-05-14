#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

const int MAX_RECIPES = 100;

struct Recipe {
    string name;
    string ingredients;
    string instructions;
    //string imagePath;
};
void generateVolumeComparisonSVG() {
    ofstream svgFile("volume_comparison.svg");
    if (!svgFile) {
        cerr << "Error creating SVG file.\n";
        return;
    }

    // Start SVG
    svgFile << "<svg width=\"300\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">\n";

    // Title
    svgFile << "<text x=\"10\" y=\"20\" font-size=\"16\" font-family=\"Arial\">Volume Comparison</text>\n";

    // Labels
    svgFile << "<text x=\"10\" y=\"60\" font-size=\"14\" font-family=\"Arial\">Teaspoon (5 mL)</text>\n";
    svgFile << "<text x=\"10\" y=\"120\" font-size=\"14\" font-family=\"Arial\">Tablespoon (15 mL)</text>\n";

    // Teaspoon bar (scaled to 5 mL)
    svgFile << "<rect x=\"150\" y=\"45\" width=\"50\" height=\"20\" fill=\"skyblue\" />\n";

    // Tablespoon bar (scaled to 15 mL)
    svgFile << "<rect x=\"150\" y=\"105\" width=\"150\" height=\"20\" fill=\"orange\" />\n";

    // End SVG
    svgFile << "</svg>\n";
    svgFile.close();

    cout << "SVG file 'volume_comparison.svg' generated successfully.\n";
}


void displayMenu() {
    cout << "\n--- Recipe Book Menu ---\n";
    cout << "1. Add a new recipe\n";
    cout << "2. View all recipes\n";
    cout << "3. Search for a recipe by name\n";
    cout << "4. Save recipes to file\n";
    cout << "5. Load recipes from file\n";
    cout << "6. Exit\n";
    cout << "7. Show tablespoon vs teaspoon graph\n";
    cout << "Enter your choice: ";
}

void toLowerCase(std::string& str) {
    for (char& c : str) c = tolower(c);
}

int main() {
    Recipe recipes[MAX_RECIPES];
    int recipeCount = 0;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        if (choice == 1) {
            if (recipeCount >= MAX_RECIPES) {
                cout << "Recipe book is full!\n";
                continue;
            }

            cout << "Enter recipe name: ";
            getline(cin, recipes[recipeCount].name);

            cout << "Enter ingredients (comma-separated): ";
            getline(cin, recipes[recipeCount].ingredients);

            cout << "Enter instructions: ";
            getline(cin, recipes[recipeCount].instructions);

            //cout << "Enter image path: ";
            //getline(cin, recipes[recipeCount].imagePath);

            cout << "Recipe added successfully!\n";
            recipeCount++;
        }
        else if (choice == 2) {
            if (recipeCount == 0) {
                cout << "No recipes to show.\n";
            } else {
                for (int i = 0; i < recipeCount; ++i) {
                    cout << "\nRecipe " << (i + 1) << ":\n";
                    cout << "Name: " << recipes[i].name << "\n";
                    cout << "Ingredients: " << recipes[i].ingredients << "\n";
                    cout << "Instructions: " << recipes[i].instructions << "\n";
                }
            }
        }
        else if (choice == 3) {
            string searchName;
            cout << "Enter recipe name to search: ";
            getline(cin, searchName);
            toLowerCase(searchName);

            bool found = false;
            for (int i = 0; i < recipeCount; ++i) {
                string lowerName = recipes[i].name;
                toLowerCase(lowerName);
                if (lowerName.find(searchName) != string::npos) {
                    cout << "\nFound Recipe:\n";
                    cout << "Name: " << recipes[i].name << "\n";
                    cout << "Ingredients: " << recipes[i].ingredients << "\n";
                    cout << "Instructions: " << recipes[i].instructions << "\n";
                    //cout << "Image Path: " << recipes[i].imagePath << "\n";
                    //char viewImg;
                    //cout << "view image? (y/n): ";
                    //cin >> viewImg;
                    //cin.ignore();
                    //if (tolower(viewImg) == 'y') {
                        //displayImage(recipes[i].imagePath);
                    //}
                    found = true;
                }
            }
            if (!found) {
                cout << "No recipe found with that name.\n";
            }
        }
        else if (choice == 4) {
            ofstream file("recipes.txt");
            if (!file) {
                cerr << "Error opening file for writing.\n";
                continue;
            }

            for (int i = 0; i < recipeCount; ++i) {
                file << recipes[i].name << "\n";
                file << recipes[i].ingredients << "\n";
                file << recipes[i].instructions << "\n";
                file << "---\n"; // Delimiter
            }
            file.close();
            cout << "Recipes saved to recipes.txt\n";
        }
        else if (choice == 5) {
            ifstream file("recipes.txt");
            if (!file) {
                cerr << "Error opening file for reading.\n";
                continue;
            }

            recipeCount = 0;
            while (getline(file, recipes[recipeCount].name)) {
                getline(file, recipes[recipeCount].ingredients);
                getline(file, recipes[recipeCount].instructions);
                string delimiter;
                getline(file, delimiter); // skip ---
                recipeCount++;

                if (recipeCount >= MAX_RECIPES) break;
            }
            file.close();
            std::cout << "Recipes loaded from file.\n";
        }
        else if (choice == 6) {
            cout << "Exiting Recipe Book. Goodbye!\n";
        }
        else if (choice == 7) {
            generateVolumeComparisonSVG();
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
