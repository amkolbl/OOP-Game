/* 
		AnnMarie Kolbl
ID: 3079881 | ak192@zips.uakron.edu
OOP Final Project: Halloween Game
		<gameMap.cpp>
*/
#include <iostream>
#include <fstream>
#include "gameMap.h"

using namespace std;

/*readArray function: Accepts the name of 
a file, reads the contents of said file into
an array, closes the file, returns true if
successful, false if not */
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

/*checkGameState Function: Accepts three boolean values passed
by reference, checks to see if any of the conditions outlined
in the function are true, updates the boolean values accordingly.
Returns nothing */
void gameMap::checkGameState(bool& b, bool& win, bool& candy)
{
	Location temp1 = getPlayerLocation();
	Location temp2 = getEndLocation();
	Location temp3 = getWitchLocation();
	Location temp4 = getCandyLocation();
	Location temp5 = getZombieLocation();
	Location temp6 = getPumpkinLocation();
		
	
	//if player location is equal to end location
	if(temp1.xCoord == temp2.xCoord && temp1.yCoord == temp2.yCoord)
	{
		b = false;
		win = true;
	}
		
	//if player location is equal to witch location
	if(temp1.xCoord == temp3.xCoord && temp1.yCoord == temp3.yCoord)
	{
		b = false;
		win = false;
	}
	
	//if player location is equal to candy location
	if(temp1.xCoord == temp4.xCoord && temp1.yCoord == temp4.yCoord)
	{
		candy = true;
	}
	
	//if player location is equal to zombie location
	if(temp1.xCoord == temp5.xCoord && temp1.yCoord == temp5.yCoord)
	{
		b = false;
		win = false;
	}
	
	//if player location is equal to pumpkin location
	if(temp1.xCoord == temp6.xCoord && temp1.yCoord == temp6.yCoord)
	{
		b = false;
		win = true;
	}
}

/*printInstructions Function: accepts nothing,
prints out the game instructions. Returns
nothing */
void gameMap::printInstructions()
{
	cout << "Halloween Game" << endl;
	cout << "Your player must navigate through the mosters to" << endl;
	cout << "the exit point (X) without getting caught by any of" << endl;
	cout << "them. Use w, a, s, and d to move when prompted to" << endl;
	cout << "move your character through the map, avoiding any" << endl;
	cout << "monsters along the way. Keep in mind that you cannot" << endl;
	cout << "move through the hay bales. The Candy will stop the" << endl;
	cout << "monsters from chasing you, the Pumpkin means you win" << endl;
	cout << "the level." << endl;
	cout << "You (+)" << endl;
	cout << "Witch (W)" << endl;
	cout << "Zombie (Z)" << endl;
	cout << "Candy (C)" << endl;
	cout << "Pumpkin (P)" << endl;
	cout << "Hay Bale (#)" << endl;
}

/*printMap Function: accepts nothing.
Traverses the array and prints it to 
the command line. Returns nothing. */
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


/*setEndPoint Function: accepts nothing.
Traveses the array and initializes the 
location of the endpoint. Returns nothing */
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

/*setPlayerLocation Function: accepts nothing.
Traveses the array and initializes the 
location of the player. Returns nothing */
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


/*setWitchLocation Function: accepts nothing.
Traveses the array and initializes the 
location of the witch. Returns nothing */
void gameMap::setWitchLocation()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            if(gameArray[i][k] == 'W')
				witch.setLocation(i, k);
        }
    }
}


/*setZombieLocation Function: accepts nothing.
Traveses the array and initializes the 
location of the zombie. Returns nothing */
void gameMap::setZombieLocation()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            if(gameArray[i][k] == 'Z')
				zombie.setLocation(i, k);
        }
    }
}

/*setCandyLocation Function: accepts nothing.
Traveses the array and initializes the 
location of the candy. Returns nothing */
void gameMap::setCandyLocation()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            if(gameArray[i][k] == 'C')
				candy.setLocation(i, k);
        }
    }
}


/*setPumpkinLocation Function: accepts nothing.
Traveses the array and initializes the 
location of the pumpkin. Returns nothing */
void gameMap::setPumpkinLocation()
{
	for(int i = 0; i < R; i++)
    {
        for(int k = 0; k < C; k++)
        {
            if(gameArray[i][k] == 'P')
				pumpkin.setLocation(i, k);
        }
    }
}


/*getEndLocation Function: accepts 
nothing. Returns the location of 
the endpoint. */
Location gameMap::getEndLocation()
{
	return endPoint;
}


/*getPlayerLocation Function: accepts 
nothing. Returns the location of 
the player. */
Location gameMap::getPlayerLocation()
{
	return player.getLocation();
}


/*getWitchLocation Function: accepts 
nothing. Returns the location of 
the witch. */
Location gameMap::getWitchLocation()
{
	return witch.getLocation();
}


/*getZombieLocation Function: accepts 
nothing. Returns the location of 
the zombie. */
Location gameMap::getZombieLocation()
{
	return zombie.getLocation();
}


/*getCandyocation Function: accepts 
nothing. Returns the location of 
the candy. */
Location gameMap::getCandyLocation()
{
	return candy.getLocation();
}


/*getPumpkinLocation Function: accepts 
nothing. Returns the location of 
the pumpkin. */
Location gameMap::getPumpkinLocation()
{
	return pumpkin.getLocation();
}


/*getDirectionInput Function: accepts
nothing. Reads in user input and sets 
dInput. Returns nothing. */
void gameMap::getDirectionInput()
{
	cout << "Enter w, a, s, or d to move: ";
	cin >> dInput;
}


/*movePlayer Function: accepts nothing.
Moves the player and updates the player
location. Returns nothing. */
void gameMap::movePlayer()
{
	player.move(gameArray,dInput);
	setPlayerLocation();
}


/*moveWitch Function: accepts nothing.
Moves the witch and updates the witch
location. Returns nothing. */
void gameMap::moveWitch()
{
	witch.monsterMove(gameArray, dInput, player.getLocation());
	setWitchLocation();
}


/*moveZombie Function: accepts nothing.
Moves the zombie and updates the zombie
location. Returns nothing. */
void gameMap::moveZombie()
{
	zombie.monsterMove(gameArray, dInput, player.getLocation());
	setZombieLocation();
}

