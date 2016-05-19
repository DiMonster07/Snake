#pragma once
#include "meta.h"


class Object
{
protected:
    Point point;
public:
    Object() { point.x = point.y = 0; };
    Object(int x, int y) { point.x = x; point.y = y; };
    Object(Point p) : point(p) { };
    virtual ~Object() { };
    Point get_point();
	void set_point(int x, int y);
	void set_point(Point p);
    virtual int get_color() {};
    virtual char get_symbol() {};
};

class SnakeObj: public Object
{
public:
    SnakeObj() : Object() { };
    SnakeObj(int x, int y) : Object(x, y) { };
    SnakeObj(Point p) : Object(p) { };
};

class SnakeHead: public SnakeObj
{
private:
    int bonus_count = 0;
public:
    SnakeHead() : SnakeObj() { };
    SnakeHead(int x, int y) : SnakeObj(x, y) { };
    SnakeHead(Point p) : SnakeObj(p) { };
    int get_color();
    char get_symbol();
};

class SnakeBody: public SnakeObj
{
public:
    SnakeBody() : SnakeObj() { };
    SnakeBody(int x, int y) : SnakeObj(x, y) { };
    SnakeBody(Point p) : SnakeObj(p) { };
    int get_color();
    char get_symbol();
};

class Bonus: public Object
{
private:
    int valBonus;
public:
    Bonus() : Object() { };
    Bonus(int x, int y) : Object(x, y) { };
    Bonus(Point p) : Object(p) { };
    int get_color();
    char get_symbol();
};
