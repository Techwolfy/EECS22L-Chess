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
	virtual bool move(Piece[12][12] board, int fromRow, int fromCol, int toRow, int toCol);

	//Variables
	const enum chess_t {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};
};

#endif //PIECE_H
