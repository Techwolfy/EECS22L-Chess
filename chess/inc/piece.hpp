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
	virtual ~Piece();

	//Functions
	chess_t getType();
	side_t getSide();
	const char* getDisplayChar();
	bool getMoved();
	void setMoved();
	bool getCaptured();
	void setCaptured();
	virtual bool checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool checkmate(ChessBoard &board, int row, int col);

protected:
	//Variables
	chess_t type;
	side_t side;
	const char *display;
	bool hasMoved;
	bool isCaptured;
};

#endif //PIECE_H
