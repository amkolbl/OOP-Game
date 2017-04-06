#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include "location.h"

using namespace std;

class Monster
{
private:
    Location location;
public:

    virtual void monsterMove(int x, int y);
    void setLocation(int x, int y)
	{
		location.xCoord = x;
		location.yCoord = y;
	}
    Location getLocation() { return location; }
};

class Zombie : Monster
{
private:
	Location location;
	
public:
    //will be overridden
    void monsterMove();
};

class Witch : Monster
{
private:
	Location location;
public:

    //will be overridden
    void monsterMove();

};

class Horseman : Monster
{
private:
	Location location;
public:

    void monsterMove();
};

#endif // MONSTER_H_INCLUDED
