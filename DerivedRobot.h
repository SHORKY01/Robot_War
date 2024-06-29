//DerivedRobot.h

#ifndef DERIVEDROBOT_H
#define DERIVEDROBOT_H

#include <iostream>
#include <string>
#include "TBot.h"

class RoboCop : public virtual Robot, public SeeingRobot, public ShootingRobot, public MovingRobot
{ // inheritance
public:
    RoboCop(string _name, int _numOfLives, int _kills, int _x, int _y, Grid* _grid);
    void Move(Grid *grid, int newX, int newY) override;

    virtual ~RoboCop() {}
};

class Terminator : public virtual Robot, public SeeingRobot, public ShootingRobot, public MovingRobot
{ // inheritance
public:
    Terminator(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid);
    
    virtual ~Terminator() {}
};

class TerminatorRoboCop : public virtual Robot, public SeeingRobot, public ShootingRobot, public MovingRobot
{ // inheritance
public:
    TerminatorRoboCop(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid);

    virtual ~TerminatorRoboCop() {}
};

class BlueThunder : public virtual Robot, public SeeingRobot, public ShootingRobot, public MovingRobot
{ // inheritance
public:
    BlueThunder(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid);

    virtual ~BlueThunder() {}
};

class Madbot : public virtual Robot, public SeeingRobot, public ShootingRobot, public MovingRobot
{ // inheritance
public:
    Madbot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid);

    virtual ~Madbot() {}
};

class RoboTank : public virtual Robot, public SeeingRobot, public ShootingRobot, public MovingRobot
{ // inheritance
public:
    RoboTank(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid);

    virtual ~RoboTank() {}
};

class UltimateRobot : public virtual Robot, public SeeingRobot, public ShootingRobot, public MovingRobot
{ // inheritance
public:
    UltimateRobot(string _name, int _numOfLives, int _kills, int _x, int _y, Grid *_grid);

    virtual ~UltimateRobot() {}
};

#endif //DERIVEDROBOT.H
