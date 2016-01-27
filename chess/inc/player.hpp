#ifndef PLAYER_H
#define PLAYER_H

//Includes
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class Player {
public:
	//Constructor
	Player();

	//Destructor
	virtual ~Player();

	//Functions
	side_t getSide();
	void setSide(side_t _side);
	virtual void getMove(ChessBoard &board, int *fromRow, int *fromCol, int *toRow, int *toCol);

protected:
	//Variables
	side_t side;
};

#endif //PLAYER_H
