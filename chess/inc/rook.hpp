#ifndef ROOK_H
#define ROOK_H

//Include
#include "piece.hpp"
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class Rook : public Piece {
public:
	//Constructor
	Rook(side_t _side);

	//Destructor
	~Rook();

	//Functions
	bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
};

#endif //ROOK_H
