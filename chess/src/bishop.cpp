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
	isCaptured = false;
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

bool Bishop::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
