//Queen.cpp

//Includes
#include "piece.hpp"
#include "chessboard.hpp"
#include "queen.hpp"

//Constructor
Queen::Queen(side_t _side) {
	type = Queen;
	side = _side;
	hasMoved = false;
	isCaptured = false;
	if(_side == WHITE) {
		display = "♛";
	} else {
		display = "♕";
	}
}

//Destructor
Queen::~Queen() {

}

//Functions
bool Queen::checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//No moving in place
	if(toRow == fromRow && toCol == fromCol) {
		return false;
	}

	//Diagonal, same column, or same row movement
	if(abs(toCol - fromCol) == abs(toRow - fromRow) || toRow == fromRow || toCol == fromCol) {
		//TODO: Check if there are other pieces in the way!
		return true;
	}

	//All checks have failed
	return false;
}

bool Queen::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}