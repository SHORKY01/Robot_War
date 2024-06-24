#include "TBot.h"
#include "Grid.h"
#include <iostream> 

using namespace std;

int main() {
    Grid grid(30, 20);

    SimpleBot simple("SimpleBot", 29, 0);
    grid.placeBot(simple.getX(), simple.getY(), 'S');
    
    grid.display();

    int newX, newY;
    cout << "Enter new x position for the bot (1-30): ";
    cin >> newX;
    cout << "Enter new y position for the bot (1-20): ";
    cin >> newY;

    newX -= 1;
    newY -= 1;

    grid.clearPosition(simple.getX(), simple.getY());
    
    simple.setPosition(newX, newY);
    grid.placeBot(simple.getX(), simple.getY(), 'S');
    
    cout << "\nAfter moving the bot:\n";
    grid.display();

    return 0;
}
