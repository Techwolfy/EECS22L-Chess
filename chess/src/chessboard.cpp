//ChessBoard.cpp

//Includes
#include <stdio.h>
#include "chessboard.hpp"
#include "piece.hpp"
#include "king.hpp"

//Constructor
ChessBoard::ChessBoard() {
	pieces = new Piece *[8];
	pieces[0] = new Piece[8] {Rook(BLACK), Knight(BLACK), Bishop(BLACK), King(BLACK), Queen(BLACK), Bishop(BLACK), Knight(BLACK), Rook(BLACK)};
	pieces[1] = new Piece[8] {Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK)};
	pieces[2] = new Piece[8] {Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()};
	pieces[3] = new Piece[8] {Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()};
	pieces[4] = new Piece[8] {Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()};
	pieces[5] = new Piece[8] {Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()};
	pieces[6] = new Piece[8] {Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE)};
	pieces[7] = new Piece[8] {Rook(WHITE), Knight(WHITE), Bishop(WHITE), Queen(WHITE), King(WHITE), Bishop(WHITE), Knight(WHITE), Rook(WHITE)};
}


//Destructor
ChessBoard::~ChessBoard() {
	for(int i = 0; i <= 7; i++) {
		delete[] pieces[i];
	}
	delete[] pieces;
}

//Functions
//Display the chess board on the screen
void ChessBoard::display() {
	//Standard terminal is 80x25; clear screen
	for(int i = 0; i <= 25; i++) {
		printf("\n");
	}

	printf(" ╔═════════════════════════════════╗ \n");
	printf(" ║┌───┬───┬───┬───┬───┬───┬───┬───┐║ \n");

	for(int i = 7; i >= 0; i--) {
		printf("%d║│", i);
		for(int j = 0; j < 8; j++) {
			printf(" %s │", pieces[i][j].getDisplayChar());
		}
		printf("║ \n");
		if(i > 0) {
			printf(" ║├───┼───┼───┼───┼───┼───┼───┼───┤║ \n");
		}
	}

	printf(" ║└───┴───┴───┴───┴───┴───┴───┴───┘║ \n");
	printf(" ╚═════════════════════════════════╝ \n");
	printf("    A   B   C   D   E   F   G   H    \n");
	printf("\n");
}

Piece ChessBoard::getPiece(int row, int col) {
	//FIXME: Segfaults if out of range
	//if(row < 0 || row > 7 || col < 0 || col > 7) {
	//	return NULL;
	//} else {
		return pieces[row][col];
	//}
}

//Determine if the game is over
side_t ChessBoard::getWinner() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(pieces[i][j].checkmate(*this, i, j)) {
				return pieces[i][j].getSide();
			}
		}
	}
	return NEITHER;
}

//Move a piece
bool ChessBoard::move(side_t side, int fromRow, int fromCol, int toRow, int toCol) {
	if(pieces[fromRow][fromCol].getSide() != side || !pieces[fromRow][fromCol].checkMove(*this, fromRow, fromCol, toRow, toCol)) {
		printf("Error; invalid move!\n");
		return false;
	} else {
		pieces[fromRow][fromCol].move(*this, fromRow, fromCol, toRow, toCol);
	}
	return true;
}

//Swap two pieces
void ChessBoard::swap(int fromRow, int fromCol, int toRow, int toCol) {
	Piece temp = pieces[toRow][toCol];
	pieces[toRow][toCol] = pieces[fromRow][fromCol];
	pieces[fromRow][fromCol] = temp;
}

//Determine if a square is threatened by another piece (i.e. it could move there next turn)
side_t ChessBoard::isThreatened(int row, int col) {
	side_t threatenedSide = NEITHER;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(pieces[i][j].checkMove(*this, i, j, row, col)) {	//TODO: Assume square is threatened?
				if(threatenedSide == NEITHER) {
					threatenedSide = pieces[i][j].getSide();
				} else if(threatenedSide != pieces[i][j].getSide()) {
					return BOTH;
				}
			}
		}
	}
	return threatenedSide;
}
