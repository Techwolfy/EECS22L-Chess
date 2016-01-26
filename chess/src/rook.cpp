//Rook.cpp

//Includes
#include "piece.hpp"
#include "chessboard.hpp"
#include "rook.hpp"

//Constructor
Rook::Rook(side_t _side) {
	type = ROOK;
	side = _side;
	hasMoved = false;
	isCaptured = false;
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
	//Movement within the same row or column
	if(toCol == fromCol || toRow == fromRow) {
		//TODO: Check if there are other pieces in the way!
		return true;	
	}

	//All checks have passed
	return false;
}

bool Rook::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
