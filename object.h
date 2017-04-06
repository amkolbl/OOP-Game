#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "location.h"

using namespace std;
class Object
{
public:
    virtual void setLocation(int x, int y) { }
    virtual Location getLocation();

};

class Pumpkin : Object
{
private:

    Location p;

public:

    void setLocation(int x, int y)
    {
        p.xCoord = x;
        p.yCoord = y;
    }

    Location getLocation()
        { return p; }
};

class Lantern : Object
{
private:

    Location l;

public:

    void setLocation(int x, int y)
    {
        l.xCoord = x;
        l.yCoord = y;
    }
    Location getLocation()
        { return l; }
};

class Candy : Object
{
private:

    Location c;

public:

    void setLocation(int x, int y)
    {
        c.xCoord = x;
        c.yCoord = y;
    }

    Location getLocation()
        { return c; }
};


#endif // OBJECT_H_INCLUDED
