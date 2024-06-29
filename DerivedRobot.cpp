//DerivedRobot.cpp

#include <iostream>
#include <string>
#include "Grid.h"
#include "TBot.h"
#include "DerivedRobot.h"

RoboCop::RoboCop(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

void RoboCop::Move(Grid *grid, int newX, int newY)
{

    int choice_dir;
    newX = getX();
    newY = getY();
    cout << "Which direction does the robot move?\n \n1.UP\n2.DOWN\n3.RIGHT\n4.LEFT\n5.UP LEFT\n6.UP RIGHT\n7.DOWN LEFT\n8.DOWN RIGHT: ";
    cin >> choice_dir;
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
    default:
        cout << "Invalid choice" << endl;
        return;
    }

    // update position
    grid->clearPosition(x, y);
    PointerToGrid(&newX, &newY);

    if (newX >= 0 && x < grid->getWidth() && y >= 0 && y < grid->getHeight())
    {
        // place robot at new position
        grid->placeBot(x, y, this->getName()[0]);
        cout << "->" << name << " moved to (" << newX << ", " << newY << ")" << endl;
    }
    else
    {
        cout << "Invalid move. Position out of bounds." << endl;
    }
}

Terminator::Terminator(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid)
    : Robot(_name, 3, _kills, _x, _y, _grid), SeeingRobot(_name, 3, _kills, _x, _y, _grid), ShootingRobot(_name, 3, _kills, _x, _y, _grid), MovingRobot(_name, 3, _kills, _x, _y, _grid) {}

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
