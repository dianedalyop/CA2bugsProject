#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(char t, int id, int xx, int yy, Direction d, int s, int h);
    void display() override;
    void move() override;
};

#endif // HOPPER_H
