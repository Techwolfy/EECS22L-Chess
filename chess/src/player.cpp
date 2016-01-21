//Player.cpp

//Includes
#include <stdio.h>
#include "player.hpp"

//Constructor
Player::Player() {

}

//Destructor
Player::~Player() {

}

//Functions
void Player::getMove(int *fromRow, int *fromCol, int *toRow, int *toCol) {
	printf("Enter a move (algebraic format; e.g. b2b3): ");
	scanf("%c%d%c%d", fromCol, fromRow, toCol, toRow);

	//ASCII uppercase to lowercase
	if(*fromCol > 'H') {
		*fromCol -= 'a' - 'A';
	}
	if(*toCol > 'H') {
		*toCol -= 'a' - 'A';
	}

	//ASCII number to int
	*fromCol -= 'A';
	*toCol -= 'A';
}
