#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"

int main() {
	ChessBoard b;

	assert(b.getPiece(0, 0)->getType() == ROOK);
	assert(b.getPiece(0, 0)->getSide() == WHITE);
	assert(b.getPiece(0, 0)->getMoved() == false);
	assert(b.getPiece(0, 0)->getCaptured() == false);

	//Move a pawn out of the way
	b.move(WHITE, 1, 0, 3, 0);
	b.move(WHITE, 3, 0, 4, 0);

	//Test rook moves
	assert(b.getPiece(0, 0)->checkMove(b, 0, 0, 3, 0));
	assert(b.getPiece(0, 0)->move(b, 0, 0, 3, 0));
	assert(b.getPiece(3, 0)->checkMove(b, 3, 0, 3, 3));
	assert(b.getPiece(3, 0)->move(b, 3, 0, 3, 3));
	assert(b.getPiece(3, 3)->checkMove(b, 3, 3, 3, 2));
	assert(b.getPiece(3, 3)->checkMove(b, 3, 3, 2, 3));

	//Check if the rook can move diagonally.
	assert(b.getPiece(3, 3)->checkMove(b, 3, 3, 4, 4) == false);
	//Check if the rook can move over pieces.
	b.move(BLACK, 6, 1, 4, 1);
	b.move(BLACK, 4, 1, 3, 1);
	assert(b.getPiece(3, 3)->checkMove(b, 3, 3, 3, 0) == false);

	printf("Rook object tests passed!\n");
	return 0;
}
