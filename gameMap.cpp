#include <iostream>
#include <fstream>
#include "gameMap.h"

using namespace std;

bool gameMap::readArray(string fileName)
{
    ifstream is;

    is.open(fileName);

    if(!is.is_open())
    {
        cout << "Error: no game board found." << endl;
        return false;
    }

    for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            is >> gameArray[i][k];
        }
    }

    is.close();

    return true;
}

void gameMap::printInstructions()
{
	cout << "Halloween Game" << endl;
	cout << "Your player (+) must navigate through the mosters to" << endl;
	cout << "the exit point (X) without getting caught by any of" << endl;
	cout << "them. Use w, a, s, and d to move when prompted to" << endl;
	cout << "move your character through the map." << endl;
}

void gameMap::printMap()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            cout << gameArray[i][k];
        }
        cout << endl;
    }
}


void gameMap::setEndPoint()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            if(gameArray[i][k] == 'X')
			{
				endPoint.xCoord = i;
				endPoint.yCoord = k;
			}
        }
    }
}

Location gameMap::getEndLocation()
{
	return endPoint;
}


void gameMap::setPlayerLocation()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            if(gameArray[i][k] == '+')
				player.setLocation(i, k);
        }
    }
}

Location gameMap::getPlayerLocation()
{
	return player.getLocation();
}


/*void gameMap::setMonsterLocation()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            if(gameArray[i][k] == 'W')
				witch.setLocation(i, k);
			
			if(gameArray[i][k] == 'Z')
				zombie.setLocation(i, k);	
        }
    }
}

Location gameMap::getWitchLocation()
{
	return witch.getLocation();
}

Location gameMap::getZombieLocation()
{
	return zombie.getLocation();
}*/


void gameMap::getDirectionInput()
{
	cout << "Enter w, a, s, or d to move: ";
	cin >> dInput;
}

void gameMap::movePlayer()
{
	player.move(gameArray,dInput);
	setPlayerLocation();
}

