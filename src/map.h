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
    std::vector<Object*> bonuses;
    Point findFreePlace(Point lp, Point rp);
    void addObject(Object* obj);
    void addBonus(Bonus* bonus);
    void deleteBonus(Object* bonus);
    int get_bonus_count();
    void print(WINDOW *win);
};
