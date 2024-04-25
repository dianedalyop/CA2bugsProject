#include "Hopper.h"
#include <iostream>

Hopper::Hopper(char t, int id, int xx, int yy, Direction d, int s, int h)
        : Bug(t, id, xx, yy, d, s), hopLength(h) {}

void Hopper::display() {
    Bug::display();
    std::cout << "Hop Length: " << hopLength << "\n";
}

void Hopper::move() {
    switch (direction) {
        case NORTH:
            if (y > hopLength - 1) y -= hopLength;
            else y = 0;
            break;
        case EAST:
            if (x < 10 - hopLength) x += hopLength;
            else x = 9;
            break;
        case SOUTH:
            if (y < 10 - hopLength) y += hopLength;
            else y = 9;
            break;
        case WEST:
            if (x > hopLength - 1) x -= hopLength;
            else x = 0;
            break;
    }
}
