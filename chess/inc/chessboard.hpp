#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Includes
#include <stdio.h>
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
	Piece* getPiece(int row, int col);
	side_t getWinner();
	bool checkMove(side_t side, int fromRow, int fromCol, int toRow, int toCol, bool displayErrors = false);
	bool move(side_t side, int fromRow, int fromCol, int toRow, int toCol);
	void swap(int fromRow, int fromCol, int toRow, int toCol);
	void promote(side_t side, int fromRow, int fromCol, int toRow, int toCol);
	side_t isThreatened(int row, int col);
	bool moveResolvesCheck(side_t side, int fromRow, int fromCol, int toRow, int toCol);
	void listPieces(chess_t list[8][8]);
  Piece* getLast();

private:
	//Variables
  Piece *lastPiece;
	Piece *pieces[8][8];
	FILE *logFile;

	//Functions
	bool checkMoveAllowOverlap(side_t side, int fromRow, int fromCol, int toRow, int toCol, bool displayErrors = false);
};

#endif //CHESSBOARD_H
