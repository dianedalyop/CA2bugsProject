#include <iostream>
#include <fstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
using namespace std;
void findBugByID( const Board &board);
void displayBugs( const Board &board);
void moveBugs(const Board &board);

int main() {




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


    while (inputFile >> type >> bugID >> x >> y >> direction >> size) {
        Direction dir = static_cast<Direction>(direction);
        if (type == 'C') {
            board.addBug(new Crawler(type, bugID, x, y, dir, size));
        } else if (type == 'H') {
            inputFile >> hopLength;
            board.addBug(new Hopper(type, bugID, x, y, dir, size, hopLength));
        }

    }

    int choice ;
bool sim = false;

while (!sim) {

        cout<< "==============================================" << endl;

        cout<< "1. Get Bugs Data from File" << endl;
        cout<< "2. Display all Bug Details" << endl;
        cout<< "3. Find Bug by ID" << endl;
        cout<< "4. Tap Bug Board" << endl;
        cout<< "5. Display Life History (Path Taken)" << endl;
        cout<< "6. Display cells listing their bugs" << endl;
        cout<< "7. Run Simulation GUI" << endl;
        cout<< "8. Exit" << endl;
        cout<< "==============================================" << endl;

        cin >> choice;

        if(choice == 2) {
            displayBugs(board);
        }
        if(choice == 3) {
            findBugByID(board);
        }
         if (choice == 4){
             moveBugs(board);
         }


if(choice == 5) {
    // Move bugs and display path history after each iteration
    for (int i = 1; i <= 3; ++i) {
        std::cout << "\nMoving bugs iteration " << i << "...\n";
        board.moveBugs(); // Move bugs
        std::cout << "Path history after moving bugs iteration " << i << ":\n";
        for (Bug *bug: board.getBugs()) {
            bug->displayPathHistory(); // Display path history for each bug
        }
    }

}

if(choice == 6) {
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


    std::cout << "\nInteractions between bugs:\n";
    board.bugsInteraction();
}




if(choice == 7){
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
            for (Bug *bug : board.getBugs()) {
                if (dynamic_cast<Crawler *>(bug) != nullptr) {
                    // Draw a red circle for crawlers
                    sf::CircleShape bugShape(10);
                    bugShape.setFillColor(sf::Color::Red);
                    bugShape.setPosition(bug->getX() * cellSize, bug->getY() * cellSize);
                    window.draw(bugShape);

                    // Draw legs for crawlers
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            // Skip drawing a leg at the center
                            if (!(i == 0 && j == 0)) {
                                sf::RectangleShape leg(sf::Vector2f(3, 3));
                                leg.setFillColor(sf::Color::Black);
                                leg.setPosition((bug->getX() + 0.5 + i * 0.25) * cellSize, (bug->getY() + 0.5 + j * 0.25) * cellSize);
                                window.draw(leg);
                            }
                        }
                    }
                } else if (dynamic_cast<Hopper *>(bug) != nullptr) {
                    // Draw a green circle for hoppers
                    sf::CircleShape bugShape(10);
                    bugShape.setFillColor(sf::Color::Green);
                    bugShape.setPosition(bug->getX() * cellSize, bug->getY() * cellSize);
                    window.draw(bugShape);

                    // Draw legs for hoppers
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            // Skip drawing a leg at the center
                            if (!(i == 0 && j == 0)) {
                                sf::RectangleShape leg(sf::Vector2f(3, 3));
                                leg.setFillColor(sf::Color::Black);
                                leg.setPosition((bug->getX() + 0.5 + i * 0.25) * cellSize, (bug->getY() + 0.5 + j * 0.25) * cellSize);
                                window.draw(leg);
                            }
                        }
                    }
                }
            }

            window.display();
        }

    inputFile.close();
        }
        if(choice == 8){
    cout<< " Goodbye "<<endl;

    sim = true;
        }
    }
        return 0;

}


void findBugByID( const Board &board){

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


}

void displayBugs( const Board &board) {
    board.displayBugs();
}

void moveBugs(const Board &board){
    std::cout << "\nMoving bugs...\n";
    board.moveBugs();
    board.displayBugs();

}

