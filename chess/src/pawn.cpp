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

	
	if(fromRow == 1 && (fromCol == toCol) && (board.getPiece(fromRow, fromCol)->getSide() == WHITE) && (toRow == fromRow+2) &&
	(board.getPiece(fromRow+1, fromCol)->getCaptured() == true) && (board.getPiece(fromRow+2, fromCol)->getCaptured() == true)) {
			return true;
		} 
	else if(fromRow == 6 && (fromCol == toCol) && (board.getPiece(fromRow, fromCol)->getSide() == BLACK) && (toRow == fromRow-2) &&
	(board.getPiece(fromRow-1, fromCol)->getCaptured() == true) && (board.getPiece(fromRow-2, fromCol)->getCaptured() == true)) {
			return true;
		} 
	else if((board.getPiece(fromRow, fromCol)->getSide() == WHITE) && (toRow == fromRow+1) && (toCol == fromCol) && 
           (board.getPiece(fromRow+1, fromCol)->getCaptured() == true)){
			return true;
		}
	else if((board.getPiece(fromRow, fromCol)->getSide() == BLACK) && (toRow == fromRow-1) && (toCol == fromCol) && 
          (board.getPiece(fromRow-1, fromCol)->getCaptured() == true  )){
			return true;
		}
	else if((board.getPiece(fromRow, fromCol)->getSide() == WHITE) && (toRow == fromRow+1) && ((toCol == fromCol+1) || (toCol == fromCol-1)) && 
          (board.getPiece(toRow, toCol)->getSide() == BLACK)) {
			return true;
		}
	else if((board.getPiece(fromRow, fromCol)->getSide() == BLACK) && (toRow == fromRow-1) && ((toCol == fromCol+1) || (toCol == fromCol-1)) && 
          (board.getPiece(toRow, toCol)->getSide() == WHITE)){
			return true;
		}
	else if(enpassantCheck(board, fromRow, fromCol, toRow, toCol)){
		
			return true;
	}
	else {
			return false;
		}
	
}

bool Pawn::move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	if(!checkMove(board, fromRow, fromCol, toRow, toCol)) {
		return false;
	}
  
	if(!enpassantCheck(board, fromRow, fromCol, toRow, toCol)){
     if((toRow == 0) || (toRow == 7)){
       board.promotion(toRow, toCol, board.getPiece(fromRow, fromCol)->getSide());
       board.getPiece(fromRow, fromCol)->setCaptured();
     }
     else{
		  board.getPiece(toRow, toCol)->setCaptured();
		  board.swap(fromRow, fromCol, toRow, toCol);
		  hasMoved = true; 
		  return true;
      }
	}
	else {
		if(board.getPiece(fromRow, fromCol)->getSide() == WHITE){
			board.getPiece(toRow-1, toCol)->setCaptured();
			board.swap(fromRow, fromCol, toRow, toCol);
			hasMoved = true;
			return true;	
		}
		else {
			board.getPiece(toRow+1, toCol)->setCaptured();
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
	if((board.getPiece(fromRow, fromCol)->getSide() == WHITE) && (fromRow == 4) && (fromCol-1 >=0) && (board.getPiece(fromRow, fromCol-1)->getSide() == BLACK) && 
		(board.getPiece(fromRow, fromCol-1)->getType() == PAWN) && (toRow == fromRow+1) && (toCol == fromCol-1)){
			return true;
		}
		else if((board.getPiece(fromRow, fromCol)->getSide() == BLACK) && (fromRow == 3) && (fromCol-1 >=0) && (board.getPiece(fromRow, fromCol-1)->getSide() == WHITE) && 
		(board.getPiece(fromRow, fromCol-1)->getType() == PAWN) && (toRow == fromRow-1) && (toCol == fromCol-1)){
			return true;
		}
	  else if((board.getPiece(fromRow, fromCol)->getSide() == WHITE) && (fromRow == 4) && (fromCol+1 <= 7) && (board.getPiece(fromRow, fromCol+1)->getSide() == BLACK) && 
		(board.getPiece(fromRow, fromCol+1)->getType() == PAWN) && (toRow == fromRow+1) && (toCol == fromCol+1)){
			return true;
		}
		else if((board.getPiece(fromRow, fromCol)->getSide() == BLACK) && (fromRow == 3) && (fromCol+1 <=7) && (board.getPiece(fromRow, fromCol+1)->getSide() == WHITE) && 
		(board.getPiece(fromRow, fromCol+1)->getType() == PAWN) && (toRow == fromRow-1) && (toCol == fromCol+1)){
			return true;
		}
    else {
      return false;
		}
}
