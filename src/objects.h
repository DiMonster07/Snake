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
    // virtual void collide(Object* object) = 0;
    // virtual void collide(SnakeHead* snakehead) = 0;
    // virtual void collide(SnakeBody* snakebody) = 0;
    // virtual void collide(Wall* wall) = 0;
    // virtual void collide(Ground* ground) = 0;
    // virtual void collide(Bonus* bonus) = 0;
};

class SnakeObj: public Object
{
public:
    SnakeObj() : Object() { };
    SnakeObj(Point p) : Object(p) { };
};

class SnakeBody: public SnakeObj
{
public:
    SnakeBody() : SnakeObj() { };
    SnakeBody(Point p) : SnakeObj(p) { };
    int get_color();
    char get_symbol();
    void collide(Object* object);
};

class SnakeHead: public SnakeObj
{
protected:
    Point direction;
    bool is_life = true;
public:
    std::deque<SnakeBody*> body;
    SnakeHead() : SnakeObj() { };
    SnakeHead(Point p) : SnakeObj(p)
    {
    	this->body.push_back(new SnakeBody(START_POSITION + Point(0, -1)));
    	this->body.push_back(new SnakeBody(START_POSITION + Point(0, -2)));
    };
    int get_color();
    char get_symbol();
    bool is_died();
    SnakeBody* addBodyPart(SnakeBody* bp);
    Point get_direction();
    void set_direction(Point p);
    void move(Map* map);
    // void collide(Object* object);
    // void collide(SnakeHead* snakehead) {};
    // void collide(SnakeBody* snakebody);
    // void collide(Bonus* bonus);
    // void collide(Wall* wall);
    // void collide(Ground* ground);
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
    void collide(Object* object);
};

class Ground: public Environment
{
public:
	Ground() : Environment() { };
    Ground(Point p) : Environment(p) { };
	int get_color();
	char get_symbol();
    void collide(Object* object);
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
    void collide(Object* object);
};
