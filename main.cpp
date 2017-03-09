#include <iostream>
#include <fstream>

using namespace std;

struct Location
{
    int xCoord;
    int yCoord;

    //Will generate a random position and pass it
    //to the class' constructors to set the position
    //for the monster
    Location setLocation();
};

class Player
{
private:

    string name;
    Location p;

public:

    Player()
    {
        //starting location of player will eventually be hard-coded
        //so they will start at the same place on each level
        p.xCoord = 0;
        p.yCoord = 0;
    }

    //Will allow the user to move the player
    void movePlayer();
    void setLocation(int x, int y);
    Location getLocation() { return p; }
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
    virtual void setLocation(int x, int y);
    virtual Location getLocation()
    {
        x.xCoord = 0;
        x.yCoord = 0;
        return x;
    }

};

class Zombie : Monster
{
private:

    string name = "Zombie";
    char *zPtr = nullptr;
    Location z;

public:

    Zombie()
    {
        //Will eventually be set to starting position of zombie on map
        z.xCoord = 0;
        z.yCoord = 0;
    }

    //will be overridden
    void monsterMove();

    void setLocation(int x, int y)
    {
        z.xCoord = x;
        z.yCoord = y;
    }

    Location getLocation(){ return z; }

};

class Witch : Monster
{
private:

    string name = "Witch";
    char *wPtr = nullptr;
    Location w;

public:

    Witch()
    {
        //Will eventually be set to starting position of zombie on map
        w.xCoord = 0;
        w.yCoord = 0;
    }

    //will be overridden
    void monsterMove();

    void setLocation(int x, int y)
    {
        w.xCoord = x;
        w.yCoord = y;
    }

    Location getLocation() { return w; }

};

class Horseman : Monster
{
private:

    string name = "Horseman";
    char *hPtr = nullptr;
    Location h;

public:

    Horseman()
    {
        //Will eventually be set to starting position of zombie on map
        h.xCoord = 0;
        h.yCoord = 0;
    }

    void monsterMove()
    {
        /*Will be overridden so that the horseman moves a different
        * distance than the other monsters */
    }

    void setLocation(int x, int y)
    {
        h.xCoord = x;
        h.yCoord = y;
    }

    Location getLocation() { return h; }

};

class Object
{
public:
    virtual void setLocation(int x, int y) { }
    virtual Location getLocation();

};

class Pumpkin : Object
{
private:

    Location p;
    char *pPtr = nullptr;

public:

    void setLocation(int x, int y)
    {
        p.xCoord = x;
        p.yCoord = y;
    }

    /*Location getLocation()
    {
        //this function will return the position
        //of the object (unique to each object)
    }*/
};

class Lantern : Object
{
private:

    Location l;
    char *lPtr = nullptr;

public:

    void setLocation(int x, int y)
    {
        l.xCoord = x;
        l.yCoord = y;
    }
    /*Location getLocation()
    {
        //This function will return the location of the
        //object (unique to each object)
    }*/
};

class Candy : Object
{
private:

    Location c;
    char *cPtr = nullptr;

public:

    void setLocation(int x, int y)
    {
        c.xCoord = x;
        c.yCoord = y;
    }

    /*Location getLocation()
    {
        //This function will return the location of the
        //object (unique to each object)
    }*/
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
