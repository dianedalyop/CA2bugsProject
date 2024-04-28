#include "Board.h"
#include <iostream>
using namespace std;


void Board::addBug(Bug* bug) {
    bugs.push_back(bug);
}
// displaying my bugs
void Board::displayBugs() {
    cout<<"Bug Initial Details"<<endl;
    for (Bug* bug : bugs) {
        bug->display();
        std::cout << "\n";
    }
}
// moving bugs
void Board::moveBugs() {
    for (Bug* bug : bugs) {
        bug->move();
    }
}

// find bug by ID

Bug* Board::findBugByID (int id) {
    for(Bug* bug: bugs) {
        if(bug->getBugID() == id){
            return bug;
        }
    }
    return nullptr;
}

void Board::bugsInteraction() {
    std::cout << "Checking for bug interactions...\n";
    for (size_t i = 0; i < bugs.size(); ++i) {
        for (size_t j = i + 1; j < bugs.size(); ++j) {
            if (bugs[i]->getX() == bugs[j]->getX() && bugs[i]->getY() == bugs[j]->getY()) {
                std::cout << "Collision detected between Bug " << bugs[i]->getBugID() << " and Bug " << bugs[j]->getBugID() << "\n";
                // Handle collision logic here
            }

        }
    }

        std::cout << "No More bug interactions Detected " << endl;

}

const vector<Bug *> &Board::getBugs() const {
    return bugs;
}




