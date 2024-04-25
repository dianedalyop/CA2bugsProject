#include "Board.h"
#include <iostream>
using namespace std;

void Board::addBug(Bug* bug) {
    bugs.push_back(bug);
}

void Board::displayBugs() {
    cout<<"Bug Initial Details"<<endl;
    for (Bug* bug : bugs) {
        bug->display();
        std::cout << "\n";
    }
}

void Board::moveBugs() {
    for (Bug* bug : bugs) {
        bug->move();
    }
}
