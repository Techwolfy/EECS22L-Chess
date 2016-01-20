#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Includes
#include "piece.hpp"
#include "types.hpp"

//Forward declaration of Piece
class Piece;

//Declaration
class ChessBoard {
public:
	//Constructor
	ChessBoard();

	//Destructor
	~ChessBoard();

	//Functions
	void display();
	Piece** getPieces();
	side_t getWinner();
	bool move(int fromRow, int fromCol, int toRow, int toCol);
	void swap(int fromRow, int fromCol, int toRow, int toCol);
	side_t isThreatened(int row, int col);

private:
	//Variables
	Piece pieces[8][8];
};

#endif //CHESSBOARD_H
