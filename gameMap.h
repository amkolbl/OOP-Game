#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

/* 
		AnnMarie Kolbl
ID: 3079881 | ak192@zips.uakron.edu
OOP Final Project: Halloween Game
		<gameMap.h>
*/
#include "location.h"
#include "monster.h"
#include "object.h"
#include "player.h"

class gameMap
{
private:
    Player player;
	Witch witch;
	Zombie zombie;
	Object candy;
	Object pumpkin;
	Location endPoint;
    char gameArray[R][C];
	char dInput;

public:
    bool readArray(string);
	void checkGameState(bool&, bool&, bool&);
	void printInstructions();
	void printMap();
	
	void setEndPoint();
	void setPlayerLocation();
	void setWitchLocation();
	void setZombieLocation();
	void setCandyLocation();
	void setPumpkinLocation();
	
	Location getEndLocation();
	Location getPlayerLocation();
	Location getWitchLocation();
	Location getZombieLocation();
	Location getCandyLocation();
	Location getPumpkinLocation();
	
	void getDirectionInput();
	void movePlayer();
	void moveWitch();
	void moveZombie();
	
};

#endif // GAMEMAP_H_INCLUDED
