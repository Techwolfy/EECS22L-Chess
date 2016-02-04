#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"

int main() {
	ChessBoard b;

	assert(b.getPiece(0, 3)->getType() == QUEEN);
	assert(b.getPiece(0, 3)->getSide() == WHITE);
	assert(b.getPiece(0, 3)->getMoved() == false);
	assert(b.getPiece(0, 3)->getCaptured() == false);

	//Move other pieces out of the way
	b.move(WHITE, 1, 3, 3, 3);
	b.move(WHITE, 3, 3, 4, 3);

	//Test queen moves
	assert(b.getPiece(0, 3)->checkMove(b, 0, 3, 2, 3));
	assert(b.getPiece(0, 3)->move(b, 0, 3, 2, 3));
	assert(b.getPiece(2, 3)->checkMove(b, 2, 3, 3, 4));
	assert(b.getPiece(2, 3)->move(b, 2, 3, 3, 4));
	assert(b.getPiece(3, 4)->checkMove(b, 3, 4, 3, 3));
	assert(b.getPiece(3, 4)->checkMove(b, 3, 4, 3, 5));
	assert(b.getPiece(3, 4)->checkMove(b, 3, 4, 2, 4));
	assert(b.getPiece(3, 4)->checkMove(b, 3, 4, 4, 4));

	//Check if the queen can move like a knight.
	assert(b.getPiece(3, 4)->checkMove(b, 3, 4, 2, 2) == false);
	//Check if the queen can move over pieces.
	b.move(BLACK, 6, 4, 4, 4);
	assert(b.getPiece(3, 4)->checkMove(b, 3, 4, 5, 4) == false);

	printf("Queen object tests passed!\n");
	return 0;
}
