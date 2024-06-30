#include "Grid.h"
#include "TBot.h"
#include "Queue.h"
#include <iostream>

using namespace std;

Robot::Robot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid)
    : name(_name), numOfLives(_numOfLives), kills(_kills), x(_x), y(_y), grid(_grid) {}

MovingRobot::MovingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid)
    : Robot(_name, 3, _kills, _x, _y, _grid) {}

SeeingRobot::SeeingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid) {}

ShootingRobot::ShootingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid) {}

SteppingRobot::SteppingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid) {}

void Robot::PointerToGrid(int *newX, int *newY)
{
    if (*newX >= 0 && *newX < grid->getWidth() && *newY >= 0 && *newY < grid->getHeight()) //pointers pointing to grid members
    {
        if (grid->getGrid()[*newY][*newX] == '.')
        {
        x = *newX;
        y = *newY;
        cout << "\n->" << name << " moved to (" << *newX << ", " << *newY << ")" << endl;
        }
        else if (grid->getGrid()[*newY][*newX] != '.')
        {
            cout << "\n->" << "Unable to move, there exists a robot in this position: " << grid->getGrid()[*newY][*newX] << endl;
        }
    }
    else
    {
        cout << "->" << "Invalid point. Position out of bounds." << endl;
    }
}

void MovingRobot::Move(Grid* grid, int newX, int newY) {

    int choice_dir;
    newX = getX();
    newY = getY();
    cout << "Which direction does the robot move?\n \n1.UP\n2.DOWN\n3.RIGHT\n4.LEFT\n5.UP LEFT\n6.UP RIGHT\n7.DOWN LEFT\n8.DOWN RIGHT: ";
    cin >> choice_dir;
    switch (choice_dir) {
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
        default:
            cout << "Invalid choice for direction" << endl;  
            return;
    }

    // update position
    grid->clearPosition(x,y);
    PointerToGrid(&newX, &newY);

    //place robot at new position, same position if x and y didnt change
    grid->placeBot(x, y, this->getName()[0]);
    this->grid->display();
}




void SeeingRobot::Look(char** grid, int width, int height) {
   cout << '\n' << name << " is looking around " << endl;
   bool Enemy = false;
   for (int W = -4; W <= 4; ++W)
   {
       for (int H = -4; H <= 4; ++H)
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
   if (Enemy == false){
       cout << "->" << name << " sees nothing in a 9 square area." << endl;
   }
   this->grid->display();
}

void ShootingRobot::Fire(char **grid, int width, int height)
{
    cout << name << " is firing!" << endl;
    // This function can be used to remove any robot that is shot at.
    // Derived classes can implement their own shooting patterns.
    // This base function can be called by derived classes to handle the removal of the robot.

    // Example pattern: Just removing the object at a fixed position (1 cell ahead)
    int targetX = getX(); // Example tpattern(should be overridden in derived classes)
    int targetY = getY() - 1;

    if (targetX >= 0 && targetX < width && targetY >= 0 && targetY < height)
    {
        char targetChar = grid[targetY][targetX];
        if (targetChar != '.')
        {
            cout << "-> " << name << " hit and killed something at (" << targetX << ", " << targetY << "): " << targetChar << endl;
            grid[targetY][targetX] = '.'; // Remove the object from the grid
            kills = getKills() + 1;
        }
        else
        {
            cout << "-> " << name << " missed at (" << targetX << ", " << targetY << ")" << endl;
            grid[targetY][targetX] = '.';
        }
    }
    this->grid->display();
}

void SteppingRobot::Step(char **grid, int width, int height)
{
    cout << name << " is stepping!" << endl;
    // This function can be used to remove any robot that is stepped on.
    // This base function can be called by derived classes to handle the removal of the robot.

    // Example pattern: Just removing the object at a fixed position (1 cell ahead)
    int targetX = getX(); // Example target coordinates (should be overridden in derived classes)
    int targetY = getY() - 1;

    if (targetX >= 0 && targetX < width && targetY >= 0 && targetY < height)
    {
        if (grid[targetY][targetX] != '.')
        {
            cout << "-> " << name << " hit and killed something at (" << targetX << ", " << targetY << "): " << grid[targetY][targetX] << endl;
            grid[targetY][targetX] = '.'; // Remove the object from the grid
            kills = getKills() + 1;
        }
        else
        {
            cout << "-> " << name << " missed at (" << targetX << ", " << targetY << ")" << endl;
        }
    }
    this->grid->display();
}
SimpleBot::SimpleBot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), SteppingRobot(_name, 3, kills, _x, _y, _grid), MovingRobot(_name, 3, kills, _x, _y, _grid) {}
