#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "location.h"

using namespace std;

class Player
{
private:
    Location p;

public:

    void move(char gameArray[R][C], char);
    void setLocation(int x, int y)
	{
		p.xCoord = x;
		p.yCoord = y;
	}
    Location getLocation() { return p; }
};

void Player::move(char gameArray[R][C], char input)
{
	if(input == 'a')
	{
		if(p.yCoord - 1 > 0)
		{
			gameArray[p.xCoord][p.yCoord] = '*';
			gameArray[p.xCoord][p.yCoord - 1] = '+';
		}
	}
	else if(input == 'd')
	{
		if(p.yCoord + 1 < 29)
		{
			gameArray[p.xCoord][p.yCoord] = '*';
			gameArray[p.xCoord][p.yCoord + 1] = '+';
		}
	}
	else if(input == 'w')
	{
		if(p.xCoord - 1 > 0)
		{
			gameArray[p.xCoord][p.yCoord] = '*';
			gameArray[p.xCoord - 1][p.yCoord] = '+';
		}			
	}
	else if(input == 's')
	{
		if(p.xCoord + 1 < 11)
		{
			gameArray[p.xCoord][p.yCoord] = '*';
			gameArray[p.xCoord + 1][p.yCoord] = '+';
		}			
	}
}


#endif // PLAYER_H_INCLUDED
