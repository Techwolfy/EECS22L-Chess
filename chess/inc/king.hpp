#ifndef KING_H
#define KING_H

//Include
#include "piece.hpp"
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class King : public Piece {
public:
	//Constructor
	King(side_t _side);

	//Destructor
	~King();

	//Functions
	bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool checkmate(ChessBoard &board, int row, int col);
};

#endif //KING_H
