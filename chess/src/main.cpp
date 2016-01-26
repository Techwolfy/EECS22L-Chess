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
		ai.setSide(BLACK);
		playerMove = true;
	} else if(playerSide == 'b') {
		player.setSide(BLACK);
		ai.setSide(WHITE);
		playerMove = false;
	} else {
		printf("Invalid input! Defaulted to White.\n");
		player.setSide(WHITE);
		ai.setSide(BLACK);
		playerMove = true;
	}

	while(true) {
		while(board.getWinner() == NEITHER) {
			if(playerMove) {
				//Loops on invalid move
				do {
					player.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				} while(board.move(player.getSide(), fromRow, fromCol, toRow, toCol) == false);
				playerMove = false;
			} else {
				//Loops on invalid move
				do {
					ai.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				} while(board.move(ai.getSide(), fromRow, fromCol, toRow, toCol) == false);
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
