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
	scanf("%d%d%d%d", fromCol, fromRow, toCol, toRow);

	//ASCII uppercase to lowercase, letter to int
	if(*fromCol >= 'a') {
		*fromCol -= 'a';
	} else {
		*fromCol -= 'A';
	}
	if(*toCol >= 'a') {
		*toCol -= 'a';
	} else {
		*toCol -= 'A';
	}

	//ASCII number to int
	*fromRow -= '0';
	*toRow -= '0';
}

side_t Player::getSide() {
	return side;
}

void Player::setSide(side_t _side) {
	//TODO: Check for BOTH or NEITHER and error here
	side = _side;
}
