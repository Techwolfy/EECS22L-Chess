//Piece.cpp

//Includes
#include "chessboard.hpp"
#include "piece.hpp"

//Constructor
Piece::Piece() : type(NONE),
				 side(NEITHER),
				 display(' ') {

}

//Destructor
Piece::~Piece() {

}

//Functions
//Return type of chess piece
chess_t Piece::getType() {
	return type;
}

//Return the side the piece is on
side_t Piece::getSide() {
	return side;
}

//Return character to display for chess piece
char Piece::getDisplayChar() {
	return display;
}

//Check if a move is valid
bool Piece::checkMove(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol, bool threatened) {
	//Blank piece object
	return false;
}

//Make a move if it is valid
bool Piece::move(Piece[8][8] board, int fromRow, int fromCol, int toRow, int toCol) {
	//Blank piece object
	return false;
}

//Revert the previous move
bool Piece::revertMove(Piece[8][8] board, int fromRow, int toRow, int toCol) {
	//Black piece object
	return false;
}

//Check if the game is over
side_t Piece::checkmate(Piece[8][8] board) {
	//Only the king should implement this
	return NEITHER;
}
