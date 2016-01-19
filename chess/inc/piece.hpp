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
	virtual bool hasMoved();
	virtual void setMoved();
	virtual bool checkMove(ChessBoard board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool move(ChessBoard board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool revertMove(ChessBoard board, int fromRow, int fromCol, int toRow, int toCol);
	virtual bool checkmate(ChessBoard board);

	//Variables
	const enum chess_t {NONE = 0, KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};
	const enum side_t {NEITHER = 0, WHITE, BLACK, BOTH};

private:
	//Variables
	chess_t type;
	side_t side;
	char display;
	bool hasMoved;
};

#endif //PIECE_H
