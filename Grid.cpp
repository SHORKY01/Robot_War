/*#include "Grid.h"
#include <iostream>
#include <vector>

using namespace std;

class Grid {
private:
    int width;
    int height;
    vector<vector<char>> grid;

public:
    Grid(int w, int h) : width(w), height(h) {
        grid.resize(height, vector<char>(width, '.'));
    }

    void placeBot(int x, int y, char symbol) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = symbol;
        }
    }

    void clearPosition(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = '.';
        }
    }

    void display() const {
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                cout << cell << ' ';
            }
            cout << endl;
        }
    }
};*/

#include "Grid.h"
#include <iostream>

using namespace std;

Grid::Grid(int w, int h) : width(w), height(h) {
    grid.resize(height, vector<char>(width, '.'));
}

void Grid::placeBot(int x, int y, char symbol) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = symbol;
    }
}

void Grid::clearPosition(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = '.';
    }
}

void Grid::display() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}
