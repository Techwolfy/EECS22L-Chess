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
		//Check if there are other pieces in the way
		if(toCol == fromCol) {
			if(toRow > fromRow) {
				for(int i = fromRow + 1; i < toRow; i++) {
					if(!board.getPiece(i, fromCol)->getCaptured()) {
						return false;
					}
				}
			} else {
				for(int i = fromRow - 1; i > toRow; i--) {
					if(!board.getPiece(i, fromCol)->getCaptured()) {
						return false;
					}
				}
			}
		} else {
		if(toCol > fromCol) {
			for(int i = fromCol + 1; i < toCol; i++) {
				if(!board.getPiece(fromRow, i)->getCaptured()) {
					return false;
				}
			}
		} else {
			for(int i = fromCol - 1; i > toCol; i--) {
				if(!board.getPiece(fromRow, i)->getCaptured()) {
					return false;
				}
			}
		}
	}

	//All checks have passed
	return true;
}

bool Rook::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
