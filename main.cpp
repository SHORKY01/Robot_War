//main.cpp

#include "Grid.h"
#include "TBot.h"
#include "Queue.h"
#include "DerivedRobot.h"
#include <iostream> 

using namespace std; // Use std namespace globally

int main() {
    Grid grid(30, 20);
    Grid* gridPtr = &grid;

    // Create a queue for managing turns
    Queue<Robot*> turnQueue;

    // Initialize Robots
    SimpleBot *simple = new SimpleBot("SimpleBot", 3, 0, 0, 0, gridPtr);
    RoboCop *robocop = new RoboCop("Robocop", 3, 0, 1, 1, gridPtr);
    // Add other robots here
    // Terminator* terminator = new Terminator(...);
    // TerminatorRobocop* terminatorRobocop = new TerminatorRobocop(...);
    // BlueThunder* blueThunder = new BlueThunder(...);
    // MadBot* madBot = new MadBot(...);
    // RoboTank* roboTank = new RoboTank(...);
    // UltimateRobot* ultimateRobot = new UltimateRobot(...);

    // Enqueue Robots
    turnQueue.enqueue(robocop);
    turnQueue.enqueue(simple);
    // Enqueue other robots similarly
    // turnQueue.enqueue(terminator);
    // turnQueue.enqueue(terminatorRobocop);
    // turnQueue.enqueue(blueThunder);
    // turnQueue.enqueue(madBot);
    // turnQueue.enqueue(roboTank);
    // turnQueue.enqueue(ultimateRobot);

    // Display initial grid state
    grid.placeBot(simple->getX(), simple->getY(), 'S');
    grid.placeBot(robocop->getX(), robocop->getY(), 'R');
    // Place other Robots similarly...

    grid.display();  

    int turnNumber = 1;

    // Main game loop
    while (!turnQueue.isEmpty()) {
        cout << "\nTurn " << turnNumber << endl; // Print current turn number

        // Process each bot's turn
        int numBots = turnQueue.size(); // Number of bots in the queue for this turn
        for (int i = 0; i < numBots; ++i) {
            Robot* currentRobot = turnQueue.dequeue(); // Get the current robot's turn from the queue
            cout << "\nCurrent turn: " << currentRobot->getName() << endl; // Display current robot's turn

            // Perform actions for the current robot (you can add more logic here)
            int choice;
            cout << "1 - Look" << endl 
                 << "2 - Fire" << endl 
                 << "3 - Move" << endl 
                 << "4 - Step" << endl 
                 << "Choice: ";
            cin >> choice;
        
            switch (choice) {
                case 1:
                    if (SeeingRobot* seeingRobot = dynamic_cast<SeeingRobot*>(currentRobot)) {
                        seeingRobot->Look(grid.getGrid(), grid.getWidth(), grid.getHeight());
                    } else {
                        cout << "This robot can't perform the Look action!" << endl;
                    }
                    break;
                case 2:
                    if (ShootingRobot* shootingRobot = dynamic_cast<ShootingRobot*>(currentRobot)) {
                        shootingRobot->Fire(grid.getGrid(), grid.getWidth(), grid.getHeight());
                    } else {
                        cout << "This robot can't perform the Fire action!" << endl;
                    }
                    break;
                case 3: {
                    int newX, newY;
                    cout << "Enter new x position for the bot (1-30): ";
                    cin >> newX;
                    cout << "Enter new y position for the bot (1-20): ";
                    cin >> newY;
                    newX -= 1;
                    newY -= 1;

                    if (MovingRobot* movingRobot = dynamic_cast<MovingRobot*>(currentRobot)) {
                        grid.clearPosition(currentRobot->getX(), currentRobot->getY());
                        movingRobot->setPosition(newX, newY);
                        grid.placeBot(currentRobot->getX(), currentRobot->getY(), currentRobot->getName()[0]);
                    } else {
                        cout << "This robot can't perform the Move action!" << endl;
                    }
                    break;
                }
                case 4:
                    if (SteppingRobot* steppingRobot = dynamic_cast<SteppingRobot*>(currentRobot)) {
                        steppingRobot->Step(grid.getGrid(), grid.getWidth(), grid.getHeight());
                    } else {
                        cout << "This robot can't perform the Step action!" << endl;
                    }
                    break;
                default:
                    cout << "Invalid Choice!" << endl;
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
    delete robocop;
    // Delete other robots similarly...
    // delete terminator;
    // delete terminatorRobocop;
    // delete blueThunder;
    // delete madBot;
    // delete roboTank;
    // delete ultimateRobot;

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

    cout << "\n1 - Look" << endl 
         << "2 - Fire" << endl 
         << "3 - Move" << endl 
         << "4 - Step" << endl 
         << "Choice: ";
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
        //(Not finish for all Robots) simple->Step(grid.getGrid(), grid.getWidth(), grid.getHeight());
    }
    grid.display();

    return 0;
}
