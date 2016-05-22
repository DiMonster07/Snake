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

bool SnakeHead::move(Map* map)
{
    Point pnt = this->point;
	Point newpnt = pnt + this->direction;
    if (this->collide(map->map[newpnt.x][newpnt.y]))
    {
        if (map->map[newpnt.x][newpnt.y]->get_symbol() == BONUS_SYMBOL)
        {
            map->deleteBonus(map->map[newpnt.x][newpnt.y]);
            this->stomach.push_back(newpnt);
        }
        map->snakeHead->set_point(newpnt);
        delete map->map[newpnt.x][newpnt.y];
    	map->map[newpnt.x][newpnt.y] = map->snakeHead;
        this->body.push_front(new SnakeBody(pnt));
    	map->map[pnt.x][pnt.y] = this->body.front();
        pnt = this->body.back()->get_point();
        delete map->map[pnt.x][pnt.y];
        map->map[pnt.x][pnt.y] = new Ground(pnt);
        this->body.pop_back();
        if (this->stomach.size() > 0 && pnt == this->stomach.back())
        {
            this->body.push_back(new SnakeBody(pnt));
        	map->map[pnt.x][pnt.y] = this->body.back();
            this->stomach.pop_front();
        }
    } else
    {
        this->is_life = false;
        return false;
    }
    return true;
};

int SnakeHead::get_bonus_count()
{
    return this->bonus_count;
};

SnakeBody* SnakeHead::addBodyPart(SnakeBody* bp)
{
    this->body.push_front(bp);
    return bp;
};

void SnakeHead::bonusEated(Point point)
{
    this->bonus_count++;
    this->stomach.push_back(point);
};

int SnakeHead::collide(Object* object)
{
    return object->collide(this);
};

int SnakeHead::get_color()
{
    return SNAKE_HEAD_COLOR;
};

char SnakeHead::get_symbol()
{
    return SNAKE_HEAD_SYMBOL;
};

int SnakeBody::collide(Object* object)
{
    return object->collide(this);
};

int SnakeBody::collide(SnakeHead* snakehead)
{
    return 0;
};

int SnakeBody::get_color()
{
    return SNAKE_BODY_COLOR;
};

char SnakeBody::get_symbol()
{
    return SNAKE_BODY_SYMBOL;
};

int Ground::collide(Object* object)
{
    return object->collide(this);
};

int Ground::collide(SnakeHead* snakehead)
{
    return 1;
};

int Ground::get_color()
{
    return GROUND_COLOR;
};

char Ground::get_symbol()
{
    return GROUND_SYMBOL;
};

int Wall::collide(Object* object)
{
    return object->collide(this);
};

int Wall::collide(SnakeHead* snakehead)
{
    return 0;
};

int Wall::get_color()
{
    return WALL_COLOR;
};

char Wall::get_symbol()
{
    return WALL_SYMBOL;
};

int Bonus::collide(Object* object)
{
    return object->collide(this);
};

int Bonus::collide(SnakeHead* snakehead)
{
    snakehead->bonusEated(this->point);
    return 1;
};

int Bonus::get_color()
{
    return BONUS_COLOR;
};

char Bonus::get_symbol()
{
    return BONUS_SYMBOL;
};
