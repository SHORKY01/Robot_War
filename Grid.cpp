

#include "Grid.h"
#include "TBot.h"
#include <iostream>
#include <string>

using namespace std;

    Grid::Grid(int w, int h) : width(w), height(h)
    {
        grid  = new char *[width];
        for (int i = 0; i < width; ++i)
        {
            grid[i] = new char[width];
        }
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                grid[i][j] = '.';
            }
        }
    }

            void Grid::placeBot(int x, int y, char Robotname)//
            {
                if (x >= 0 && x < width && y >= 0 && y < height)
                {
                    grid[y][x] = Robotname;
                }
            }

            void Grid::clearPosition(int x, int y)
            {
                if (x >= 0 && x < width && y >= 0 && y < height)
                {
                    grid[y][x] = '.';
                }
            }

            void Grid::display() const
            {
                for (int i = 0; i < height; ++i)
                {
                    for (int j = 0; j < width; ++j)
                    {
                        cout << grid[i][j] << ' ';
                    }
                    cout << endl;
                }
            }
