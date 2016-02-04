#ifndef KNIGHT_H
#define KNIGHT_H

//Include
#include "piece.hpp"
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class Knight : public Piece {
public:
	//Constructor
	Knight(side_t _side);

	//Destructor
	~Knight();

	//Functions
	bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
};

#endif //KNIGHT_H
