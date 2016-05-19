#pragma once
#include "meta.h"
#include "map.h"

class GameManager
{
private:
	WINDOW *game_win, *info_win;
public:
	Map map;
	GameManager() {};
	GameManager(const char* name_map);
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
