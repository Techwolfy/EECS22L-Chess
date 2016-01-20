#ifndef PLAYER_H
#define PLAYER_H

//Declaration
class Player {
public:
	//Constructor
	Player();

	//Destructor
	~Player();

	//Functions
	virtual void getMove(int *fromRow, int *fromCol, int *toRow, int *toCol);
};

#endif //PIECE_H
