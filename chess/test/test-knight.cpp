#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"

int main() {
	ChessBoard b;

	assert(b.getPiece(0, 1)->getType() == KNIGHT);
	assert(b.getPiece(0, 1)->getSide() == WHITE);
	assert(b.getPiece(0, 1)->getMoved() == false);
	assert(b.getPiece(0, 1)->getCaptured() == false);

	//Test knight moves
	assert(b.getPiece(0, 1)->checkMove(b, 0, 1, 2, 2));
	assert(b.getPiece(0, 1)->move(b, 0, 1, 2, 2));
	assert(b.getPiece(2, 2)->checkMove(b, 2, 2, 3, 0));
	assert(b.getPiece(2, 2)->checkMove(b, 2, 2, 4, 1));
	assert(b.getPiece(2, 2)->checkMove(b, 2, 2, 4, 3));
	assert(b.getPiece(2, 2)->checkMove(b, 2, 2, 3, 4));
	assert(b.getPiece(2, 2)->move(b, 2, 2, 4, 3));
	assert(b.getPiece(4, 3)->checkMove(b, 4, 3, 3, 1));
	assert(b.getPiece(4, 3)->checkMove(b, 4, 3, 2, 2));
	assert(b.getPiece(4, 3)->checkMove(b, 4, 3, 2, 4));
	assert(b.getPiece(4, 3)->checkMove(b, 4, 3, 3, 5));

	//Check if the knight can move vertically.
	assert(b.getPiece(4, 3)->checkMove(b, 4, 3, 2, 3) == false);
	//Check if the knight can move diagonally.
	assert(b.getPiece(4, 3)->checkMove(b, 4, 3, 2, 1) == false);

	printf("Knight object tests passed!\n");
	return 0;
}
