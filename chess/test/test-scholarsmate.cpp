#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"

int main() {
	ChessBoard b;
	Piece *king = b.getPiece(7, 4);

	//Set up scholars' mate
	b.move(WHITE, 1, 4, 2, 4);
	b.move(WHITE, 0, 5, 4, 1);
	b.move(WHITE, 0, 3, 4, 7);
	b.move(WHITE, 4, 7, 6, 5);
	b.display();

	//Confirm checkmate:
	//Square must be threatened
	assert(b.isThreatened(7, 4) == BOTH);
	//Target piece must be king
	assert(king->getType() == KING);
	//King must not be able to move
	assert(king->checkMove(b, 7, 4, 6, 5) == false);
	assert(king->move(b, 7, 4, 6, 5) == false);
	//Checkmate should be "WHITE"
	assert(king->checkmate(b, 7, 4) == WHITE);

	printf("Scholar's mate test passed!\n");
	return 0;
}
