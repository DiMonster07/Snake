#pragma once
#include <ncurses.h>
#include <panel.h>
#include <vector>
#include "map.h"

class GameManager
{
private:
	WINDOW *game_win, *info_win;
public:
	bool is_end_game = false;
	GameManager();
	static GameManager& instance();
	void initConsole();
	void createGrids();
	void deleteGrids();
	void refreshGrid();
	void refreshInfo();
	int keyCallback(int key);
	void gameLoop();
	void freeResources();
};
