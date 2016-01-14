//King.cpp

//Includes
#include <math.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "king.hpp"

//Constructor
King::King(side_t _side) : type(KING),
						   side(_side),
						   hasMoved(false) {
	if(_side == WHITE) {
		display = '♚';
	} else {
		display = '♔';
	}
}

//Destructor
King::~King() {

}

//Functions
bool King::checkMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol) {
	//Only one square away, unless castling
	if(hasMoved) {
		if(abs(fromRow - toRow) > 1 || abs(fromCol - toCol) > 1) {
			return false;
		}
	} else {
		//TODO: Check for castling
	}

	//New square must not be threatened (king can't move into check)
	//TODO: Implement
}

bool King::move(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}

bool King::revertMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}

bool King::checkmate(Piece[8][8] board) {
	//TODO: Implement
}
