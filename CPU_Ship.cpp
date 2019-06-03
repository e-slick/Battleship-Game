#include "CPU_Ship.h"



CPU_Ship::CPU_Ship()
{
}


CPU_Ship::~CPU_Ship()
{
}

void CPU_Ship::checkSunk(vector<vector<char>> &_playGrid)
{
	Player gameObj;
	string tLoc, tOrient;
	int tXCoord, tYCoord, sunkCount = 0;
	for (int i = 0; i < vecCPUShips.size(); i++) {
		int count = 1;
		tLoc = vecCPUShips[i].getLocation();
		tOrient = vecCPUShips[i].getOrientation();
		tXCoord = tLoc[0] - 65;
		tYCoord = (tLoc[1] - '0') - 1;
		if (_playGrid[tXCoord][tYCoord] == 'X') {
			if (tOrient[0] == 'H') {
				while (count < vecCPUShips[i].getLength()) {
					tYCoord++;
					if (_playGrid[tXCoord][tYCoord] == 'X') {
						count++;
					}
					if (count == vecCPUShips[i].getLength()) {
						vecCPUShips[i].setSunk(true);
					}
					if (_playGrid[tXCoord][tYCoord] != 'X') {
						count = vecCPUShips[i].getLength();
					}
				}
			}
			if (tOrient[0] == 'V') {
				while (count < vecCPUShips[i].getLength()) {
					tXCoord++;
					if (_playGrid[tXCoord][tYCoord] == 'X') {
						count++;
					}
					if (count == vecCPUShips[i].getLength()) {
						vecCPUShips[i].setSunk(true);
					}
					if (_playGrid[tXCoord][tYCoord] != 'X') {
						count = vecCPUShips[i].getLength();
					}
				}
			}
			if (vecCPUShips[i].getSunk() == true && vecCPUShips[i].getDisplaySunk() == false) {
				vecCPUShips[i].setDisplaySunk(true);
				sunkCount++;
				cout << "Player sunk CPU: " << vecCPUShips[i].getName() << endl;
			}
		}
	}
	if (sunkCount == 5) {
		cout << "Game over! Player Wins!" << endl << endl;
		gameObj.setGameOver(true);
		exit(0);
	}
}

void CPU_Ship::fireTorpedo(vector<vector<char>> &_playGrid)
{
	int xShot, yShot, tInt;
	char hitChar;
	string tLoc;
	xShot = rand() % 10;
	yShot = rand() % 10;

	if (_playGrid[xShot][yShot] != 'O' && _playGrid[xShot][yShot] != 'X' && _playGrid[xShot][yShot] != 'M') {
			cout << "CPU HIT: ";
			hitChar = xShot + 65;
			cout << hitChar << yShot << endl;
			_playGrid[xShot][yShot] = 'X';
		}
	else if (_playGrid[xShot][yShot] == 'X' || _playGrid[xShot][yShot] == 'M') {
			fireTorpedo(_playGrid);
		}
	else if (_playGrid[xShot][yShot] == 'O') {
		cout << "CPU MISS!" << endl;
		_playGrid[xShot][yShot] = 'M';
	}
}

/*
Name: Eric Slick
Class: CSCI 2312 OOP, Dr. Augustine
Assignment: Final
Description: Battleship game, player vs. cpu
*/


void CPU_Ship::printGrids(vector<vector<char>>& _trackGrid)
{
}

void CPU_Ship::placeShips(vector<vector<char>>& _playGridVec)
{
	string tLocation, tName, stringOrientation;
	char tLoc = 'A', charOrientation;
	int tXCoord, tYCoord;


	for (int i = 0; i < vecCPUShips.size(); i++) {

		int count = 0;
		tLocation = vecCPUShips[i].getLocation();
		tName = vecCPUShips[i].getName();
		stringOrientation = vecCPUShips[i].getOrientation();
		charOrientation = stringOrientation[0];
		tYCoord = (tLocation[1] - '0') - 1;
		tXCoord = tLocation[0] - 65;


		if (tLocation.size() == 3) {
			tYCoord = 9;
		}
		else {
			tYCoord = (tLocation[1] - '0') - 1;
		}
		try {
			if (charOrientation == 'H') {

				if (tYCoord + vecCPUShips[i].getLength() > 10) {
					throw vecCPUShips[i].getLocation();
				}
			}
			if (charOrientation == 'V') {
				if (tXCoord + vecCPUShips[i].getLength() > 10) {
					throw vecCPUShips[i].getLocation();
				}
			}
		}
		catch (string e) {
			cout << "CPU Location Invalid. Generated valid placement." << endl;
			int tInt;
			tYCoord = rand() % 11;
			tXCoord = rand() % 11;
			tInt = vecCPUShips[i].getLength();
			//horizontal orientation
			if (charOrientation == 'H' && tYCoord == 10) {
				tYCoord--;
				tYCoord = tYCoord - tInt;
			}
			else if (charOrientation == 'H' && tYCoord >= tInt) {
				tYCoord = tYCoord - tInt;
			}
			if (tXCoord == 10) {
				tXCoord--;
			}
			//vertical orientation
			if (charOrientation == 'V' && tXCoord == 10) {
				tXCoord--;
				tXCoord = tXCoord - tInt;
			}
			else if (charOrientation == 'V' && tXCoord >= tInt) {
				tXCoord = tXCoord - tInt;
			}
			if (tYCoord == 10) {
				tYCoord--;
			}
		}


		//ship placement
		while (count < vecCPUShips[i].getLength()) {
			if (stringOrientation[0] == 'H') {
				_playGridVec[tXCoord][tYCoord] = tName[0];
				count++;
				tYCoord++;
			}
			if (stringOrientation[0] == 'V') {
				_playGridVec[tXCoord][tYCoord] = tName[0];
				count++;
				tXCoord++;
			}

		}

	}

}

void CPU_Ship::printOut()
{
	for (int i = 0; i < vecCPUShips.size(); i++) {
		cout << vecCPUShips[i].getName() << ", " << vecCPUShips[i].getLocation() << ", " << vecCPUShips[i].getOrientation() << endl;
	}
}

void CPU_Ship::readIn()
{
	ifstream myFile("ships.csv");
	string tName, tLocation, tOrientation;
	CPU_Ship cpuShipObj;
	while (!myFile.eof()) {
		getline(myFile, tName, ',');
		getline(myFile, tLocation, ',');
		getline(myFile, tOrientation);
		cpuShipObj.name = tName;
		cpuShipObj.location = tLocation;
		cpuShipObj.orientation = tOrientation;
		vecCPUShips.push_back(cpuShipObj);
	}
	vecCPUShips[0].setLength(5);
	vecCPUShips[1].setLength(4);
	vecCPUShips[2].setLength(3);
	vecCPUShips[3].setLength(3);
	vecCPUShips[4].setLength(2);
	//sunk
	vecCPUShips[0].setSunk(false);
	vecCPUShips[1].setSunk(false);
	vecCPUShips[2].setSunk(false);
	vecCPUShips[3].setSunk(false);
	vecCPUShips[4].setSunk(false);
}
