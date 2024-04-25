#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Bug.h"

class Board {
private:
    std::vector<Bug*> bugs;

public:
    void addBug(Bug* bug);
    void displayBugs();
    void moveBugs();
};

#endif // BOARD_H
