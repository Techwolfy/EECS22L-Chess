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
	bool checkMove(ChessBoard board, int fromRow, int fromCol, int toRow, int toCol);
	bool move(ChessBoard board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(ChessBoard board, int fromRow, int fromCol, int toRow, int toCol);
	bool checkmate(ChessBoard board);
};

#endif //KING_H
