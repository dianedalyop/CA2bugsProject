#include "Bug.h"
#include "Hopper.h"
#include "Crawler.h"
#include "Board.h"
#include <iostream>

Bug::Bug(char t, int id, int xx, int yy, Direction d, int s)
        : type(t), bugID(id), x(xx), y(yy), direction(d), size(s) {}

int Bug::getSize() const {
    return size;
}

int Bug::getY() const {
    return y;
}

int Bug::getX() const {
    return x;
}

void Bug::display() {
    std::cout << "Type: " << type << " : ";
    std::cout << "Bug ID: " << bugID << " : ";
    std::cout << "X coordinate: " << x << " : ";
    std::cout << "Y coordinate: " << y << " : ";
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
            if (y > 0) y--;
            break;
        case EAST:
            if (x < Board::BOARD_WIDTH - 1) x++;
            break;
        case SOUTH:
            if (y < Board::BOARD_HEIGHT - 1) y++;
            break;
        case WEST:
            if (x > 0) x--;
            break;
    }
    addPosHistory();
}

void Bug::addPosHistory() {
    pathHistory.push_back(std::make_pair(x, y));
}

void Bug::displayPathHistory(){

        std::cout << "Path history for Bug " << bugID << " : " << getX() << " " << getY()<< " \n";
        for (const auto& position : pathHistory) {
            std::cout << "(" << position.first << ", " << position.second << ")\n";
        }

}

