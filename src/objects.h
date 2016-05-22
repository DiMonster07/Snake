#pragma once
#include "meta.h"

class Object
{
protected:
    Point point;
public:
    Object() { point.x = point.y = 0; };
    Object(Point p) : point(p) { };
    virtual ~Object() { };
    Point get_point();
	void set_point(int x, int y);
	void set_point(Point p);
    virtual int get_color() {};
    virtual char get_symbol() {};
    virtual int collide(Object* object) = 0;
    virtual int collide(SnakeHead* snakehead) { };
    virtual int collide(SnakeBody* snakebody) { };
    virtual int collide(Wall* wall) { };
    virtual int collide(Ground* ground) { };
    virtual int collide(Bonus* bonus) { };
};

class Snake: public Object
{
public:
    Snake() : Object() { };
    Snake(Point p) : Object(p) { };
};

class SnakeBody: public Snake
{
public:
    SnakeBody() : Snake() { };
    SnakeBody(Point p) : Snake(p) { };
    int get_color();
    char get_symbol();
    int collide(Object* object);
    int collide(SnakeHead* snakehead);
};

class SnakeHead: public Snake
{
protected:
    Point direction;
    bool is_life = true;
    int bonus_count;
public:
    std::deque<SnakeBody*> body;
    std::deque<Point>stomach;
    SnakeHead() : Snake() { };
    SnakeHead(Point p) : Snake(p)
    {
    	this->body.push_back(new SnakeBody(START_POSITION + Point(0, -1)));
    	this->body.push_back(new SnakeBody(START_POSITION + Point(0, -2)));
    };
    int get_color();
    char get_symbol();
    int get_bonus_count();
    bool is_died();
    SnakeBody* addBodyPart(SnakeBody* bp);
    Point get_direction();
    void set_direction(Point p);
    void bonusEated(Point point);
    bool move(Map* map);
    int collide(Object* object);
};

class Environment: public Object
{
public:
	Environment() : Object() { };
    Environment(Point p) : Object(p) { };
};

class Wall: public Environment
{
public:
	Wall() : Environment() { };
    Wall(Point p) : Environment(p) { };
	int get_color();
	char get_symbol();
    int collide(Object* object);
    int collide(SnakeHead* snakehead);
};

class Ground: public Environment
{
public:
	Ground() : Environment() { };
    Ground(Point p) : Environment(p) { };
	int get_color();
	char get_symbol();
    int collide(Object* object);
    int collide(SnakeHead* snakehead);
};

class Bonus: public Object
{
private:
    int valBonus;
public:
    Bonus() : Object() { };
    Bonus(Point p) : Object(p) { };
    int get_color();
    char get_symbol();
    int collide(Object* object);
    int collide(SnakeHead* snakehead);
};
