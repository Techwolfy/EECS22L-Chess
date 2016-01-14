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
	virtual chess_t getType();
	virtual char getDisplayChar();
	virtual bool checkMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol, bool threatened);
	virtual bool move(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool revertMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool checkmate(Piece[8][8] board);

	//Variables
	const enum chess_t {NONE = 0, KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};
	const enum side_t {NEITHER = 0, WHITE, BLACK};

private:
	//Variables
	chess_t type;
	side_t side;
	char display;
};

#endif //PIECE_H
