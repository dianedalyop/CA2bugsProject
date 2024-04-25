#include <iostream>
#include <fstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
using namespace std;

int main() {
    std::ifstream inputFile("bugs2.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    Board board;
    char type;
    int bugID, x, y, direction, size, hopLength;

    while (inputFile >> type >> bugID >> x >> y >> direction >> size) {
        Direction dir = static_cast<Direction>(direction);
        if (type == 'C') {
            board.addBug(new Crawler(type, bugID, x, y, dir, size));
        } else if (type == 'H') {
            inputFile >> hopLength;
            board.addBug(new Hopper(type, bugID, x, y, dir, size, hopLength));
        }
    }

    board.displayBugs();
    board.moveBugs();
    std::cout << "\nAfter moving:\n";
    board.displayBugs();

    // find bug by ID
    int bugtofind ;
    cout<<"Enter bug ID"<<endl;
    cin>>bugtofind;

    Bug* found_bug = board.findBugByID(bugtofind);
    if(found_bug){
        cout<< " Bug with ID "<< bugtofind << " Found " << endl;
        found_bug->display();
    }
    else {
        cout<< " Bug with ID "<< bugtofind << "Not Found " << endl;
    }

    inputFile.close();

    return 0;
}
