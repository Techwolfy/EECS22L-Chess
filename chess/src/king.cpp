//King.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "king.hpp"

//Constructor
King::King(side_t _side) {
	type = KING;
	side = _side;
	hasMoved = false;
	isCaptured = false;
	if(_side == WHITE) {
		display = "♚";
	} else {
		display = "♔";
	}
}

//Destructor
King::~King() {

}

//Functions
bool King::checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	bool isCastling = false;
	//Only one square away, unless castling
	if(abs(fromRow - toRow) > 1 || abs(fromCol - toCol) > 1) {
		if(!hasMoved && fromRow == toRow && abs(fromCol - toCol) == 2) {
			isCastling = true;
		} else {
			return false;
		}
	}

	//New square must not be threatened (king can't move into check)
	//NB: Check is performed in King::move, since checking here causes an infinite loop

	//If castling, rook must not have moved either, and no pieces can be between them
	if(isCastling) {
		if(fromCol < toCol) {
			if(!board.getPiece(fromRow, 3)->getCaptured() || !board.getPiece(fromRow, 2)->getCaptured() || !board.getPiece(fromRow, 1)->getCaptured()) {
				//Pieces are in the way
				return false;
			}
			if(board.getPiece(fromRow, 0)->getType() != ROOK || board.getPiece(fromRow, 0)->getMoved()) {
				//Rook has moved
				return false;
			}
		} else {
			if(!board.getPiece(fromRow, 5)->getCaptured() || !board.getPiece(fromRow, 6)->getCaptured()) {
				//Pieces are in the way
				return false;
			}
			if(board.getPiece(fromRow, 7)->getType() != ROOK || board.getPiece(fromRow, 7)->getMoved()) {
				//Rook has moved
				return false;
			}
		}
	}

	//All checks have passed
	return true;
}

bool King::move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	if(!checkMove(board, fromRow, fromCol, toRow, toCol)) {
		return false;
	}

	//Check if king is castling
	bool isCastling = false;
	if(fromRow == toRow && abs(fromCol - toCol) == 2) {
		isCastling = true;
	}

	//Check if target square or squares in between are threatened
	side_t threat = board.isThreatened(toRow, toCol);
	if(threat != NEITHER && threat != side) {
		return false;
	} else {
		if(isCastling) {
			if(fromCol < toCol) {
				threat = board.isThreatened(fromRow, fromCol + 1);
			} else {
				threat = board.isThreatened(fromRow, fromCol - 1);
			}
			if(threat != NEITHER && threat != side) {
				return false;
			}
		}
	}

	board.getPiece(toRow, toCol)->setCaptured();
	board.swap(fromRow, fromCol, toRow, toCol);
	if(isCastling) {
		if(fromCol < toCol) {
			board.getPiece(fromRow, 0)->setMoved();
			board.getPiece(fromRow, 0)->setCaptured();
			board.swap(fromRow, 0, fromCol, fromCol + 1);
		} else {
			board.getPiece(fromRow, 7)->setCaptured();
			board.swap(fromRow, 7, fromCol, fromCol - 1);
		}
	}
	hasMoved = true;
	return true;
}

bool King::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}

bool King::checkmate(ChessBoard &board, int row, int col) {
	side_t threat = NEITHER;
	if((threat = board.isThreatened(row, col)) == NEITHER || threat == side) {
		//King is not threatened; don't bother with the other checks
		return false;
	}

	isCaptured = true;	//Prevent the king from obstructing threatened squares

	//Check every piece to find which are threatening the king and surrounding squares
	for(int i = row - 1; i <= row + 1; i++) {
		for(int j = col - 1; j <= col + 1; j++) {
			if(i > 0 && i < 8 && j > 0 && j < 8){
				//For all squares surrounding the king, check if they are unoccupied first
				if(i != row && j != col && !board.getPiece(i, j)->getCaptured() && board.getPiece(i, j)->getSide() == side) {
					continue;
				}
				//Check if the king and surrounding squares are threatened
				threat = board.isThreatened(i, j);
				if(threat == NEITHER || threat == side) {
					isCaptured = false;
					return false;
				} else {}
			}
		}
	}

	isCaptured = false;

	//The king is threatened and can't move
	return true;
}
