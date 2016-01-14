#ifndef KING_H
#define KING_H

//Include
#include "piece.hpp"

//Declaration
class King : public Piece {
public:
	//Constructor
	King();

	//Destructor
	~King();

	//Functions
	bool checkMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol, bool threatened);
	bool move(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol);
	bool checkmate(Piece[8][8] board);

private:
	bool hasMoved;
};

#endif //KING_H
