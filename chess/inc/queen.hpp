#ifndef QUEEN_H
#define QUEEN_H

//Include
#include "piece.hpp"
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class Queen : public Piece {
public:
	//Constructor
	Queen(side_t _side);

	//Destructor
	~Queen();

	//Functions
	bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);

};

#endif //QUEEN_H