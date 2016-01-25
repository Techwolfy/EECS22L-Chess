#include <stdio.h>
#include "chessboard.hpp"
#include "player.hpp"
#include "types.hpp"

int main(int argc, char *argv[]) {
	Player player;
	Player ai;
	ChessBoard board;
	int fromRow = 0, fromCol = 0, toRow = 0, toCol = 0;
	bool playerMove = true;
	char playerSide = 'w';

	printf("Choose a side (w for white, b for black): ");
	scanf("%c", &playerSide);
	if(playerSide == 'w') {
		player.setSide(WHITE);
	} else if(playerSide == 'b') {
		player.setSide(BLACK);
	} else {
		printf("Invalid input! Defaulted to White.\n");
		player.setSide(WHITE);
	}

	while(true) {
		while(board.getWinner() == NEITHER) {
			if(playerMove) {
				player.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				while(board.move(player.getSide(), fromRow, fromCol, toRow, toCol) == false) {
					//Invalid move, try again
					player.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				}
				playerMove = false;
			} else {
				ai.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				while(board.move(player.getSide(), fromRow, fromCol, toRow, toCol) == false) {
					//Invalid move, try again (should never happen for AI...)
					ai.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				}
				playerMove = true;
			}
		}

		//Game over
		if(board.getWinner() == WHITE) {
			//White won
			printf("White won!\n");
		} else if(board.getWinner() == BLACK) {
			//Black won
			printf("Black won!\n");
		}

		//Prompt for input (new game or quit)
		break;
	}

	return 0;
}
