#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"

int main() {
	ChessBoard b;
	Piece *king = b.getPiece(7, 4);

	//Set up scholars' mate
	b.move(WHITE, 1, 4, 2, 4);
	b.move(WHITE, 0, 5, 3, 2);
	b.move(WHITE, 0, 3, 4, 7);
	b.move(WHITE, 4, 7, 6, 5);

	//Confirm checkmate:
	//Square must be threatened
	assert(b.isThreatened(6, 5) == BOTH);
	assert(b.isThreatened(7, 4) == BOTH);
	//Target piece must be king
	assert(king->getType() == KING);
	//King must not be able to move
	assert(king->move(b, 7, 4, 6, 5) == false);
	//King should be checkmated
	assert(king->checkmate(b, 7, 4));
	//Checkmate should be "WHITE"
	assert(b.getWinner() == WHITE);

	printf("Scholar's mate test passed!\n");
	return 0;
}
