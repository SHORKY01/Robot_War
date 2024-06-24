#include "TBot.h"
#include <iostream>

using namespace std;

Bot::Bot(std::string _name, int _health, int _power, int _x, int _y)
    : name(_name), health(_health), power(_power), x(_x), y(_y) {}

SimpleBot::SimpleBot(std::string _name, int _x, int _y)
    : Bot(_name, 100, 20, _x, _y) {}

void SimpleBot::attack() const {
    cout << name << " attacks with Basic Strike." << endl;
}

void SimpleBot::defend() const {
    cout << name << " defends with Simple Block." << endl;
}
