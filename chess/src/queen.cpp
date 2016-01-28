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
	//Diagonal, same column, or same row movement
	if(abs(toCol - fromCol) == abs(toRow - fromRow) || toRow == fromRow || toCol == fromCol) {
		//TODO: Check if there are other pieces in the way!
		if(toCol==fromCol && toRow > fromRow) {
			for (int i=fromRow+1;i<toRow;i++) {
				if(board.getPiece(i,fromCol)->getCaptured()!=true) {
					return false;
				}
			}
		}
		else if(toCol==fromCol && toRow < fromRow) {
			for (int i=fromRow-1;i>toRow;i--) {
				if(board.getPiece(i,fromCol)->getCaptured()!=true) {
					return false;
				}
			}
		}
		else if(toRow==fromRow && toCol > fromCol) {
			for (int i=fromCol+1;i<toCol;i++) {
				if(board.getPiece(fromRow,i)->getCaptured()!=true) {
					return false;
				}
			}
		}
		else if(toRow==fromRow && toCol < fromCol) {
			for (int i=fromCol-1;i>toCol;i--) {
				if(board.getPiece(fromRow,i)->getCaptured()!=true) {
					return false;
				}
			}
		}
		else if(fromRow<toRow){
			if(fromCol<toCol){
				for(int i=1; i<toRow-fromRow; i++){
					if(board.getPiece(fromRow+i,fromCol+i)->getCaptured()!=true) return false;
				}
			}
			else if(fromCol>toCol){
				for(int i=1; i<toRow-fromRow; i++){
					if(board.getPiece(fromRow+i,fromCol-i)->getCaptured()!=true) return false;
				}
			}
		}
		else if(fromRow>toRow){
			if(fromCol<toCol){
				for(int i=1; i<fromRow-toRow; i++){
					if(board.getPiece(fromRow-i,fromCol+i)->getCaptured()!=true) return false;
				}
			}
			else if(fromCol>toCol){
				for(int i=1; i<fromRow-toRow; i++){
					if(board.getPiece(fromRow-i,fromCol-i)->getCaptured()!=true) return false;
				}
			}
		}
		if(board.getPiece(toRow,toCol)->getSide()==this->side){
			return false;
		}
		return true;
	}

	//All checks have failed
	return false;
}

bool Queen::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}
