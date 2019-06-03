/*
Name: Eric Slick
Class: CSCI 2312 OOP, Dr. Augustine
Assignment: Final
Description: Battleship game, player vs. cpu
*/


#include "Ship.h"

Ship::Ship()
{
}


Ship::~Ship()
{
}

//function to check if the players ship inputs overlap
	//uses exception handling
void Ship::checkOverlap(vector<Ship> &_vecPlayerShip, vector<vector<char>> &_playGrid)
{
	int count = 0, tXCoord, tYCoord, tLength;
	char tOrient;
	string tName, tLoc;
	for (int i = 0; i < _vecPlayerShip.size(); i++) {
		count = 0;
		tLength = _vecPlayerShip[i].getLength();
		tLoc = _vecPlayerShip[i].getLocation();
		tXCoord = tLoc[0] - 65;
		tYCoord = (tLoc[1] - '0') - 1;
		tName = _vecPlayerShip[i].getName();
		tOrient = _vecPlayerShip[i].getOrientation();
		//exception handling
		try {
			//horizontal
			if (tOrient == 'H') {
				while (count < _vecPlayerShip[i].getLength()) {
					if (_playGrid[tXCoord][tYCoord] == 'O') {
						tXCoord++;
						count++;
						if (count == tLength) {
							throw _vecPlayerShip[i].getLocation();
						}
						if (_playGrid[tXCoord][tYCoord] != 'O') {
							throw  _vecPlayerShip[i].getLocation();
						}
					}
				}
			}
			//vertical
			if (tOrient == 'V') {
				while (count < _vecPlayerShip[i].getLength()) {
					if (_playGrid[tXCoord][tYCoord] == 'O') {
						tYCoord++;
						count++;
						if (count == tLength) {
							throw _vecPlayerShip[i].getLocation(); //throw 1
						}
						if (_playGrid[tXCoord][tYCoord] != 'O') {
							throw  _vecPlayerShip[i].getLocation(); //throw 2
						}
					}
					if (_playGrid[tXCoord][tYCoord] != 'O') {
						throw _vecPlayerShip[i].getLocation(); // throw 3
					}
				}
			}
		}
		//exception catch
		catch (string e) {
			if (count == tLength) {
				count = 0;
				tXCoord = tLoc[0] - 65;
				tYCoord = (tLoc[1] - '0') - 1;
				while (count < _vecPlayerShip[i].getLength()) {
					if (tOrient == 'H') {
						_playGrid[tXCoord][tYCoord] = tName[0];
						count++;
						tYCoord++;
					}
					if (tOrient == 'V') {
						_playGrid[tXCoord][tYCoord] = tName[0];
						count++;
						tXCoord++;
					}
				}
			}
			else {
				cout << "Overlapping ships! Re-enter your location: ";
				count = 0;
				cin >> tLoc;
				tLoc[0] = toupper(tLoc[0]);
				tXCoord = tLoc[0] - 65;
				tYCoord = (tLoc[1] - '0') - 1;

			}
				
			

		}
		while (count < _vecPlayerShip[i].getLength()) {
			if (tOrient == 'H') {
				_playGrid[tXCoord][tYCoord] = tName[0];
				tYCoord++;
				count++;
			}
			if (tOrient == 'V') {
				_playGrid[tXCoord][tYCoord] = tName[0];
				tXCoord++;
				count++;
			}
		}
	}
}


//checks if ships are sunk after each iteration of torpedos
	//exits the game upon all ships == sunk
void Ship::checkSunk(vector<vector<char>> &_playGrid)
{
	Player gameObj;
	string tLoc, tOrient;
	int sunkCount = 0, tXCoord, tYCoord;
	for (int i = 0; i < vecPlayerShips.size(); i++) {
		int count = 1;
		tLoc = vecPlayerShips[i].getLocation();
		tOrient = vecPlayerShips[i].getOrientation();
		tXCoord = tLoc[0] - 65;
		tYCoord = (tLoc[1] - '0') - 1;
		if (_playGrid[tXCoord][tYCoord] == 'X') {
			if (tOrient[0] == 'H') {
				while (count <= vecPlayerShips[i].getLength()) {
					tYCoord++;
					if (_playGrid[tXCoord][tYCoord] == 'X') {
						count++;
					}
					if (count == vecPlayerShips[i].getLength()) {
						vecPlayerShips[i].setSunk(true);
					}
					if (_playGrid[tXCoord][tYCoord] != 'X') {
						count = vecPlayerShips[i].getLength();
					}
				}
			}
			if (tOrient[0] == 'V') {
				while (count < vecPlayerShips[i].getLength()) {
					tXCoord++;
					if (_playGrid[tXCoord][tYCoord] == 'X') {
						count++;
					}
					if (count == vecPlayerShips[i].getLength()) {
						vecPlayerShips[i].setSunk(true);
					}
					if (_playGrid[tXCoord][tYCoord] != 'X') {
						count = vecPlayerShips[i].getLength();
					}
				}
			}

		}
		if (vecPlayerShips[i].getSunk() == true) {
			if (vecPlayerShips[i].getDisplaySunk() == false) {
				vecPlayerShips[i].setDisplaySunk(true);
				sunkCount++;
				cout << "CPU sunk your: " << vecPlayerShips[i].getName() << endl;
			}
		}
	}
	if (sunkCount == 5) {
		cout << "Game over! CPU Wins!" << endl << endl;
		gameObj.setGameOver(true);
		//exit(0);
	}

}

//player fire torpedo function
	//exception handling if string tLoc is greater than 2 chars
void Ship::fireTorpedo(vector<vector<char>> &_playGrid, vector<vector<char>> &_trackingGrid)
{
	string tLoc;
	char cont = 'N';
	int tXCoord, tYCoord;
	cout << "Continue? (Y/N): ";
	cin >> cont;
	cont = toupper(cont);
	if (cont == 'Y') {

		try {
			cout << "Enter Torpedo Firing Coordinates (ex: A1): ";
			cin >> tLoc;
			tXCoord = tLoc[0] - 65;
			tYCoord = (tLoc[1] - '0') - 1;
			if (tLoc.size() > 2) {
				throw tLoc;
			}

			tLoc[0] = toupper(tLoc[0]);
			tXCoord = tLoc[0] - 65;
			tYCoord = (tLoc[1] - '0') - 1;
		}
		catch (string e) {
			cout << "Invalid Torpedo Coordinates! Re-enter: ";
			cin >> tLoc;
			tLoc[0] = toupper(tLoc[0]);
			tXCoord = tLoc[0] - 65;
			tYCoord = (tLoc[1] - '0') - 1;
		}

		if (_playGrid[tXCoord][tYCoord] == 'O') {
			cout << "Miss!" << endl;
			_trackingGrid[tXCoord][tYCoord] = 'M';
		}
		else {
			_playGrid[tXCoord][tYCoord] = 'X';
			_trackingGrid[tXCoord][tYCoord] = 'X';
		}
	}
	else {
		exit(0);
	}

}


//asks the user to define the orientation and location for their ships
void Ship::createShips() {
	char tOrient, tXCoord;
	string tLoc;
	Ship newShip;
	int tInt;
	cout << "Please enter the orientation (V/H) and location (ex: A1) for all of your ships (Carrier/Battleship/Cruiser/Sub/Destroyer)" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Orienation: ";
		cin >> tOrient;
		tOrient = toupper(tOrient);
		newShip.setOrientation(tOrient);
		cout << "Location: ";
		cin >> tLoc;
		tLoc[0] = toupper(tLoc[0]);
		newShip.setLocation(tLoc);
		cout << endl;
		vecPlayerShips.push_back(newShip);
	}
	//setting ship names
	vecPlayerShips[0].setName("Carrier");
	vecPlayerShips[1].setName("Battleship");
	vecPlayerShips[2].setName("Cruiser");
	vecPlayerShips[3].setName("Submarine");
	vecPlayerShips[4].setName("Destroyer");
	//setting ship length values
	vecPlayerShips[0].setLength(5);
	vecPlayerShips[1].setLength(4);
	vecPlayerShips[2].setLength(3);
	vecPlayerShips[3].setLength(3);
	vecPlayerShips[4].setLength(2);
	//setting sunk value
	vecPlayerShips[0].setSunk(false);
	vecPlayerShips[1].setSunk(false);
	vecPlayerShips[2].setSunk(false);
	vecPlayerShips[3].setSunk(false);
	vecPlayerShips[4].setSunk(false);

}

//placing the player ships on the grid
	//uses exception handling
void Ship::placeShips(vector<vector<char>> &_playGrid)
{
	Ship shipObj;
	string tLoc, tName;
	char tOrient;
	int tXCoord, tYCoord;

	for (int i = 0; i < vecPlayerShips.size(); i++) {
		int count = 0;

		tName = vecPlayerShips[i].getName();
		tOrient = vecPlayerShips[i].getOrientation();
		tLoc = vecPlayerShips[i].getLocation();
		tXCoord = tLoc[0] - 65;
		if (tLoc.size() == 3) {
			tYCoord = 9;
		}
		else {
			tYCoord = (tLoc[1] - '0') - 1;
		}
		try {
			if (vecPlayerShips[i].getOrientation() == 'H') {

				if (tYCoord + vecPlayerShips[i].getLength() > 10) {
					throw vecPlayerShips[i].getLocation();
				}
			}
			if (vecPlayerShips[i].getOrientation() == 'V') {
				if (tXCoord + vecPlayerShips[i].getLength() > 10) {
					throw vecPlayerShips[i].getLocation();
				}
			}
		}
		catch (string e) {
			string tLoc;
			int tXCoord, tYCoord;
			cout << "Location " << i + 1 << " invalid, please input another Grid Location: ";
			cin >> tLoc;
			tLoc[0] = toupper(tLoc[0]);
			vecPlayerShips[i].setLocation(tLoc);
		}
	}
	checkOverlap(vecPlayerShips, _playGrid);

}

//used this simply to see the values of the ships
void Ship::printOut()
{
	for (int i = 0; i < vecPlayerShips.size(); i++) {
		cout << vecPlayerShips[i].getName() << ", " << vecPlayerShips[i].getLocation() << ", " << vecPlayerShips[i].getOrientation() << endl;
	}
}