#include "map.h"
#include "objects.h"
#include <fstream>

Map::Map(const char* name_map)
{
    std::ifstream input(name_map);
	input >> this->rows;
	input >> this->cols;
    char c;
	for (int i = 0; i < this->rows; i++)
	{
		std::vector<Object*> row;
		for (int j = 0; j < this->cols; j++)
		{
			input >> c;
			switch(c)
			{
				case WALL_SYMBOL:
                    row.push_back(new Wall(Point(i, j)));
					break;
				case GROUND_SYMBOL:
                    row.push_back(new Ground(Point(i, j)));
					break;
			}
		}
		map.push_back(row);
	}
};

void Map::addObject(Object* obj)
{
    Point p = obj->get_point();
    delete this->map[p.x][p.y];
    this->map[p.x][p.y] = obj;
};

Point Map::findFreePlace(Point lp, Point rp)
{
	int c = 0;
	for (int i = lp.x; i <= rp.x; i++)
		for (int j = lp.y; j <= rp.y; j++)
			if (this->map[i][j]->get_symbol() == GROUND_SYMBOL) c++;
	int num = rand() % c + 1;
	c = 0;
	for (int i = lp.x; i <= rp.x; i++)
		for (int j = lp.y; j <= rp.y; j++)
		{
			if (this->map[i][j]->get_symbol() == GROUND_SYMBOL) c++;
			if (c == num) return this->map[i][j]->get_point();
		}
};

void Map::print(WINDOW *win)
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			wattron(win, COLOR_PAIR(this->map[i][j]->get_color()));
			mvwprintw(win, i, j, "%c", this->map[i][j]->get_symbol());
		}
	}
	wattron(win, COLOR_PAIR(BASE_COLOR));
};
