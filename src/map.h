#pragma once
#include <vector>
#include "objects.h"
#include "point.h"

class Map
{
public:
    int rows, cols;
    Map() {};
    Map(const char *name_map);
    SnakeHead* snakeHead;
    std::vector< std::vector<Object*> > map;
    std::vector<Bonus*> bonuses;
    Point findFreePlace(Point lp, Point rp);
    void addObject(Object* obj);
    void print(WINDOW *win);
};
