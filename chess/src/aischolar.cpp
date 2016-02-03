//AIScholar.cpp

//Includes
#include <stdio.h>
#include "chessboard.hpp"
#include "types.hpp"
#include "ai.hpp"
#include "aischolar.hpp"

//Constructor
AIScholar::AIScholar() : currentMove(0),
						 ai() {

}

//Destructor
AIScholar::~AIScholar() {

}

//Functions
void AIScholar::getMove(ChessBoard &board, int *fromRow, int *fromCol, int *toRow, int *toCol) {
	switch(currentMove) {
		case 0:
			if(side == WHITE) {
				*fromRow = 1;
				*fromCol = 4;
				*toRow = 2;
				*toCol = 4;
			} else {
				*fromRow = 6;
				*fromCol = 4;
				*toRow = 5;
				*toCol = 4;
			}
			break;
		case 1:
			if(side == WHITE) {
				*fromRow = 0;
				*fromCol = 5;
				*toRow = 3;
				*toCol = 2;
			} else {
				*fromRow = 7;
				*fromCol = 5;
				*toRow = 4;
				*toCol = 2;
			}
			break;
		case 2:
			if(side == WHITE) {
				*fromRow = 0;
				*fromCol = 3;
				*toRow = 4;
				*toCol = 7;
			} else {
				*fromRow = 7;
				*fromCol = 3;
				*toRow = 3;
				*toCol = 7;
			}
			break;
		case 3:
			if(side == WHITE) {
				*fromRow = 4;
				*fromCol = 7;
				*toRow = 6;
				*toCol = 5;
			} else {
				*fromRow = 3;
				*fromCol = 7;
				*toRow = 1;
				*toCol = 5;
			}
			break;
		default:
			ai.getMove(board, fromRow, fromCol, toRow, toCol);
			break;
	}

	if(!board.checkMove(side, *fromRow, *fromCol, *toRow, *toCol)) {
		ai.getMove(board, fromRow, fromCol, toRow, toCol);
	}

	currentMove++;
}
