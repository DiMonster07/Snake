#include "objects.h"

Point Object::get_point()
{
    return this->point;
};

void Object::set_point(int x, int y)
{
    this->point.x = x;
    this->point.y = y;
};

void Object::set_point(Point p)
{
    this->point = p;
};

int SnakeHead::get_color()
{
    return SNAKE_HEAD_COLOR;
};

char SnakeHead::get_symbol()
{
    return SNAKE_HEAD_SYMBOL;
};

int SnakeBody::get_color()
{
    return SNAKE_BODY_COLOR;
};

char SnakeBody::get_symbol()
{
    return SNAKE_BODY_SYMBOL;
};

int Bonus::get_color()
{
    return BONUS_COLOR;
};

char Bonus::get_symbol()
{
    return BONUS_SYMBOL;
};
