#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

#include "location.h"
#include "monster.h"
#include "object.h"
#include "player.h"

class gameMap
{
private:
    Player player;
	//Witch witch;
	//Zombie zombie;
	Location endPoint;
    char gameArray[R][C];
	char dInput;

public:
    bool readArray(string);
	void printInstructions();
	void printMap();
	
	void setEndPoint();
	Location getEndLocation();
	void setPlayerLocation();
	Location getPlayerLocation();
	void setMonsterLocation();
	Location getWitchLocation();
	Location getZombieLocation();
	
	void getDirectionInput();
	void movePlayer();
	
};

#endif // GAMEMAP_H_INCLUDED
