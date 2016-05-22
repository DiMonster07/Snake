#include "gamemanager.h"
#include "point.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
const char *dir = "../src/map.txt";

void initColorPairs();

bool GameManager::snakeMove()
{
	return this->map.snakeHead->move(&(this->map));
};

void GameManager::gameLoop()
{
	this->snakeCreate();
	this->refreshGrid();
	halfdelay(1);
	while (!this->snake_is_died())
	{
		int command = wgetch(this->game_win);
		if (this->keyCallback(command)) break;
		if (this->snakeMove()) this->bonusGen();
		this->refreshGrid();
	}

};

bool GameManager::snake_is_died()
{
	if (this->map.snakeHead->is_died()) return true;
	else return false;
};

void GameManager::snakeCreate()
{
	this->map.snakeHead = new SnakeHead(START_POSITION);
	this->map.snakeHead->set_direction(RIGHT_DIRECTION);
	this->map.addObject(this->map.snakeHead);
	this->map.addObject(this->map.snakeHead->body[0]);
	this->map.addObject(this->map.snakeHead->body[1]);
};

void GameManager::bonusGen()
{
	if (this->map.get_bonus_count() == 0)
	{
		this->map.addObject(new Bonus(
			this->map.findFreePlace(LEFT_ANG, RIGHT_ANG)));
	}
};

int GameManager::keyCallback(int key)
{
	switch(key)
	{
		case KEY_UP:
			this->map.snakeHead->set_direction(UP_DIRECTION);
			break;
		case KEY_DOWN:
			this->map.snakeHead->set_direction(DOWN_DIRECTION);
			break;
		case KEY_RIGHT:
			this->map.snakeHead->set_direction(RIGHT_DIRECTION);
			break;
		case KEY_LEFT:
			this->map.snakeHead->set_direction(LEFT_DIRECTION);
			break;
		case 27: return 1;
	}
	return 0;
};

GameManager::GameManager(const char* name_map)
{
	this->map = Map(name_map);
};

GameManager& GameManager::instance()
{
	static GameManager manager(dir);
	return manager;
};

void GameManager::createGrids()
{
	this->game_win = newwin(30, 90, 0, 0);
	this->info_win = newwin(30, 20, 0, 91);
	keypad(this->game_win, TRUE);
};

void GameManager::deleteGrids()
{
	delwin(this->game_win);
	delwin(this->info_win);
};

void GameManager::refreshGrid()
{
    this->map.print(this->game_win);
    this->refreshInfo();
};

void GameManager::refreshInfo()
{
	wclear(this->info_win);
	mvwprintw(this->info_win, 1, 0, "Score: %d",
		this->map.snakeHead->get_bonus_count());
	wrefresh(this->info_win);
};

void GameManager::initConsole()
{
    initscr();
	noecho();
	curs_set(FALSE);
	cbreak();
	start_color();
	initColorPairs();
	clear();
	srand(time(0));
};

void initColorPairs()
{
	init_pair(WALL_COLOR, 0, 0);
	init_pair(GROUND_COLOR, 7, 7);
    init_pair(SNAKE_HEAD_COLOR, 2, 0);
	init_pair(SNAKE_BODY_COLOR, 2, 2);
    init_pair(BONUS_COLOR, 5, 5);
	init_pair(BASE_COLOR, 7, 0);
};

/*
		COLOR_BLACK   0
        COLOR_RED     1
        COLOR_GREEN   2
        COLOR_YELLOW  3
        COLOR_BLUE    4
        COLOR_MAGENTA 5
        COLOR_CYAN    6
        COLOR_WHITE   7
*/
