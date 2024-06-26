#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
using namespace std;

class Grid {
protected:
    int width;
    int height;
    char** grid;

public:
    Grid(int w, int h);
    ~Grid(){
        for (int i = 0; i < width; ++i)
        {
            delete[] grid[i];
        }
        delete[] grid;
    }

    void placeBot(int x, int y, char name);
    void clearPosition(int x, int y);
    void display() const;
    char** getGrid() { return grid; };
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

#endif //GRID_H
