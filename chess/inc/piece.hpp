#ifndef PIECE_H
#define PIECE_H

//Declaration
class Piece {
public:
	//Constructor
	Piece();

	//Destructor
	~Piece();

	//Functions
	virtual void display();
	virtual bool checkMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol);

	//Variables
	const enum chess_t {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};

private:
	//Variables
	char text = ' ';
};

#endif //PIECE_H
