#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <string>

using namespace std;

class Bot {
protected:
    string name;
    int health;
    int power;
    int x, y; // Position on the grid

public:
    Bot(string _name, int _health, int _power, int _x, int _y);

    virtual void attack() const = 0;
    virtual void defend() const = 0;

    virtual ~Bot() {}

    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int _x, int _y) { x = _x; y = _y; }
};

class SimpleBot : public Bot {
public:
    SimpleBot(string _name, int _x, int _y);

    void attack() const override;
    void defend() const override;
};

#endif // BOT_H
