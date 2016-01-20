#ifndef PIECE_H
#define PIECE_H

//Includes
//#include "chessboard.hpp"
#include "types.hpp"

//Forward declaration of ChessBoard
class ChessBoard;

//Declaration
class Piece {
public:
	//Constructor
	Piece();

	//Destructor
	~Piece();

	//Functions
	chess_t getType();
	side_t getSide();
	char getDisplayChar();
	bool getMoved();
	void setMoved();
	virtual bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool checkmate(ChessBoard &board, int row, int col);

protected:
	//Variables
	chess_t type;
	side_t side;
	char display;
	bool hasMoved;
};

#endif //PIECE_H
