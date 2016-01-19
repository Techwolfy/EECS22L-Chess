//Player.cpp

//Includes
#include <stdio.h>

//Constructor
Player::Player() {

}

//Destructor
Piece::~Piece() {

}

//Functions
virtual bool getMove(int *fromRow, int *fromCol, int *toRow, int *toCol) {
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
