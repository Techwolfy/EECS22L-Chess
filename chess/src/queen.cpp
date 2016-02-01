//Queen.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "queen.hpp"

//Constructor
Queen::Queen(side_t _side) {
	type = QUEEN;
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

	//Diagonal movement
	if(abs(fromCol - toCol) == abs(fromRow - toRow)) {
		if(fromRow < toRow) {
			if(fromCol < toCol) {
				for(int i = 1; i < toRow - fromRow; i++) {
					if(!board.getPiece(fromRow + i, fromCol + i)->getCaptured()) {
						return false;
					}
				}
			} else {
				for(int i = 1; i < toRow - fromRow; i++) {
					if(!board.getPiece(fromRow + i, fromCol - i)->getCaptured()) {
						return false;
					}
				}
			}
		} else {
			if(fromCol < toCol) {
				for(int i = 1; i < fromRow - toRow; i++) {
					if(!board.getPiece(fromRow - i, fromCol + i)->getCaptured()) {
						return false;
					}
				}
			} else {
				for(int i = 1; i < fromRow - toRow; i++) {
					if(!board.getPiece(fromRow - i, fromCol - i)->getCaptured()) {
						return false;
					}
				}
			}
		}
	}

	//All checks have passed
	return true;
}

bool Queen::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
