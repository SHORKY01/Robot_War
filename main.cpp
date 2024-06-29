//main.cpp

#include "Grid.h"
#include "TBot.h"
#include "Queue.h"
#include <iostream> 

using namespace std; // Use std namespace globally

int main() {
    Grid grid(30, 20);
    Grid* gridPtr = &grid;

    // Create a queue for managing turns
    Queue<SimpleBot*> turnQueue;

    SimpleBot *simple = new SimpleBot("SimpleBot", 3, 0, 0, 0, gridPtr);
    turnQueue.enqueue(simple);

    SimpleBot *enemy = new SimpleBot("SimpleBotOfHeaven", 3, 0, 1, 3, gridPtr);
    turnQueue.enqueue(enemy);

    // Display initial grid state
    grid.placeBot(simple->getX(), simple->getY(), 'S');
    grid.placeBot(enemy->getX(), enemy->getY(), 'P');

    grid.display();  

    int turnNumber = 1;

    // Main game loop
    while (!turnQueue.isEmpty()) {
        // Print current turn number
        cout << "\nTurn " << turnNumber << endl;

        // Process each bot's turn
        int numBots = turnQueue.size(); // Number of bots in the queue for this turn
        for (int i = 0; i < numBots; ++i) {
            // Get the current robot's turn from the queue
            SimpleBot* currentRobot = turnQueue.dequeue();

            // Display current robot's turn
            cout << "\nCurrent turn: " << currentRobot->getName() << endl;

            // Perform actions for the current robot (you can add more logic here)
            int choice;
            cout << "1 - Look" << endl << "2 - Fire" << endl << "3 - Move" << endl << "4 - Step" << endl << "Choice: ";
            cin >> choice;
        
            switch (choice) {
                case 1:
                    currentRobot->Look(grid.getGrid(), grid.getWidth(), grid.getHeight());
                    break;
                case 2:
                    currentRobot->Fire(grid.getGrid(), grid.getWidth(), grid.getHeight());
                    break;
                case 3: {
                    int newX, newY;
                    cout << "Enter new x position for the bot (1-30): ";
                    cin >> newX;
                    cout << "Enter new y position for the bot (1-20): ";
                    cin >> newY;
                    newX -= 1;
                    newY -= 1;

                    grid.clearPosition(currentRobot->getX(), currentRobot->getY());
                    currentRobot->setPosition(newX, newY);
                    grid.placeBot(currentRobot->getX(), currentRobot->getY(), currentRobot->getName()[0]);
                    break;
                }
                case 4:
                    currentRobot->Step(grid.getGrid(), grid.getWidth(), grid.getHeight());
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }

            // Enqueue the current robot back to the queue for the next turn
            turnQueue.enqueue(currentRobot);

        }
        
        // Display updated grid state
        grid.display();

        // Increment turn number for the next round
        turnNumber++;
        
    }

    // Clean up memory
    delete simple;
    delete enemy;

    // Call the Look function to print the surrounding area

    int newX, newY;
    cout << "Enter new x position for the bot (1-30): ";
    cin >> newX;

    cout << "Enter new y position for the bot (1-20): ";
    cin >> newY;
    newX -= 1;
    newY -= 1;

    grid.clearPosition(simple->getX(), simple->getY());

    simple->setPosition(newX, newY);
    grid.placeBot(simple->getX(), simple->getY(), 'S');

    cout << "\nAfter moving the bot:\n";
    grid.display();

    cout << "\n1 - Look" << endl << "2 - Fire" << endl << "3 - Move" << "\n4 - Step" << endl << "Choice: ";
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
