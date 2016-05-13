#include "gamemanager.h"

GameManager::GameManager()
{
	this->map = Map(name_map);
}

GameManager& GameManager::instance()
{
	static GameManager manager();
	return manager;
}

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

void GameManager::createGrids()
{
	this->game_win = newwin(30, 60, 0, 0);
	this->info_win = newwin(30, 20, 0, 61);
	keypad(this->game_win, TRUE);
}

void GameManager::deleteGrids()
{
	delwin(this->game_win);
	delwin(this->info_win);
}

void GameManager::refreshGrid()
{
    this->map.printMap(this->game_win);
    this->refreshInfo();
};

void GameManager::refreshInfo()
{

};

int GameManager::keyCallback(int key)
{
	switch(key)
	{
		case KEY_UP:
			break;
		case KEY_DOWN:
			break;
		case KEY_RIGHT:
			break;
		case KEY_LEFT:
			break;
		case 27: return 1;
	}
	return 0;
};

void GameManager::gameLoop()
{

};

void GameManager::freeResources()
{

};

void initColorPairs()
{
	init_pair(WALL_COLOR, 0, 0);
	init_pair(GROUND_COLOR, 7, 7);
	init_pair(KNIGHT_COLOR, 1, 7);
	init_pair(PRINCESS_COLOR, 7, 5);
	init_pair(ZOMBIE_COLOR, 2, 7);
	init_pair(DRAGON_COLOR, 1, 0);
	init_pair(ZOMBIES_SPAWN_COLOR, 0, 2);
	init_pair(DRAGONS_SPAWN_COLOR, 0, 1);
	init_pair(WIZARD_COLOR, 7, 4);
	init_pair(BASE_COLOR, 7, 0);
}

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
