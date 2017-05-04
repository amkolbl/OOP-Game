#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
/* 
		AnnMarie Kolbl
ID: 3079881 | ak192@zips.uakron.edu
OOP Final Project: Halloween Game
		<object.h>
*/
#include "location.h"

using namespace std;
class Object
{
private:
	Location location;
	
public:
    virtual void setLocation(int, int);
    virtual Location getLocation();

};

void Object::setLocation(int x, int y)
{
	location.xCoord = x;
	location.yCoord = y;	
}

Location Object::getLocation()
{
	return location;
}


class Candy : Object
{
private:
    Location location;
};


class Pumpkin : Object
{
private:
    Location location;
};


/*
class Lantern : Object
{
private:
	Location location;
};
*/

#endif // OBJECT_H_INCLUDED
