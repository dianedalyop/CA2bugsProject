#include "Bug.h"
#include "Hopper.h"
#include "Crawler.h"
#include "Board.h"
#include <iostream>

Bug::Bug(char t, int id, int xx, int yy, Direction d, int s)
        : type(t), bugID(id), x(xx), y(yy), direction(d), size(s) {}

int Bug::getY() const {
    return y;
}

int Bug::getX() const {
    return x;
}

void Bug::display() {
    std::cout << "Type: " << type << "\n";
    std::cout << "Bug ID: " << bugID << "\n";
    std::cout << "X coordinate: " << x << "\n";
    std::cout << "Y coordinate: " << y << "\n";
    std::cout << "Direction: ";
    switch (direction) {
        case NORTH:
            std::cout << "North";
            break;
        case EAST:
            std::cout << "East";
            break;
        case SOUTH:
            std::cout << "South";
            break;
        case WEST:
            std::cout << "West";
            break;
    }
    std::cout << "\nSize: " << size << "\n";
}
int Bug::getBugID() const {
    return bugID;
}

void Bug::move() {
    // Update bug position based on its direction and board dimensions
    switch (direction) {
        case NORTH:
            if (y > 0) y--; // Move up if not at the top boundary
            break;
        case EAST:
            if (x < Board::BOARD_WIDTH - 1) x++; // Move right if not at the right boundary
            break;
        case SOUTH:
            if (y < Board::BOARD_HEIGHT - 1) y++; // Move down if not at the bottom boundary
            break;
        case WEST:
            if (x > 0) x--; // Move left if not at the left boundary
            break;
    }

    // After moving, add the current position to the path history
    addPosHistory();
}

void Bug::addPosHistory() {
    pathHistory.push_back(std::make_pair(x, y));
}

void Bug::displayPathHistory() {
    std::cout << "Adding position to path history for Bug " << bugID << ": (" << x << ", " << y << ")\n";
    for (const auto& position : pathHistory) {
        std::cout << "(" << position.first << ", " << position.second << ")\n";
    }
}

