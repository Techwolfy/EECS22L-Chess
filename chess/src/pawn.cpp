//Pawn.cpp

//Includes
#include <stdlib.h>
#include "piece.hpp"
#include "chessboard.hpp"
#include "pawn.hpp"

//Constructor
Pawn::Pawn(side_t _side) {
	type = PAWN;
	side = _side;
	hasMoved = false;
	isCaptured = false;
	if(_side == WHITE) {
		display = "♟";
	} else {
		display = "♙";
	}
}

//Destructor
Pawn::~Pawn() {

}

bool Pawn::checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Move setting of enPassant variable to Pawn::move!
	if(side == WHITE) {
		if(fromRow == 1 && fromCol == toCol && toRow == (fromRow + 2)
		&& board.getPiece(fromRow + 1, fromCol)->getCaptured() && board.getPiece(fromRow + 2, fromCol)->getCaptured()) {
			enPassant = true;
			return true;
		}
		else if(toRow == (fromRow + 1) && toCol == fromCol && board.getPiece(fromRow + 1, fromCol)->getCaptured()) {
			enPassant = false;
			return true;
		}
		else if(toRow == (fromRow + 1) && (toCol == (fromCol + 1) || toCol == (fromCol - 1))
		&& board.getPiece(toRow, toCol)->getSide() == BLACK) {
			enPassant = false;
			return true;
		}
		else if(enpassantCheck(board, fromRow, fromCol, toRow, toCol)) {
			return true;
		}
	} else if(side == BLACK) {
		if(fromRow == 6 && fromCol == toCol && toRow == (fromRow - 2)
		&& board.getPiece(fromRow - 1, fromCol)->getCaptured() && board.getPiece(fromRow - 2, fromCol)->getCaptured()) {
			enPassant = true;
			return true;
		}
		else if(toRow == (fromRow - 1) && toCol == fromCol && board.getPiece(fromRow - 1, fromCol)->getCaptured()) {
			enPassant = false;
			return true;
		}
		else if(toRow == (fromRow - 1) && (toCol == (fromCol + 1) || toCol == (fromCol - 1))
		&& board.getPiece(toRow, toCol)->getSide() == WHITE) {
			enPassant = false;
			return true;
		}
		else if(enpassantCheck(board, fromRow, fromCol, toRow, toCol)) {
			return true;
		}
	}

	//All checks have failed
	return false;
}

bool Pawn::move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	if(!checkMove(board, fromRow, fromCol, toRow, toCol)) {
		return false;
	}

	if(!enpassantCheck(board, fromRow, fromCol, toRow, toCol)) {
		if(toRow == 0 || toRow == 7) {
			board.promote(board.getPiece(toRow, toCol)->getSide(), fromRow, fromCol);
			board.getPiece(fromRow, fromCol)->setCaptured();
		} else{
			board.getPiece(toRow, toCol)->setCaptured();
			board.swap(fromRow, fromCol, toRow, toCol);
			hasMoved = true;
			return true;
		}
	} else {
		if(side == WHITE) {
			board.getPiece(toRow - 1, toCol)->setCaptured();
			board.swap(fromRow, fromCol, toRow, toCol);
			hasMoved = true;
			return true;
		} else {
			board.getPiece(toRow + 1, toCol)->setCaptured();
			board.swap(fromRow, fromCol, toRow, toCol);
			hasMoved = true;
			return true;
		}
	}
}

bool Pawn::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//TODO: Implement
}

bool Pawn::enpassantCheck(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	if(side == WHITE && fromRow == 4) {
		if((fromCol - 1) >= 0 && board.getPiece(fromRow, fromCol - 1)->getSide() == BLACK
		&& board.getPiece(fromRow, fromCol - 1)->getEnPassant() && toRow == (fromRow + 1) && toCol == (fromCol - 1)) {
			return true;
		}
		else if((fromCol + 1) <= 7 && board.getPiece(fromRow, fromCol + 1)->getSide() == BLACK
		&& board.getPiece(fromRow, fromCol + 1)->getEnPassant() && toRow == (fromRow + 1) && toCol == (fromCol + 1)) {
			return true;
		}
	} else if(side == BLACK && fromRow == 3) {
		if((fromCol - 1) >= 0 && board.getPiece(fromRow, fromCol - 1)->getSide() == WHITE
		&& board.getPiece(fromRow, fromCol - 1)->getEnPassant() && toRow == (fromRow - 1) && toCol == (fromCol - 1)) {
			return true;
		}
		else if((fromCol + 1) <= 7 && board.getPiece(fromRow, fromCol + 1)->getSide() == WHITE
		&& board.getPiece(fromRow, fromCol + 1)->getEnPassant() && toRow == (fromRow - 1) && toCol == (fromCol + 1)) {
			return true;
		}
	}

	//All tests have failed
	return false;
}
