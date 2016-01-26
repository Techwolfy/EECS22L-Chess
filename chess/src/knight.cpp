//Knight.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "knight.hpp"

//Constructor
Knight::Knight(side_t _side) {
	type = KNIGHT;
	side = _side;
	hasMoved = false;
	isCaptured = false;
	if(_side == WHITE) {
		display = "♞";
	} else {
		display = "♘";
	}
}

//Destructor
Knight::~Knight() {

}

//Functions
bool Knight::checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//Check all 8 possible moves
	if(abs(fromCol - toCol) == 2 && abs(fromRow - toRow) == 1) {
		//Upward/downward L
		return true;
	} else if(abs(fromRow - toRow) == 2 && abs(fromCol - toCol) == 1) {
		//Left/right L
		return true;
	}

	//All checks have passed
	return true;
}

bool Knight::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
