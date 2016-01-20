#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Includes
#include "piece.hpp"
#include "types.hpp"

//Declaration
class ChessBoard {
public:
	//Constructor
	ChessBoard();

	//Destructor
	~ChessBoard();

	//Functions
	void display();
	Piece getPiece(int row, int col);
	side_t getWinner();
	bool move(int fromRow, int fromCol, int toRow, int toCol);
	void swap(int fromRow, int fromCol, int toRow, int toCol);
	side_t isThreatened(int row, int col);

private:
	//Variables
	Piece **pieces;
};

#endif //CHESSBOARD_H
