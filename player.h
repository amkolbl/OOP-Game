#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

/* 
		AnnMarie Kolbl
ID: 3079881 | ak192@zips.uakron.edu
OOP Final Project: Halloween Game
		<player.h>
*/
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


/*move Function: accepts an array of chars, and a char.
Checks to see what direction the user indicated, makes
sure that the move is "legal", then moves the player
accordingly. Returns nothing. */
void Player::move(char gameArray[R][C], char input)
{
	//if the user input left
	if(input == 'a')
	{
		if(p.yCoord - 1 > 0)
		{
			if(gameArray[p.xCoord][p.yCoord - 1] != '#')
			{
				gameArray[p.xCoord][p.yCoord] = '*';
				gameArray[p.xCoord][p.yCoord - 1] = '+';
			}
		}
	}
	//if the user input right
	else if(input == 'd')
	{
		if(p.yCoord + 1 < 29 && p.yCoord + 1 != '#')
		{
			if(gameArray[p.xCoord][p.yCoord + 1] != '#')
			{
				gameArray[p.xCoord][p.yCoord] = '*';
				gameArray[p.xCoord][p.yCoord + 1] = '+';
			}	
		}
	}
	//if the user input up
	else if(input == 'w')
	{
		if(p.xCoord - 1 > 0 && p.xCoord - 1 != '#')
		{
			if(gameArray[p.xCoord - 1][p.yCoord] != '#')
			{
				gameArray[p.xCoord][p.yCoord] = '*';
				gameArray[p.xCoord - 1][p.yCoord] = '+';
			}
		}	
	}
	//if the user input down
	else if(input == 's')
	{
		if(p.xCoord + 1 < 11 && p.xCoord + 1 != '#')
		{
			if(gameArray[p.xCoord + 1][p.yCoord] != '#')
			{			
				gameArray[p.xCoord][p.yCoord] = '*';
				gameArray[p.xCoord + 1][p.yCoord] = '+';
			}
		}
	}
}


#endif // PLAYER_H_INCLUDED
