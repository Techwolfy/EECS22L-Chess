#ifndef BISHOP_H
#define BISHOP_H

//Include
#include "piece.hpp"
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class Bishop : public Piece {
public:
	//Constructor
	Bishop(side_t _side);

	//Destructor
	~Bishop();

	//Functions
	bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
};

#endif //BISHOP_H
