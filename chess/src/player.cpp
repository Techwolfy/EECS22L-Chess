//Player.cpp

//Includes
#include <stdio.h>
#include "chessboard.hpp"
#include "types.hpp"
#include "player.hpp"

//Constructor
Player::Player() {

}

//Destructor
Player::~Player() {

}

//Functions
void Player::getMove(ChessBoard &board, int *fromRow, int *fromCol, int *toRow, int *toCol) {
	board.display();
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

side_t Player::getSide() {
	return side;
}

void Player::setSide(side_t _side) {
	//TODO: Check for BOTH or NEITHER and error here
	side = _side;
}
