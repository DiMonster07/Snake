#include "objects.h"
#include "map.h"

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

Point SnakeHead::get_direction()
{
    return this->direction;
};

void SnakeHead::set_direction(Point p)
{
    this->direction = p;
};

bool SnakeHead::is_died()
{
    return !is_life;
};

void SnakeHead::move(Map* map)
{
    Point pnt = this->point;
	Point newpnt = pnt + this->direction;
    this->body.push_front(new SnakeBody(pnt));
	map->map[pnt.x][pnt.y] = this->body.front();
    map->snakeHead->set_point(newpnt);
	map->map[newpnt.x][newpnt.y] = map->snakeHead;
    pnt = this->body.back()->get_point();
    delete map->map[pnt.x][pnt.y];
    map->map[pnt.x][pnt.y] = new Ground(pnt);
    this->body.pop_back();
};

SnakeBody* SnakeHead::addBodyPart(SnakeBody* bp)
{
    this->body.push_front(bp);
    return bp;
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

int Ground::get_color()
{
    return GROUND_COLOR;
};

char Ground::get_symbol()
{
    return GROUND_SYMBOL;
};

int Wall::get_color()
{
    return WALL_COLOR;
};

char Wall::get_symbol()
{
    return WALL_SYMBOL;
};

int Bonus::get_color()
{
    return BONUS_COLOR;
};

char Bonus::get_symbol()
{
    return BONUS_SYMBOL;
};
