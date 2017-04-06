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
void play();

int main()
{
    gameMap gMap;
    int userInput;

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
		
	play();
    
	return 0;
}

bool menuVal(int userInput)
{
    if(userInput < 1 || userInput > 3 || isalpha(userInput))
    {
        cout << "You have entered an incorrect option" << endl;
        return false;
    }

    return true;
}


void play()
{
	gameMap gMap;
	string board1 = "level1.txt";
	
    if(!gMap.readArray(board1))
        return;

	gMap.setPlayerLocation();
	gMap.setEndPoint();
	
	gMap.printMap();
	
	bool b = true;
	Location temp1;
	Location temp2;
	
	while(b)
	{
		gMap.getDirectionInput();
	
		gMap.movePlayer();
		
		temp1 = gMap.getPlayerLocation();
		temp2 = gMap.getEndLocation();
		if(temp1.xCoord == temp2.xCoord && temp1.yCoord == temp2.yCoord)
			b = false;
	
		gMap.printMap();	
	}
}
