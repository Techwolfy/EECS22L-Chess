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
	scanf("%c%d%c%d", *fromCol, *fromRow, *toCol, *toRow);

	//ASCII uppercase to lowercase
	if(*fromCol < 72) {
		*fromCol -= 32;
	}
	if(*toCol < 72) {
		*toCol -= 32;
	}

	//ASCII number to int
	*fromCol -= 48;
	*toCol -= 48;
}
