//Bishop.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "bishop.hpp"

//Constructor
Bishop::Bishop(side_t _side) {
	type = BISHOP;
	side = _side;
	hasMoved = false;
	if(_side == WHITE) {
		display = "♝";
	} else {
		display = "♗";
	}
}

//Destructor
Bishop::~Bishop() {

}

//Functions
bool Bishop::checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//Diagonal movement
	if(abs(fromCol - toCol) == abs(fromRow - toRow)) {
		return true;
	}

	//All checks have failed
	return false;
}


bool Bishop::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
