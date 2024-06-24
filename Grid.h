#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
using namespace std;

class Grid {
private:
    int width;
    int height;
    vector<vector<char>> grid;

public:
    Grid(int w, int h);

    void placeBot(int x, int y, char symbol);
    void clearPosition(int x, int y);
    void display() const;
};

#endif // GRID_H
