#ifndef BUG_H
#define BUG_H



#include <vector>
#include <utility>

enum Direction {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};

class Bug {
protected:
    char type;
    int bugID;
    int x, y;
    Direction direction;
    int size;
    std::vector<std::pair<int, int>> pathHistory;

public:
    Bug(char t, int id, int xx, int yy, Direction d, int s);
    virtual ~Bug() {}

    virtual void display();
    virtual void move() = 0;

    int getBugID() const;

    int getX() const;

    int getY() const;


    void addPosHistory();

    void displayPathHistory();

    int getSize() const;
};

#endif // BUG_H
