#include <stdio.h>
#include "chessboard.hpp"
#include "player.hpp"
#include "ai.hpp"
#include "types.hpp"

int main(int argc, char *argv[]) {
	Player player,player2;
	AI ai;
	ChessBoard board;
	int fromRow = 0, fromCol = 0, toRow = 0, toCol = 0;
	bool playerMove = true, playerMove2 = false;
	char playerSide = 'w';
  int playermode;

	printf("Choose a side (w for white, b for black): ");
	scanf("%c", &playerSide);
  printf("Choose mode (pvp(1),pvc(2),cvc(3)): ");
  scanf("%d", &playermode);
  
  if(playermode == 1){
    if(playerSide == 'w') {
		player.setSide(WHITE);
		player2.setSide(BLACK);
		playerMove = true;
    playerMove2 = false;
	  } 
      else if(playerSide == 'b') {
		    player.setSide(BLACK);
		    player2.setSide(WHITE);
        playerMove = false;
		    playerMove2 = true;
	      } 
          else {
		        printf("Invalid input! Defaulted to White.\n");
		        player.setSide(WHITE);
		        player2.setSide(BLACK);
		        playerMove = true;
            playerMove2 = false;
	        }
  }
  
  if(playermode == 2){
    if(playerSide == 'w') {
		player.setSide(WHITE);
		ai.setSide(BLACK);
		playerMove = true;
	  } 
      else if(playerSide == 'b') {
		  player.setSide(BLACK);
		  ai.setSide(WHITE);
		  playerMove = false;
	    }   
        else {
        printf("Invalid input! Defaulted to White.\n");
		    player.setSide(WHITE);
		    ai.setSide(BLACK);
		    playerMove = true;
	      }
  }
  
  if (playermode == 3){
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
  }


	while(true) {
		while(board.getWinner() == NEITHER) {
			if(playerMove) {
				//Loops on invalid move
				do {
					player.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				} while(board.move(player.getSide(), fromRow, fromCol, toRow, toCol) == false);
				playerMove = false;
        if(playermode == 1){
          playerMove2 = true;
        }
			} 
      else if (playerMove2) {
        //Loops on invalid move
				do {
					player2.getMove(board, &fromRow, &fromCol, &toRow, &toCol);
				} while(board.move(player2.getSide(), fromRow, fromCol, toRow, toCol) == false);
				playerMove2 = false;
        playerMove = true;
			} 
      else{
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
