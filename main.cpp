#include "Grid.h"
#include "TBot.h"
#include <iostream> 

using namespace std;

int main() {
    Grid grid(30, 20);
    Grid* gridPtr = &grid;

    SimpleBot *simple = new SimpleBot("SimpleBot", 3, 0, 0, 0, gridPtr);
    grid.placeBot(simple->getX(), simple->getY(), 'S');

    SimpleBot *enemy = new SimpleBot("SimpleBotOfHeaven", 3, 0, 1, 3, gridPtr);
    grid.placeBot(enemy->getX(), enemy->getY(), 'P');

    grid.display();  
    // Call the Look function to print the surrounding area
    

    int newX, newY;
    cout << "Enter new x position for the bot (1-30): ";
    cin >> newX;

    cout << "Enter new y position for the bot (1-20): ";
    cin >> newY;++
    newX -= 1;
    newY -= 1;

    grid.clearPosition(simple->getX(), simple->getY());

    simple->setPosition(newX, newY);
    grid.placeBot(simple->getX(), simple->getY(), 'S');

    cout << "\nAfter moving the bot:\n";
    grid.display();

    cout << "\n1 - Look" << endl << "2 - Fire" << endl << "3 - Move" << "\n4 - Step" << endl << "Choice: " ;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        simple->Look(grid.getGrid(), grid.getWidth(), grid.getHeight());
    }
    else if (choice == '2')
    {
        simple->Fire(grid.getGrid(), grid.getWidth(), grid.getHeight());
    }
    else if (choice == '3')
    {
        simple->Move(&grid, grid.getWidth(), grid.getHeight());
    }
    else if (choice == '4')
    {
        simple->Step(grid.getGrid(), grid.getWidth(), grid.getHeight());
    }
    grid.display();

    return 0;
}
