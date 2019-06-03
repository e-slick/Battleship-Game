/*
Name: Eric Slick
Class: CSCI 2312 OOP, Dr. Augustine
Assignment: Final
Description: Battleship game, player vs. cpu
*/


#include "Player.h"
#include "Ship.h"
#include "CPU_Ship.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::checkSunk()
{
}

void Player::fireTorpedo()
{
}

void Player::printGrids(vector<vector<char>>& _trackGrid, vector<vector<char>> &_playGrid)
{
	//player playing
	cout << "Player Playing Grid: " << endl << "  ";
	for (int i = 1; i < 11; i++) {
		cout << i << " ";
	}
	cout << endl;

	char columnLetter = 'A';
	for (int r = 0; r < MAXROW; r++) {
		cout << columnLetter << " ";
		columnLetter++;
		for (int c = 0; c < MAXCOLUMN; c++) {
			cout << _playGrid[r][c] << " ";
		}
		cout << endl;
	}

	//player tracking
	cout << "Player Tracking Grid: " << endl << "  ";
	for (int i = 1; i < 11; i++) {
		cout << i << " ";
	}
	cout << endl;

	columnLetter = 'A';
	for (int r = 0; r < MAXROW; r++) {
		cout << columnLetter << " ";
		columnLetter++;
		for (int c = 0; c < MAXCOLUMN; c++) {
			cout << _trackGrid[r][c] << " ";
		}
		cout << endl;
	}
}



void Player::placeShips(vector<vector<char>> &_playGridVec) {
}

void Player::printOut()
{
}

void Player::readIn()
{
}

void Player::playGame()
{
	srand(time(NULL));
	Player gameObj;
	Ship playerShips;
	CPU_Ship CPUShips;

	//CPU playing Grid
	vector<char> rowVec(MAXROW, 'O');
	vector<vector<char> > playGridVec(MAXCOLUMN, rowVec);

	//player playing grid
	vector <char> rowVec2(MAXROW, 'O');
	vector<vector<char> > playGridVec2(MAXCOLUMN, rowVec2);
	
	//tracking grid for player
	vector<char>rowVec3(MAXROW, 'O');
	vector<vector<char> > trackGridVec(MAXCOLUMN, rowVec3);

	//creation and placement of player ships
	playerShips.createShips();
	playerShips.placeShips(playGridVec2);

	//creation and placement of cpu ships
	CPUShips.readIn();
	CPUShips.placeShips(playGridVec);

	//playing the game
	
	do {
		//because if the player doesn't win by then the computer will have
		for (int i = 0; i < 100; i++) {
			printGrids(trackGridVec, playGridVec2);
			playerShips.fireTorpedo(playGridVec, trackGridVec);
			CPUShips.fireTorpedo(playGridVec2);
		}
			playerShips.checkSunk(playGridVec2);
			CPUShips.checkSunk(playGridVec);
	} while (gameObj.getGameOver() == false);

	
}
