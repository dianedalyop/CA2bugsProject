#include <iostream>
#include <fstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
using namespace std;
void menu();

int main() {

    menu();
    int choice;
    bool end = false;

    while (!end) {
        menu();
        cout << "Enter choice " << endl;
        cin >> choice;
        std::ifstream inputFile("bugs2.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening file\n";
            return 1;
        }
        else{
            cout << "File successfully Read" << endl;
        }

        Board board;
        char type;
        int bugID, x, y, direction, size, hopLength;
if (choice == 1) {
    while (inputFile >> type >> bugID >> x >> y >> direction >> size) {
        Direction dir = static_cast<Direction>(direction);
        if (type == 'C') {
            board.addBug(new Crawler(type, bugID, x, y, dir, size));
        } else if (type == 'H') {
            inputFile >> hopLength;
            board.addBug(new Hopper(type, bugID, x, y, dir, size, hopLength));
        }

    }

}


    board.displayBugs();

        // Move bugs and display path history
        std::cout << "\nMoving bugs...\n";
        board.moveBugs();
        std::cout << "Path history after moving bugs:\n";
        for (Bug *bug: board.getBugs()) {
            bug->displayPathHistory(); // Display path history for each bug
        }

        // Move bugs and display path history after each iteration
        for (int i = 1; i <= 3; ++i) {
            std::cout << "\nMoving bugs iteration " << i << "...\n";
            board.moveBugs(); // Move bugs
            std::cout << "Path history after moving bugs iteration " << i << ":\n";
            for (Bug *bug: board.getBugs()) {
                bug->displayPathHistory(); // Display path history for each bug
            }
        }

        std::cout << "\nAfter moving:\n";
        board.displayBugs();

        // Display bugs in cells
        cout << "Bugs in cells" << endl;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                bool bugFound = false;
                for (Bug *bug: board.getBugs()) {
                    if (bug->getX() == x && bug->getY() == y) {
                        bugFound = true;
                        cout << "Bug " << bug->getBugID() << " is in cell (" << x << ", " << y << ")\n";
                    }
                }
                if (!bugFound) {
                    cout << "No bug here in cell (" << x << ", " << y << ")\n";
                }
            }
        }

        // find bug by ID
        int bugtofind;
        cout << "Enter bug ID" << endl;
        cin >> bugtofind;

        Bug *found_bug = board.findBugByID(bugtofind);
        if (found_bug) {
            cout << " Bug with ID " << bugtofind << " Found " << endl;
            found_bug->display();
        } else {
            cout << " Bug with ID " << bugtofind << "Not Found " << endl;
        }

// bugs interraction

        std::cout << "\nInteractions between bugs:\n";
        board.bugsInteraction();


        cout << "Display Path History" << endl;

        cout << "Bugs in cells" << endl;
        // Iterate through each cell in the grid


        inputFile.close();

        // SFML Rendering
        sf::RenderWindow window(sf::VideoMode(500, 500), "Bug Simulation");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);

            const int cellSize = 50;

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                    cell.setPosition(i * cellSize, j * cellSize);
                    cell.setOutlineColor(sf::Color::Black);
                    cell.setOutlineThickness(1);
                    cell.setFillColor(sf::Color(255, 192, 203));
                    window.draw(cell);
                }
            }

            // Draw bugs on the grid
            for (Bug *bug: board.getBugs()) {
                if (dynamic_cast<Crawler *>(bug) != nullptr) {
                    // Draw a specific shape for crawlers
                    sf::CircleShape bugShape(10); // Adjust size as needed
                    bugShape.setFillColor(sf::Color::Red); // Set color for crawlers
                    bugShape.setPosition(bug->getX() * cellSize,
                                         bug->getY() * cellSize); // Set position based on bug's coordinates
                    window.draw(bugShape);
                } else if (dynamic_cast<Hopper *>(bug) != nullptr) {
                    // Draw a specific shape for hoppers
                    sf::RectangleShape bugShape(sf::Vector2f(20, 20)); // Adjust size as needed
                    bugShape.setFillColor(sf::Color::Green); // Set color for hoppers
                    bugShape.setPosition(bug->getX() * cellSize,
                                         bug->getY() * cellSize); // Set position based on bug's coordinates
                    window.draw(bugShape);
                }
            }

            window.display();
        }

        return 0;
    }
}
void menu(){
    cout<< "==============================================" << endl;

    cout<< "1. Get Bugs Data from File" << endl;
    cout<< "2. Display all Bug Details" << endl;
    cout<< "3. Find Bug by ID" << endl;
    cout<< "4. Tap Bug Board" << endl;
    cout<< "5. Display Life History (Path Taken)" << endl;
    cout<< "6. Display cells listing their bugs" << endl;
    cout<< "7. Run Simulation" << endl;
    cout<< "8. Exit" << endl;
    cout<< "==============================================" << endl;
}
