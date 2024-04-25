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
