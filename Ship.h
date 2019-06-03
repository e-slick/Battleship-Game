#ifndef SHIP_H
#define SHIP_H
/*
Name: Eric Slick
Class: CSCI 2312 OOP, Dr. Augustine
Assignment: Final
Description: Battleship game, player vs. cpu
*/


#include "Player.h"
class Ship :
	public Player
{
public:
	Ship();
	~Ship();
	void checkOverlap(vector<Ship> &_vecPlayerShip, vector<vector<char>> &_playGrid);
	void checkSunk(vector<vector<char>> &_playGrid);
	void fireTorpedo(vector<vector<char>> &_playGrid, vector<vector<char>> &_trackingGrid);
	void placeShips(vector<vector<char>> &_playGrid);
	void printOut(); //virtual
	void createShips();
	void setName(string n) { name = n; }
	void setLength(int l) { length = l; }
	void setOrientation(char h) { orientation = h; }
	void setLocation(string _loc) { location = _loc; }
	void setSunk(bool s) { sunk = s; }
	void setDisplaySunk(bool ds) { displaySunk = ds; }

	int getLength() { return length; }
	string getLocation() { return location; }
	string getName() { return name; }
	char getOrientation() { return orientation; }
	bool getSunk() { return sunk; }
	bool getDisplaySunk() { return displaySunk; }

private:
	//vector of player ships
	vector<Ship> vecPlayerShips;
	string location, name;
	char orientation;
	int length;
	bool sunk;
	bool displaySunk;

};

#endif
