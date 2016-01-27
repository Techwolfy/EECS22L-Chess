#include <stdio.h>
#include "chessboard.hpp"
#include "player.hpp"
#include "ai.hpp"
#include "types.hpp"

int main(int argc, char *argv[]) {
	Player *player;
	Player *ai;
	ChessBoard board;
	int fromRow = 0, fromCol = 0, toRow = 0, toCol = 0;
	bool playerMove = true;
	char playerSide = 'w';
	int gameMode = 0;

	printf("Available game modes:\n");
	printf("1. Player vs. Player\n");
	printf("2. Player vs. AI\n");
	printf("3. AI vs. AI\n");
	printf("Choose a game mode: ");
	scanf(" %d", &gameMode);

	switch(gameMode) {
		case 1:
			player = new Player();
			ai = new Player();
			break;
		case 2:
			player = new Player();
			ai = new AI();
			break;
		case 3:
			player = new AI();
			ai = new AI();
			break;
		default:
			printf("Invalid game mode! Defaulted to Player vs. AI.\n");
			player = new Player();
			ai = new AI();
			break;
	}

	if(gameMode == 1 || gameMode == 2) {
		printf("Player 1, choose a side (w for white, b for black): ");
		scanf(" %c", &playerSide);
	} else {
		playerSide = 'w';
	}

	if(playerSide == 'w' || playerSide == 'W') {
		player->setSide(WHITE);
		ai->setSide(BLACK);
		playerMove = true;
	} else if(playerSide == 'b' || playerSide == 'B') {
		player->setSide(BLACK);
		ai->setSide(WHITE);
		playerMove = false;
	} else {
		printf("Invalid input! Defaulted to White.\n");
		player->setSide(WHITE);
		ai->setSide(BLACK);
		playerMove = true;
	}

	while(board.getWinner() == NEITHER) {
		if(playerMove) {
			//Loops on invalid move
			do {
				player->getMove(board, &fromRow, &fromCol, &toRow, &toCol);
			} while(board.move(player->getSide(), fromRow, fromCol, toRow, toCol) == false);
			playerMove = false;
		} else {
			//Loops on invalid move
			do {
				ai->getMove(board, &fromRow, &fromCol, &toRow, &toCol);
			} while(board.move(ai->getSide(), fromRow, fromCol, toRow, toCol) == false);
			playerMove = true;
		}
	}

	//Game over
	if(board.getWinner() == WHITE) {
		//White won
		board.display();
		printf("White won!\n");
	} else if(board.getWinner() == BLACK) {
		//Black won
		board.display();
		printf("Black won!\n");
	}

	delete player;
	delete ai;
	return 0;
}
