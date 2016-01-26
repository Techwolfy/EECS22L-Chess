//Queen.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "Queen.hpp"

//Constructor
Queen::Queen(side_t _side) {
	type = Queen;
	side = _side;
	hasMoved = false;
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
	//Diagonal movement or same col movement or same row movement
	if((toRow==fromRow)&&(toCol==fromCol)){
		return false;
	}
	if(abs(toCol-fromCol)==abs(toRow-fromRow) || toRow==fromRow || toCol==fromCol) {
		return true;
	}
	//All checks have passed
	return false;
}


bool Queen::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
