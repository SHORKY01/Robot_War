#include "battlefield.h"
#include <iostream>

using namespace std;

// Function to initialize the battlefield
void initializeBattlefield(vector<vector<char>>& battlefield) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            battlefield[i][j] = '.';  // Empty space
        }
    }
}

// Function to display the battlefield with grid borders
void displayBattlefield(const vector<vector<char>>& battlefield) {
    // Top border
    cout << "+";
    for (int j = 0; j < WIDTH; ++j) {
        cout << "---+";
    }
    cout << endl;

    for (int i = 0; i < HEIGHT; ++i) {
        // Left border of the row
        cout << "|";
        for (int j = 0; j < WIDTH; ++j) {
            cout << " " << battlefield[i][j] << " |";
        }
        cout << endl;

        // Bottom border of the row
        cout << "+";
        for (int j = 0; j < WIDTH; ++j) {
            cout << "---+";
        }
        cout << endl;
    }
}
