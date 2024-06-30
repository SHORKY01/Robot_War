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
//terminator
Terminator::Terminator(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

void Terminator::Look(char **grid, int width, int height){
    cout << '\n'
         << name << " is looking around " << endl;
    bool Enemy = false;
    for (int W = -1; W <= 1; ++W)
    {
        for (int H = -1; H <= 1; ++H)
        {
            int lookX = getX() + W;
            int lookY = getY() + H;

            // Check bounds to avoid out-of-bounds access
            if (lookX >= 0 && lookX < width && lookY >= 0 && lookY < height)
            {
                if (grid[lookY][lookX] != '.' && !(lookX == x && lookY == y)) // to make sure it doesnt detect itself as enemy
                {
                    Enemy = true;
                    cout << "->" << name << " found enemy robot at " << "(" << lookX << "," << lookY << "): " << grid[lookY][lookX] << endl;
                    break;
                }
                if (Enemy == true)
                    break;
            }
        }
    }
    if (Enemy == false)
    {
        cout << "->" << name << " sees nothing in a 9 square area." << endl;
    }
    this->grid->display();
}
void Terminator::Move(Grid *grid, int newX, int newY)
{
    // Scan for enemy robots
    pair<int, int> enemyPositions[8];
    int enemyCount = 0;
    int width = grid->getWidth();
    int height = grid->getHeight();

    for (int W = -1; W <= 1; ++W)
    {
        for (int H = -1; H <= 1; ++H)
        {
            int lookX = getX() + W;
            int lookY = getY() + H;

            // Check bounds to avoid out-of-bounds access
            if ((lookX >= 0 && lookX < width) && (lookY >= 0 && lookY < height))
            {
                if ((grid->getGrid()[lookY][lookX] != '.') && !(lookX == getX() && lookY == getY()))
                { // to make sure it doesn't detect itself as enemy
                    if (enemyCount < 8)
                    {
                        enemyPositions[enemyCount++] = {lookX, lookY};
                    }
                }
            }
        }
    }

    // Move to an enemy position if found
    if (enemyCount > 0)
    {
        int targetIndex = rand() % enemyCount;
        newX = enemyPositions[targetIndex].first;
        newY = enemyPositions[targetIndex].second;
    }
    else
    {
        // If no enemies are found, move randomly
        srand(time(0));
        int choice_dir = rand() % 8 + 1;
        newX = getX();
        newY = getY();
        switch (choice_dir)
        {
        case 1:
            newY -= 1;
            break;
        case 2:
            newY += 1;
            break;
        case 3:
            newX += 1;
            break;
        case 4:
            newX -= 1;
            break;
        case 5:
            newX -= 1;
            newY -= 1;
            break;
        case 6:
            newX += 1;
            newY -= 1;
            break;
        case 7:
            newX -= 1;
            newY += 1;
            break;
        case 8:
            newX += 1;
            newY += 1;
            break;
        }
    }

    // Update position
    if (newX >= 0 && newX < grid->getWidth() && newY >= 0 && newY < grid->getHeight())
    {
        if (!(newX == getX() && newY == getY()))
        {
            grid->clearPosition(x, y);
            if (grid->getGrid()[newY][newX] == '.')
            {
                cout << "\n->" << getName() << " moved to (" << newX << ", " << newY << ")" << endl;
                x = newX;
                y = newY;
                grid->placeBot(newX, newY, this->getName()[0]);
            }
            else
            {
                cout << "\n->" << "Robot is stepped on!: " << grid->getGrid()[newY][newX] << endl;
                kills = getKills() + 1;
                cout << "\n->" << getName() << " now has " << getKills() << " kills!\n";
                x = newX;
                y = newY;
                grid->placeBot(newX, newY, this->getName()[0]);
            }
        }
    }
    else
    {
        cout << "->" << "Invalid point. Position out of bounds." << endl;
    }
    this->grid->display();
}
//----------------------------------------------------------------------------------------------------------------
TerminatorRoboCop::TerminatorRoboCop(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

BlueThunder::BlueThunder(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid)
{
}

Madbot::Madbot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

RoboTank::RoboTank(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

UltimateRobot::UltimateRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}
