#include "chessboard.hpp"
#include "player.hpp"
#include "types.hpp"

int main(int argc, char *argv[]) {
	Player player;
	Player ai;
	ChessBoard board;
	int fromRow = 0, fromCol = 0, toRow = 0, toCol = 0;

	while(true) {
		while(board.getWinner() == NEITHER) {
			board.display();

			player.getMove(&fromRow, &fromCol, &toRow, &toCol);
			while(board.move(fromRow, fromCol, toRow, toCol) == false) {
				//Invalid move, try again
				player.getMove(&fromRow, &fromCol, &toRow, &toCol);
			}

			ai.getMove(&fromRow, &fromCol, &toRow, &toCol);
			while(board.move(fromRow, fromCol, toRow, toCol) == false) {
				//Invalid move, try again (should never happen for AI...)
				ai.getMove(&fromRow, &fromCol, &toRow, &toCol);
			}
		}

		//Game over
		if(board.getWinner() == WHITE) {
			//White won
		} else if(board.getWinner() == BLACK) {
			//Black won
		}

		//Prompt for input (new game or quit)
		break;
	}

	return 0;
}
