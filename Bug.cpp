#include "Bug.h"
#include <iostream>

Bug::Bug(char t, int id, int xx, int yy, Direction d, int s)
        : type(t), bugID(id), x(xx), y(yy), direction(d), size(s) {}

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
