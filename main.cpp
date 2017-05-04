/* 
		AnnMarie Kolbl
ID: 3079881 | ak192@zips.uakron.edu
OOP Final Project: Halloween Game
		<main.cpp>
*/
#include <iostream>
#include <fstream>
#include "gameMap.h"
#include "location.h"
#include "player.h"
#include "monster.h"
#include "object.h"
#include "gameMap.cpp"

using namespace std;

bool menuVal(int);
bool continueVal();
bool play(string, int&);

int main()
{
    gameMap gMap;
    int userInput;
	int counter = 1;
	
	string level1 = "level1.txt";
	string level2 = "level2.txt";
	string level3 = "level3.txt";
	string level4 = "level4.txt";
	string level5 = "level5.txt";

    cout << "Halloween Game" << endl;
    cout << "Enter 1 to play, 2 for instructions, or 3 to quit." << endl;
    cin >> userInput;

    if(!menuVal(userInput))
        return 0;
	
	if(userInput == 3)
	{
		cout << "Thanks for playing!" << endl;
		return 0;
	}
	
	if(userInput == 2)
		gMap.printInstructions();
		
		
	if(play(level1, counter))
	{
		if(!continueVal())
			return 0;
	}
	else
	{
		cout << "You've lost the game! Better luck next time!" << endl;
		return 0;
	}
	
	if(play(level2, counter))
	{
		if(!continueVal())
			return 0;
	}
	else
	{
		cout << "You've lost the game! Better luck next time!" << endl;
		return 0;
	}
	
	if(play(level3, counter))
	{
		if(!continueVal())
			return 0;
	}
	else
	{
		cout << "You've lost the game! Better luck next time!" << endl;
		return 0;
	}
	
	if(play(level4, counter))
	{
		if(!continueVal())
			return 0;
	}
	else
	{
		cout << "You've lost the game! Better luck next time!" << endl;
		return 0;
	}
	
	if(play(level5, counter))
	{
		cout << "You've completed all the levels!" << endl;
		cout << "Thanks for playing!" << endl;
		return 0;
	}
	else
	{
		cout << "You've lost the game! Better luck next time!" << endl;
		return 0;
	}
	
}

/*continueVal Function: accepts nothing.
Gets user input, makes sure its valid.
Returns a boolean value */
bool continueVal()
{
	int userInput;
	cout << "Enter 1 to keep playing, 2 to quit" << endl;
	cin >> userInput;
	
	if(userInput < 1 || userInput > 2 || isalpha(userInput))
    {
        cout << "You have entered an incorrect option" << endl;
        return false;
    }
	else if(userInput == 2)
	{
		cout << "Thanks for playing!" << endl;
		return false;
	}
	else
		return true;	
}


/*menuVal Function: accepts an integer
variable, checks to make sure its valid.
Returns a boolean value. */
bool menuVal(int userInput)
{
    if(userInput < 1 || userInput > 3 || isalpha(userInput))
    {
        cout << "You have entered an incorrect option" << endl;
        return false;
    }

    return true;
}


/*play Function: accepts a string and a 
counter passed by reference. Calls all the
functions that are needed to run the game.
Returns true if the game completed successfully */
bool play(string filename, int& counter)
{
	gameMap gMap;
	
    if(!gMap.readArray(filename))
	{
		cout << "The gameboard could not be loaded." << endl;
		cout << "Please exit and try again." << endl;
		return false;
	}
	
	//initialize object locations
	gMap.setEndPoint();
	gMap.setPlayerLocation();
	gMap.setWitchLocation();
	gMap.setCandyLocation();
	gMap.setPumpkinLocation();
	if(counter > 3)
		gMap.setZombieLocation();
	
	gMap.printMap();
	
	bool b = true;
	bool win = true;
	bool candy = false;
	
	while(b)
	{
		//get direction input
		gMap.getDirectionInput();
	
		//move the player
		gMap.movePlayer();
		
		if(!candy) //if the candy has not been picked up
		{
			//move the witch
			gMap.moveWitch();
			if(counter > 3)
				gMap.moveZombie();
		}
		
		//check the game state
		gMap.checkGameState(b, win, candy);
		
		 //print the map
		gMap.printMap();	
	}
	
	//keeps track of the level
	counter++;
	return win;
}
