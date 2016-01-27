#ifndef PAWN_H
#define PAWN_H

//Include
#include "piece.hpp"
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class Pawn : public Piece {
public:
	//Constructor
	Pawn(side_t _side);

	//Destructor
	~Pawn();

	//Functions
	bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);

private:
	//Functions
	bool enpassantCheck(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
};

#endif //PAWN_H
