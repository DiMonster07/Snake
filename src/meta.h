#pragma once
#include <ncurses.h>
#include <panel.h>
#include <vector>
#include "point.h"

#define GROUND_SYMBOL '.'
#define WALL_SYMBOL '#'
#define SNAKE_HEAD_SYMBOL 'S'
#define SNAKE_BODY_SYMBOL 's'
#define BONUS_SYMBOL 'B'

class Map;
class Object;
class SnakeObj;
class SnakeHead;
class SnakeBody;
class Bonus;

enum COLORS_UNITS
{
	WALL_COLOR = 1,
	GROUND_COLOR = 2,
	SNAKE_HEAD_COLOR = 3,
	SNAKE_BODY_COLOR = 4,
	BONUS_COLOR = 5,
	BASE_COLOR = 6
};
