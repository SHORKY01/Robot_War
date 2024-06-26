#include "TBot.h"
#include "Grid.h"
#include <iostream>

using namespace std;

Robot::Robot(std::string _name, int _numOfLives, int _x, int _y)
    : name(_name), x(_x), y(_y) {}

void Robot::Look(char** grid, int width, int height) {
   cout << '\n' << name << " is looking around " << endl;
   bool Enemy = false;
   for (int W = -4; W <= 4; ++W)
   {
       for (int H = -4; H <= 4; ++H)
       {
           int lookX = x + W;
           int lookY = y + H;

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
}

void Robot::Fire(char **grid, int width, int height)
{
    cout << '\n'
         << name << " is firing!" << endl;

    // Fire up
    for (int FireY = y - 1; FireY >= 0; --FireY)
    {
        if (grid[FireY][x] != '.' && !(x == x && FireY == y))
        {
            cout << "-> " << name << " hit something at (" << x << ", " << FireY << "): " << grid[FireY][x] << endl;
            break;
        }
        else {
            cout << "-> " << name << " missed at (" << x << ", " << FireY << "): U" << grid[FireY][x] << endl;
        }
    }

    // Fire down
    for (int FireY = y + 1; FireY < height; ++FireY)
    {
        if (grid[FireY][x] != '.' && !(x == x && FireY == y))
        {
            cout << "-> " << name << " hit something at (" << x << ", " << FireY << "): " << grid[FireY][x] << endl;
            break;
        }
        else
        {
            cout << "-> " << name << " missed at (" << x << ", " << FireY << "): D" << grid[FireY][x] << endl;
        }
    }

    // Fire left
    for (int FireX = x - 1; FireX >= 0; --FireX)
    {
        if (grid[y][FireX] != '.' && !(FireX == x && y == y))
        {
            cout << "-> " << name << " hit something at (" << FireX << ", " << y << "): " << grid[y][FireX] << endl;
            break;
        }
        else
        {
            cout << "-> " << name << " missed at (" << x << ", " << FireX << "): L " << grid[y][FireX] << endl;
        }
    }

    // Fire right
    for (int FireX = x + 1; FireX < width; ++FireX)
    {
        if (grid[y][FireX] != '.' && !(FireX == x && y == y))
        {
            cout << "-> " << name << " hit something at (" << FireX << ", " << y << "): " << grid[y][FireX] << endl;
            break;
        }
        else
        {
            cout << "-> " << name << " missed at (" << x << ", " << FireX << "): R" << grid[y][FireX] << endl;
        }
    }
}

SimpleBot::SimpleBot(string _name, int _numOfLives, int _x, int _y)
    : Robot(_name, 3, _x, _y) {}
