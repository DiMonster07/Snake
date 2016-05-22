#pragma once
#include <ncurses.h>
#include <panel.h>
#include <vector>
#include <deque>
#include "point.h"

#define GROUND_SYMBOL '.'
#define WALL_SYMBOL '#'
#define SNAKE_HEAD_SYMBOL 'S'
#define SNAKE_BODY_SYMBOL 's'
#define BONUS_SYMBOL 'B'

#define LEFT_ANG Point(1, 1)
#define RIGHT_ANG Point(28, 88)
#define START_POSITION Point(14, 44)
#define UP_DIRECTION Point(-1, 0)
#define DOWN_DIRECTION Point(1, 0)
#define LEFT_DIRECTION Point(0, -1)
#define RIGHT_DIRECTION Point(0, 1)

enum COLORS_UNITS
{
	WALL_COLOR = 1,
	GROUND_COLOR = 2,
	SNAKE_HEAD_COLOR = 3,
	SNAKE_BODY_COLOR = 4,
	BONUS_COLOR = 5,
	BASE_COLOR = 6
};

class Map;
class Object;
class SnakeObj;
class SnakeHead;
class SnakeBody;
class Wall;
class Ground;
class Bonus;
