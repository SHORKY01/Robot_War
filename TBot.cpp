#include "robot.h"
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

Robot::Robot(int id, int x, int y, bool canLook, bool canMove, bool canFire)
    : id(id), x(x), y(y), canLook(canLook), canMove(canMove), canFire(canFire) {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
}

void Robot::performActions(vector<vector<char>>& battlefield) {
    if (canLook) look(battlefield);
    if (canMove) move(battlefield);
    if (canFire) fire(battlefield);
}

void Robot::look(const vector<vector<char>>& battlefield) {
    cout << "Robot " << id << " is looking around." << endl;
    int lookRange = 1;  // Define how far the robot can look
    for (int i = y - lookRange; i <= y + lookRange; ++i) {
        for (int j = x - lookRange; j <= x + lookRange; ++j) {
            if (i >= 0 && i < battlefield.size() && j >= 0 && j < battlefield[0].size()) {
                cout << " (" << j << ", " << i << "): " << battlefield[i][j];
            }
        }
        cout << endl;
    }
}

void Robot::move(vector<vector<char>>& battlefield) {
    // Define the 8 possible movements
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, // Up-left, Up, Up-right
        {0, -1},           {0, 1},  // Left,        Right
        {1, -1}, {1, 0}, {1, 1}     // Down-left, Down, Down-right
    };

    // Select a random direction to move
    int dirIndex = rand() % directions.size();
    int newX = x + directions[dirIndex].second;
    int newY = y + directions[dirIndex].first;

    // Check if the new position is within bounds and not occupied
    if (newX >= 0 && newX < battlefield[0].size() && newY >= 0 && newY < battlefield.size() && battlefield[newY][newX] == '.') {
        battlefield[y][x] = '.';
        x = newX;
        y = newY;
        battlefield[y][x] = 'R';
        cout << "Robot " << id << " moved to (" << x << ", " << y << ")." << endl;
    } else {
        cout << "Robot " << id << " failed to move." << endl;
    }
}

void Robot::fire(vector<vector<char>>& battlefield) {
    cout << "Robot " << id << " is firing." << endl;
}
