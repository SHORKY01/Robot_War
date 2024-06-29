#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <vector>

using namespace std;

const int WIDTH = 10;  // You can change this to 80
const int HEIGHT = 5;  // You can change this to 50

void initializeBattlefield(vector<vector<char>>& battlefield);
void displayBattlefield(const vector<vector<char>>& battlefield);

#endif // BATTLEFIELD_H
