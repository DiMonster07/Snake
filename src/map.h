#pragma once
#include <vector>
#include "objects.h"

class Map
{
private:
    int rows, cols;
public:
    Map() {};
    Map(const char *name_map);
    std::vector< std::vector<Object*> > map;
    void print(WINDOW *win);
};
