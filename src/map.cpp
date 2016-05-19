#include "map.h"
#include "objects.h"
#include <fstream>

Map::Map(const char* name_map)
{
    std::ifstream input(name_map);
	char c;
	input >> this->rows;
	input >> this->cols;
	for (int i = 0; i < this->rows; i++)
	{
		std::vector<Object*> row;
		for (int j = 0; j < this->cols; j++)
		{
			input >> c;
			switch(c)
			{
				case WALL_SYMBOL:
					break;
				case GROUND_SYMBOL:
					break;
			}
		}
		map.push_back(row);
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
}
