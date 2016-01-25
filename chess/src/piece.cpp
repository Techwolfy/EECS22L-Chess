//Piece.cpp

//Includes
#include "chessboard.hpp"
#include "piece.hpp"

//Constructor
Piece::Piece() : type(NONE),
				 side(NEITHER),
				 display(" "),
				 hasMoved(true),
				 isCaptured(true) {

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
const char* Piece::getDisplayChar() {
	if(!isCaptured) {
		return display;
	} else {
		return " ";
	}
}

//Check if the piece has moved
bool Piece::getMoved() {
	//Defaults to true for blank pieces to prevent glitches when moving
	return hasMoved;
}

//Set the piece moved flag, for use when moved by another piece
void Piece::setMoved() {
	hasMoved = true;
}

void Piece::setCaptured() {
	isCaptured = true;
}

//Check if a move is valid
bool Piece::checkMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//Blank piece object
	return false;
}

//Make a move if it is valid
bool Piece::move(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//Blank piece object
	return false;
}

//Revert the previous move
bool Piece::revertMove(ChessBoard &board, int fromRow, int fromCol, int toRow, int toCol) {
	//Black piece object
	return false;
}

//Check if the game is over
bool Piece::checkmate(ChessBoard &board, int row, int col) {
	//Only the king should implement this
	return NEITHER;
}
