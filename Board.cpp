#include "Board.h"
#include <iostream>
#include "Bug.h"
using namespace std;


void Board::addBug(Bug* bug) {
    bugs.push_back(bug);
}
// displaying my bugs
void Board::displayBugs() const {
    cout<<"Bug Initial Details"<<endl;
    for (Bug* bug : bugs) {
        bug->display();
        std::cout << " : ";
    }
}
// moving bugs
void Board::moveBugs() const{
    for (Bug* bug : bugs) {
        bug->move();
    }
}

// find bug by ID

Bug* Board::findBugByID (int id) const {
    for(Bug* bug: bugs) {
        if(bug->getBugID() == id){
            return bug;
        }
    }
    return nullptr;
}

void Board::bugsInteraction() {
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            std::vector<Bug *> bugsInCell = getBugs();


            if (bugsInCell.size() > 1) {
                Bug *largestBug = bugsInCell[0];
                for (size_t i = 1; i < bugsInCell.size(); ++i) {
                    if (bugsInCell[i]->getSize() > largestBug->getSize()) {
                        largestBug = bugsInCell[i];
                    }
                }

                // result of the fight
                std::cout << "Bug " << largestBug->getBugID() << " wins in cell (" << x << ", " << y << ") against:";
                for (size_t i = 0; i < bugsInCell.size(); ++i) {
                    if (bugsInCell[i] != largestBug) {
                        std::cout << " Bug " << bugsInCell[i]->getBugID();
                    }
                }
                std::cout << std::endl;
            }
        }
    }
}

const vector<Bug *> &Board::getBugs() const {
    return bugs;
}




