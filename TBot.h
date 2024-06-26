#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <string>

using namespace std;

class Robot {
protected:
    string name;
    int numOfLives = 3;
    int x, y; // Position on the grid

public:
    Robot(string _name, int _numOfLives, int _x, int _y);

    void Look(char** grid, int width, int height);
    void Fire(char **grid, int width, int height);

    virtual ~Robot() {}

    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int _x, int _y) { x = _x; y = _y; }

    string getName() const { return name; }

};

class SimpleBot : public Robot { //inheritance
public:
    SimpleBot(string _name, int _numOfLives, int _x, int _y);
    
    using Robot::Look;

};

#endif // BOT_H
