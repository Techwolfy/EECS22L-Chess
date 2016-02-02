#include <stdio.h>
#include <assert.h>
#include "types.hpp"
#include "chessboard.hpp"
#include "piece.hpp"

int main() {
	Piece p;
	ChessBoard b;	//Default chessboard; not read at this level

	assert(p.getType() == NONE);
	assert(p.getSide() == NEITHER);
	assert(p.getDisplayChar()[0] == ' ');
	assert(p.getDisplayChar()[1] == '\0');
	assert(p.getMoved());
	assert(p.getCaptured());
	
	//TODO: En-passant logic?
  	
  	assert(p.checkMove(b, 0, 0, 0, 0) == false);
  	assert(p.move(b, 0, 0, 0, 0) == false);
  	assert(p.revertMove(b, 0, 0, 0, 0) == false);
  	assert(p.checkmate(b, 0, 0) == NEITHER);

  	printf("Piece object tests passed!\n");
	return 0;
}
