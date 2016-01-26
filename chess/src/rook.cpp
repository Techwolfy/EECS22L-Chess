//Rook.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "Rook.hpp"

//Constructor
Rook::Rook(side_t _side) {
	type = ROOK;
	side = _side;
	hasMoved = false;
	if(_side == WHITE) {
		display = "♜";
	} else {
		display = "♖";
	}
}

//Destructor
Rook::~Rook() {

}

//Functions
bool Rook::checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//same col movement or same row movement
	if ((toRow==fromRow)&&(toCol==fromCol)){
		return false;
	}
	if(toCol==fromCol || toRow==fromRow) {
		return true;	
	}

	//All checks have passed
	return false;
}

bool Rook::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
