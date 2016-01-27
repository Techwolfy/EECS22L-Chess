#ifndef AI_H
#define AI_H

//Includes
#include "chessboard.hpp"
#include "types.hpp"

//Declaration
class AI : public Player {
public:
	//Constructor
	AI();

	//Destructor
	~AI();

	//Functions
	void getMove(ChessBoard &board, int *fromRow, int *fromCol, int *toRow, int *toCol);
};

#endif //AI_H
