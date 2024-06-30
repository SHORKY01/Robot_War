#include <iostream>
#include <string>
#include <cstdlib>
#include "Grid.h"
#include "TBot.h"
#include "DerivedRobot.h"


RoboCop::RoboCop(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

void RoboCop::Look(char** grid, int width, int height){
    SeeingRobot::Look(grid, width, height);
}

void RoboCop::Move(Grid* grid, int newX, int newY){
    MovingRobot::Move(grid, newX, newY);
}

void RoboCop::Fire(char **grid, int width, int height)
{
    int missedShots[3][2]; // To store up to 3 missed shot coordinates
    int missedCount = 0;

    for (int i = 0; i < 3; i++){ //fire 3 times
         // Generate random offsets between -5 and 5
        int RandX = rand() % 11 - 5;
        int RandY = rand() % 11 - 5;
        // coordinates that are shot at
        int newX = getX() + RandX;
        int newY = getY() + RandY;

        if ((newX >= 0 && newX < width) && (newY >= 0 && newY < height) && !(newX == getX() && newY == getY()))
        {
            //shoot at the new coordinates
            char hitrobot = grid[newY][newX] = '*'; //coordinates hit symbol
            if ((hitrobot != '.') && (hitrobot != '*')){
                cout << "\n->" << this->name << " fires at (" << newX << ", " << newY << "): " << hitrobot << endl;
                kills = getKills() + 1;
            }
            else {
                cout << "\n->" << this->name << " misses at (" << newX << ", " << newY << ")" << endl;
                grid[newY][newX] = '*'; // Mark missed shots directly on the grid
                missedShots[missedCount][0] = newX;
                missedShots[missedCount][1] = newY;
                missedCount++;
            }
        }
        else {
            cout << "\n->" << "Position shot out of bounds!" << endl;
        }
    }
    if (missedCount > 0) {
        cout << endl;
        this->grid->display(); // call the display fx on the grid member variable
        // Restore the grid by changing '*' back to '.' because '*' is just a hitmarket that shows where spots are hit on the grid
        for (int i = 0; i < missedCount; i++)
        {
            int missedX = missedShots[i][0]; // Get the x-coordinate of the missed shot
            int missedY = missedShots[i][1]; // Get the y-coordinate of the missed shot
            grid[missedY][missedX] = '.';
        }
    }
}

Terminator::Terminator(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid)
{
}

TerminatorRoboCop::TerminatorRoboCop(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

BlueThunder::BlueThunder(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

Madbot::Madbot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

RoboTank::RoboTank(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

UltimateRobot::UltimateRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}
