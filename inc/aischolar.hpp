#ifndef AISCHOLAR_H
#define AISCHOLAR_H

//Includes
#include "chessboard.hpp"
#include "ai.hpp"
#include "player.hpp"

//Declaration
class AIScholar : public Player {
public:
	//Constructor
	AIScholar();

	//Destructor
	~AIScholar();

	//Functions
	void getMove(ChessBoard &board, int *fromRow, int *fromCol, int *toRow, int *toCol);

private:
	int currentMove;
	AI ai;
};

#endif //AISCHOLAR_H
