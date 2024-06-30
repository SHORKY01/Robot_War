#ifndef BOT_H
#define BOT_H

#include "Grid.h"
#include <iostream>
#include <string>

using namespace std;

class Robot {
protected:
    string name;
    int numOfLives = 3;
    int kills = 0;
    int x, y; // Position on the grid
    Grid* grid;

public:
    Robot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid);

    virtual ~Robot() {}

    int getX() const { return x; }
    int getY() const { return y; }
    int getLivesLeft() const { return numOfLives; }
    int getKills() const { return kills; }
    void setPosition(int _x, int _y) { x = _x; y = _y; }
    void PointerToGrid(int* newX, int* newY);

    string getName() const { return name; }  

    // Virtual functions to be overridden in derived classes
};
class MovingRobot : public virtual Robot
{
public:
    MovingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid);
    virtual void Move(Grid *grid, int newX, int newY);

    virtual ~MovingRobot() {} // destructor
};

class SeeingRobot : public virtual Robot {
    public:
        SeeingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid);
        void Look(char **grid, int width, int height);

        virtual ~SeeingRobot() {} // destructor

};

class ShootingRobot : public virtual Robot
{
public:
    ShootingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid);
    virtual void Fire(char **grid, int width, int height);

    virtual ~ShootingRobot() {} // destructor
};

class SteppingRobot : public virtual Robot
{
    public:
    SteppingRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid);
    void Step(char** grid, int width, int height);

    virtual ~SteppingRobot() {}
};



class SimpleBot : public virtual Robot, public SeeingRobot, public ShootingRobot, public SteppingRobot, public MovingRobot { //inheritance
public:
    SimpleBot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid);

    virtual ~SimpleBot() {}

};

#endif // BOT_H
