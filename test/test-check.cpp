#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"

int main() {
	ChessBoard b;
	Piece *king = b.getPiece(7, 4);

	//Move a pawn to prevent checkmate
	b.move(BLACK, 6, 4, 5, 4);

	//Set up scholars' mate
	b.move(WHITE, 1, 4, 2, 4);
	b.move(WHITE, 0, 5, 3, 2);
	b.move(WHITE, 0, 3, 4, 7);
	b.move(WHITE, 4, 7, 6, 5);

	//King and opposing queen must be threatened
	assert(b.isThreatened(6, 5) == BLACK);
	assert(b.isThreatened(7, 4) == BOTH);

	//Try to move without breaking check
	assert(b.move(BLACK, 7, 5, 6, 4) == false);

	//Capture the piece putting the king in check
	assert(b.move(BLACK, 7, 4, 6, 5));

	//King should not be checkmated
	assert(!king->checkmate(b, 6, 5));
	assert(b.getWinner() == NEITHER);

	printf("Check test passed!\n");
	return 0;
}
