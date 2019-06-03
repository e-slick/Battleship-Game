/*
Name: Eric Slick
Class: CSCI 2312 OOP, Dr. Augustine
Assignment: Final
Description: Battleship game, player vs. cpu
*/


#pragma once
#include "Player.h"
#include "Ship.h"

class CPU_Ship :
	public Player
{
public:
	CPU_Ship();
	~CPU_Ship();
	void checkSunk(vector<vector<char>> &_playGrid);
	void fireTorpedo(vector<vector<char>> &_playGrid);
	void printGrids(vector<vector<char>> &_trackGrid);
	void placeShips(vector<vector<char>> &_playGridVec);
	void printOut();
	void readIn();
	void setName(string n) { name = n; }
	void setOrienation(string h) { orientation = h; }
	void setLocation(string _loc) { location = _loc; }
	void setLength(int l) { length = l; }
	void setSunk(bool s) { sunkShip = s; }
	void setDisplaySunk(bool ds) { displaySunk = ds; }

	bool getDisplaySunk() { return displaySunk; }
	bool getSunk() { return sunkShip; }
	string getLocation() { return location; }
	string getName() { return name; }
	string getOrientation() { return orientation; }
	int getLength() { return length; }

private:
	vector<CPU_Ship> vecCPUShips;
	string location, name, orientation;
	int length;
	bool sunkShip, displaySunk;
};

