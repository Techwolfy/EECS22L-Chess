#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Includes
#include "piece.hpp"

//Declaration
class ChessBoard {
friend class Piece;
public:
	//Constructor
	ChessBoard();

	//Destructor
	~ChessBoard();

	//Functions
	void display();
	side_t getWinner();
	bool move(int fromRow, int fromCol, int toRow, int toCol);
	void swap(int fromRow, int fromCOl, int toRow, int toCol);
	bool isThreatened(int row, int col);

private:
	//Variables
	Piece pieces[8][8];
};

#endif //CHESSBOARD_H
