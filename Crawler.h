#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler(char t, int id, int xx, int yy, Direction d, int s);
    void move() override;
};

#endif // CRAWLER_H
