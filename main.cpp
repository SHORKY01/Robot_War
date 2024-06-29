#include "battlefield.h"
#include "robot.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    // Create the battlefield matrix
    vector<vector<char>> battlefield(HEIGHT, vector<char>(WIDTH));

    // Initialize the battlefield
    initializeBattlefield(battlefield);

    // Create robots with different capabilities and place them on the battlefield
    vector<Robot> robots = {
        Robot(1, 1, 1, true, true, true),
        Robot(2, 2, 2, true, false, true),
        Robot(3, 3, 3, false, true, true)
    };

    // Place robots on the battlefield
    battlefield[1][1] = 'R'; // Position for Robot 1
    battlefield[2][2] = 'R'; // Position for Robot 2
    battlefield[3][3] = 'R'; // Position for Robot 3

    // Display the initial battlefield
    displayBattlefield(battlefield);

    // Simulate turns
    for (int turn = 0; turn < 5; ++turn) { // Run for 5 turns for example
        cout << "Turn " << turn + 1 << endl;
        for (auto& robot : robots) {
            robot.performActions(battlefield);
            displayBattlefield(battlefield);
        }
    }

    return 0;
}
