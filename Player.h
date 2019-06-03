/*
Name: Eric Slick
Class: CSCI 2312 OOP, Dr. Augustine
Assignment: Final
Description: Battleship game, player vs. cpu
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Player
{
public:
	Player();
	~Player();
	virtual void checkSunk();
	virtual void fireTorpedo();
	virtual void printGrids(vector<vector<char>> &_trackGrid, vector<vector<char>> &_playGrid);
	virtual void placeShips(vector<vector<char>> &_playGridVec);
	virtual void printOut();
	virtual void readIn();
	virtual void playGame();

	void setGameOver(bool go) { gameOver = go; }
	bool getGameOver() { return gameOver; }

private:
	bool gameOver;
	int MAXROW = 10, MAXCOLUMN = 10;


};

#endif