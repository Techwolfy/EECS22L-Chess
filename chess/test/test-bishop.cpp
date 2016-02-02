#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"

int main() {
	ChessBoard b;

	assert(b.getPiece(0, 2)->getType() == BISHOP);
	assert(b.getPiece(0, 2)->getSide() == WHITE);
	assert(b.getPiece(0, 2)->getMoved() == false);
	assert(b.getPiece(0, 2)->getCaptured() == false);

	//Move a pawn out of the way
	b.move(WHITE, 1, 3, 3, 3);

	//Test bishop moves
	assert(b.getPiece(0, 2)->checkMove(b, 0, 2, 3, 5));
	assert(b.getPiece(0, 2)->move(b, 0, 2, 3, 5));
	assert(b.getPiece(3, 5)->checkMove(b, 3, 5, 4, 4));
	assert(b.getPiece(3, 5)->checkMove(b, 3, 5, 2, 4));
	assert(b.getPiece(3, 5)->checkMove(b, 3, 5, 2, 6));

	//Check if the bishop can move vertically.
	assert(b.getPiece(3, 5)->checkMove(b, 3, 5, 4, 5) == false);
	//Check if the bishop can move over pieces.
	assert(b.getPiece(3, 5)->checkMove(b, 3, 5, 7, 1) == false);

	printf("Bishop object tests passed!\n");
	return 0;
}
