/*
Name: Eric Slick
Class: CSCI 2312 OOP, Dr. Augustine
Assignment: Final
Description: Battleship game, player vs. cpu
*/


#include "Player.h"
#include "Ship.h"
	
int main() {
	//object for calling the game into play
	Player playerOne;

	//play game function
	playerOne.playGame();


	cout << endl;
	system("pause");

	return 0;
}