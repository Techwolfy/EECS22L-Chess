//Bishop.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "Bishop.hpp"

//Constructor
Bishop::Bishop(side_t _side) {
	type = Bishop;
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
	//Out of bounds
	if(fromRow < 0 || fromRow > 7 || fromCol < 0 || fromCol > 7 || toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7) {
		return false;
	}

	bool isCastling = false;
	//Only one square away, unless castling
	if(abs(fromRow - toRow) > 1 || abs(fromCol - toCol) > 1) {
		if(!hasMoved && fromRow == toRow && abs(fromCol - toCol) == 2) {
			isCastling = true;
		} else {
			return false;
		}
	}

	//New square must not be threatened (Bishop can't move into check)
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

	//If castling, rook must not have moved either
	if(isCastling) {
		if(fromCol < toCol) {
			if(board.getPiece(fromRow, 0).getType() != ROOK || board.getPiece(fromRow, 0).getMoved()) {
				return false;
			}
		} else {
			if(board.getPiece(fromRow, 0).getType() != ROOK || board.getPiece(fromRow, 7).getMoved()) {
				return false;
			}
		}
	}

	//All checks have passed
	return true;
}

bool Bishop::move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	bool isCastling = false;
	if(fromRow == toRow && abs(fromCol - toCol) == 2) {
		isCastling = true;
	}

	board.swap(fromRow, fromCol, toRow, toCol);
	if(isCastling) {
		if(fromCol < toCol) {
			board.getPiece(fromRow, 0).setMoved();
			board.swap(fromRow, 0, fromCol, fromCol + 1);
		} else {
			board.getPiece(fromRow, 7).setMoved();
			board.swap(fromRow, 7, fromCol, fromCol - 1);
		}
	}
	hasMoved = true;
	return true;
}

bool Bishop::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}

	return true;
}
