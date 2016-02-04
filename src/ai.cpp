//AI.cpp

//Includes
#include <stdio.h>
#include "chessboard.hpp"
#include "types.hpp"
#include "player.hpp"
#include "ai.hpp"

//Constructor
AI::AI() {

}

//Destructor
AI::~AI() {

}

//Functions
void AI::getMove(ChessBoard &board, int *fromRow, int *fromCol, int *toRow, int *toCol) {
	int kingx, kingy;
	bool isKing = false, isKing1 = false, isKing2 = false;

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if((board.getPiece(i, j)->getSide() == side) && board.getPiece(i,j)->getType() == KING) {
				*fromRow = i;
				*fromCol = j;
				isKing = true;
				break;
			}
		}
		if(isKing) {
			break;
		}
	}

	side_t threat = board.isThreatened(*fromRow, *fromCol);
	if(threat != NEITHER && threat != side) {
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
					if(board.checkMove(side, *fromRow, *fromCol, i, j)) {
						*toRow = i;
						*toCol = j;
						isKing1 = true;
						break;
					}
			}
			if(isKing1) {
				break;
			}
		}
		return;
	}
 
//The first move is only for pawns.
	if(side==BLACK){
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				if(!board.getPiece(i,j)->getCaptured() && board.getPiece(i, j)->getSide() == side) {   
					for(int k = 0; k < 8; k++) {
						for(int l = 0; l < 8; l++) {
							if(board.checkMove(side, i, j, k, l) && !(i == k && j == l)) {
								*fromRow = i;
								*fromCol = j;
								*toRow = k;
								*toCol = l;
								isKing2 = true;
								break;
							}
						}
						if(isKing2) {
							break;
						}
					}
				}
				if(isKing2) {
					break;
				}
			}

			if(isKing2) {
				break;
			}
		}
	}
	else {
		for(int i = 7; i >= 0; i--) {
			for(int j = 7; j >= 0; j--) {
				if(!board.getPiece(i,j)->getCaptured() && board.getPiece(i, j)->getSide() == side) {   
					for(int k = 7; k >= 0; k--) {
						for(int l = 7; l >= 0; l--) {
							if(board.checkMove(side, i, j, k, l) && !(i == k && j == l)) {
								*fromRow = i;
								*fromCol = j;
								*toRow = k;
								*toCol = l;
								isKing2 = true;
								break;
							}
						}
						if(isKing2) {
							break;
						}
					}
				}
				if(isKing2) {
					break;
				}
			}

			if(isKing2) {
				break;
			}
		}
	}
	return;
}
