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
	printf("%s, enter a move (algebraic format; e.g. b2b3): ", side == WHITE ? "White" : "Black");

	char fromColIn = 0, toColIn = 0; //Used only to read in row identifier characters
	scanf(" %c%d%c%d", &fromColIn, fromRow, &toColIn, toRow);

	//ASCII uppercase to lowercase, letter to int
	if(fromColIn >= 'a') {
		fromColIn -= 'a';
	} else {
		fromColIn -= 'A';
	}
	if(toColIn >= 'a') {
		toColIn -= 'a';
	} else {
		toColIn -= 'A';
	}

	//Convert input characters to output integers
	*fromCol = fromColIn;
	*toCol = toColIn;

	//Convert from 1-based to 0-based indexing
	*fromRow -= 1;
	*toRow -= 1;
}

side_t Player::getSide() {
	return side;
}

void Player::setSide(side_t _side) {
	//TODO: Check for BOTH or NEITHER and error here
	side = _side;
}
