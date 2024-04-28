#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Bug.h"

class Board {
private:
    std::vector<Bug*> bugs;
public:
    const std::vector<Bug *> &getBugs() const;

public:
    void addBug(Bug* bug);
    void displayBugs();
    void moveBugs();
    Bug* findBugByID(int id);
    void bugsInteraction();

    static constexpr int BOARD_WIDTH = 10;
    static constexpr int BOARD_HEIGHT = 10;
};

#endif // BOARD_H
