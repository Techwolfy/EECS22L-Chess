#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Includes
#include "piece.hpp"

//Declaration
class ChessBoard {
public:
	//Constructor
	ChessBoard();

	//Destructor
	~ChessBoard();

	//Functions
	void display();
	bool move(int fromRow, int fromCol, int toRow, int toCol);
	side_t getWinner();

	//Variables
	const enum side_t {NONE = 0, WHITE, BLACK};

private:
	//Variables
	Piece pieces[8][8];
};

#endif //CHESSBOARD_H
