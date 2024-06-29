#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

using namespace std;

class Robot {
public:
    Robot(int id, int x, int y, bool canLook, bool canMove, bool canFire);

    void performActions(vector<vector<char>>& battlefield);

private:
    int id;
    int x, y;
    bool canLook;
    bool canMove;
    bool canFire;

    void look(const vector<vector<char>>& battlefield);
    void move(vector<vector<char>>& battlefield);
    void fire(vector<vector<char>>& battlefield);
};

#endif // ROBOT_H
