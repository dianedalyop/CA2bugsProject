#include "Crawler.h"
#include "Bug.h"

Crawler::Crawler(char t, int id, int xx, int yy, Direction d, int s)
        : Bug(t, id, xx, yy, d, s) {}

void Crawler::move() {
    switch (direction) {
        case NORTH:
            if (y > 0) y--;
            break;
        case EAST:
            if (x < 9) x++;
            break;
        case SOUTH:
            if (y < 9) y++;
            break;
        case WEST:
            if (x > 0) x--;
            break;
    }
}
