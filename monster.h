#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

/* 
		AnnMarie Kolbl
ID: 3079881 | ak192@zips.uakron.edu
OOP Final Project: Halloween Game
		<monster.h>
*/
#include "location.h"

using namespace std;

class Monster
{
public:
    Location location;

    virtual void monsterMove(char gameArray[R][C], char input, Location pLoc);
    void setLocation(int x, int y);
    Location getLocation();
};

/*monsterMove Function: accepts a character array, a char, and a 
Location variable. Checks to see if the monster and the player are
in the same location and returns if true. If false, moves the monster
accordingly and updates its position in the array. Returns nothing. */
void Monster::monsterMove(char gameArray[R][C], char input, Location pLoc)
{
	Location mLoc = getLocation();
	
	//if they are in the same position
	if(mLoc.xCoord == pLoc.xCoord && mLoc.yCoord == pLoc.yCoord)
		return;
	
	//if the player went left or right
	if(input == 'a' || input == 'd')
	{
		//if the monster is to the right of the player
		if(mLoc.yCoord > pLoc.yCoord)
		{
			if(location.yCoord - 1 > 0)
			{
				if(gameArray[location.xCoord][location.yCoord - 1] != '#')
				{
					gameArray[location.xCoord][location.yCoord] = '*';					
					gameArray[location.xCoord][location.yCoord - 1] = 'W';	
				}	
			}
		}	
		else 
		{
			if(location.yCoord + 1 < 29)
			{
				if(gameArray[location.xCoord][location.yCoord + 1] != '#')
				{
					gameArray[location.xCoord][location.yCoord] = '*';
					gameArray[location.xCoord][location.yCoord + 1] = 'W';	
				}
			}
		}
	}
	//if the player went up or down
	else if(input == 'w' || input == 's')
	{
		//if the player is above the monster
		if(mLoc.xCoord > pLoc.xCoord)
		{
			if(location.xCoord - 1 > 0)
			{
				if(gameArray[location.xCoord - 1][location.yCoord] != '#')
				{
					gameArray[location.xCoord][location.yCoord] = '*';
					gameArray[location.xCoord - 1][location.yCoord] = 'W';
				}
			}	
		}
		else
		{
			if(location.xCoord + 1 < 11)
			{
				if(gameArray[location.xCoord + 1][location.yCoord] != '#')
				{
					gameArray[location.xCoord][location.yCoord] = '*';
					gameArray[location.xCoord + 1][location.yCoord] = 'W';
				}	
			}
		}
	}
}


/*setLocation Function: accepts two integers,
initializes the private location variables,
Returns nothing. */
void Monster::setLocation(int x, int y)
{
	location.xCoord = x;
	location.yCoord = y;
}

/*getLocation Function: accepts nothing.
Returns the monster location */
Location Monster::getLocation()
{
	return location;
}


class Witch : public Monster
{
private:
	Location location;
};



class Zombie : public Monster
{
private:
	Location location;
	
public:
	void monsterMove(char gameArray[R][C], char input, Location pLoc) override;
};


/*Overridden monsterMove Function: same as above, only difference
is substituting 'Z' for 'W'
*/
void Zombie::monsterMove(char gameArray[R][C], char input, Location pLoc)
{
	Location mLoc = getLocation();
	
	if(mLoc.xCoord == pLoc.xCoord && mLoc.yCoord == pLoc.yCoord)
		return;
	
	if(input == 'a' || input == 'd')
	{
		if(mLoc.yCoord > pLoc.yCoord)
		{
			if(location.yCoord - 1 > 0)
			{
				gameArray[location.xCoord][location.yCoord] = '*';					
				gameArray[location.xCoord][location.yCoord - 1] = 'Z';	
			}
			
		}	
		else 
		{
			if(location.yCoord + 1 < 29)
			{
				gameArray[location.xCoord][location.yCoord] = '*';
				gameArray[location.xCoord][location.yCoord + 1] = 'Z';	
			}
		}
	}
	else if(input == 'w' || input == 's')
	{
		if(mLoc.xCoord > pLoc.xCoord)
		{
			if(location.xCoord - 1 > 0)
			{
				gameArray[location.xCoord][location.yCoord] = '*';
				gameArray[location.xCoord - 1][location.yCoord] = 'Z';
			}	
		}
		else
		{
			if(location.xCoord + 1 < 11)
			{
				gameArray[location.xCoord][location.yCoord] = '*';
				gameArray[location.xCoord + 1][location.yCoord] = 'Z';
			}
		}
	}
}

/*
class Horseman : public Monster
{
private:
	Location location;
};
*/




#endif // MONSTER_H_INCLUDED
