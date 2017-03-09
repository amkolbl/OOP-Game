#include <iostream>
#include <fstream>

using namespace std;

struct Location
{
    int xCoord; //to hold x coordinate
    int yCoord; //to hold y coordinate

    Location moveLocation(Location); //to move the players and monsters through the array
};

class Player
{
private:

    Location p;

public:

    void movePlayer(); //will allow the user to move the player
    void setLocation(int x, int y); //sets private variables
    Location getLocation() { return p; } //returns private variables
};

class Monster
{
private:

    Location x;

public:

    //Not entirely sure how move will be implemented yet
    //but each monster will move a different distance in
    //the direction that the player moves
    virtual void monsterMove(int x, int y);
    //to set the location of the respective monster
    virtual void setLocation(int x, int y);
    //to return the location of the respective monster
    virtual Location getLocation();
};

class Zombie : Monster
{
private:

    Location z;

public:

    //will be overridden
    void monsterMove();

    void setLocation(int x, int y) //to set private variables
    {
        z.xCoord = x;
        z.yCoord = y;
    }

    Location getLocation(){ return z; } //to return private variables

};

class Witch : Monster
{
private:

    Location w;

public:

    //will be overridden
    void monsterMove();

    void setLocation(int x, int y) //to set private variables
    {
        w.xCoord = x;
        w.yCoord = y;
    }

    Location getLocation() { return w; } //to return private variables

};

class Horseman : Monster
{
private:

    Location h;

public:

    //will be overridden
    void monsterMove();

    void setLocation(int x, int y) //to set private variables
    {
        h.xCoord = x;
        h.yCoord = y;
    }

    Location getLocation() { return h; } //to return private variables

};

class Object
{
public:
    virtual void setLocation(int x, int y); //to initialize private variables to location of object
    virtual Location getLocation(); //to return location of object

};

class Pumpkin : Object
{
private:

    Location p;

public:

    void setLocation(int x, int y) //set private varibles
    {
        p.xCoord = x;
        p.yCoord = y;
    }

    Location getLocation() { return p; } //return private variables
};

class Lantern : Object
{
private:

    Location l;

public:

    void setLocation(int x, int y) //set private variables
    {
        l.xCoord = x;
        l.yCoord = y;
    }
    Location getLocation() { return l; } //return private variables
};

class Candy : Object
{
private:

    Location c;

public:

    void setLocation(int x, int y) //set private variables
    {
        c.xCoord = x;
        c.yCoord = y;
    }

    Location getLocation() { return c; } //return private variables
};

int main()
{
    int userInput;
    char gameArray[12][30];


    cout << "Halloween Game" << endl;
    cout << "Enter 1 to play, 2 for instructions, or 3 to quit." << endl;
    cin >> userInput;

    if(userInput < 1 || userInput > 3 || isalpha(userInput))
    {
        cout << "You have entered an incorrect option" << endl;
        return 0;
    }
    else if(userInput == 2)
    {
        cout << "This is where instructions will be" << endl;
    }
    else if(userInput == 3)
    {
        cout << "Thanks for playing!" << endl;
        return 0;
    }

    ifstream is;

    is.open("level1.txt");

    if(!is.is_open())
    {
        cout << "Error: no gameboard found." << endl;
        return 0;
    }

    for(int i = 0; i < 12; i++)
    {
        for(int k = 0; k < 30; k++)
        {
            is >> gameArray[i][k];
        }
    }

    //print
    for(int i = 0; i < 12; i++)
    {
        for(int k = 0; k < 30; k++)
        {
            cout << gameArray[i][k];
        }
        cout << endl;
    }
    is.close();
}
