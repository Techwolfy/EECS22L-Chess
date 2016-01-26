//ChessBoard.cpp

//Includes
#include <stdio.h>
#include "chessboard.hpp"
#include "piece.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "pawn.hpp"

//Constructor
ChessBoard::ChessBoard() : pieces{
								{new Rook(BLACK), new Knight(BLACK), new Bishop(BLACK), new King(BLACK), new Queen(BLACK), new Bishop(BLACK), new Knight(BLACK), new Rook(BLACK)},
								{new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK)},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE)},
								{new Rook(WHITE), new Knight(WHITE), new Bishop(WHITE), new Queen(WHITE), new King(WHITE), new Bishop(WHITE), new Knight(WHITE), new Rook(WHITE)}
							} {

}


//Destructor
ChessBoard::~ChessBoard() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; i++) {
			delete pieces[i][j];
		}
	}
}

//Functions
//Display the chess board on the screen
void ChessBoard::display() {
	//Standard terminal is 80x25; clear screen
	//for(int i = 0; i <= 25; i++) {
		printf("\n");
	//}

	printf(" ╔═════════════════════════════════╗ \n");
	printf(" ║┌───┬───┬───┬───┬───┬───┬───┬───┐║ \n");

	for(int i = 7; i >= 0; i--) {
		printf("%d║│", i);
		for(int j = 0; j < 8; j++) {
			printf(" %s │", pieces[i][j]->getDisplayChar());
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

Piece* ChessBoard::getPiece(int row, int col) {
	if(row < 0 || row > 7 || col < 0 || col > 7) {
		return NULL;
	} else {
		return pieces[row][col];
	}
}

//Determine if the game is over
side_t ChessBoard::getWinner() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(pieces[i][j]->checkmate(*this, i, j)) {
				return pieces[i][j]->getSide();
			}
		}
	}
	return NEITHER;
}

//Move a piece
bool ChessBoard::move(side_t side, int fromRow, int fromCol, int toRow, int toCol) {
	//Bounds checking
	if(fromRow < 0 || fromRow > 7 || fromCol < 0 || fromCol > 7 || toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7) {
		printf("Error; move is out of bounds!\n");
		return false;
	}

	//No moving in place
	if(fromRow == fromCol && toRow == toCol) {
		printf("Error: no move made!\n");
		return false;
	}

	//Move validation
	if(pieces[fromRow][fromCol]->getSide() != side || pieces[fromRow][fromCol]->getCaptured() || !pieces[fromRow][fromCol]->checkMove(*this, fromRow, fromCol, toRow, toCol)) {
		printf("Error; invalid move!\n");
		return false;
	} else {
		//Move the piece
		pieces[fromRow][fromCol]->move(*this, fromRow, fromCol, toRow, toCol);
	}
	return true;
}

//Swap two pieces
void ChessBoard::swap(int fromRow, int fromCol, int toRow, int toCol) {
	Piece *temp = pieces[toRow][toCol];
	pieces[toRow][toCol] = pieces[fromRow][fromCol];
	pieces[fromRow][fromCol] = temp;
}

//Determine if a square is threatened by another piece (i.e. it could move there next turn)
side_t ChessBoard::isThreatened(int row, int col) {
	side_t threatenedSide = NEITHER;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(pieces[i][j]->checkMove(*this, i, j, row, col)) {	//TODO: Assume square is threatened?
				if(threatenedSide == NEITHER) {
					threatenedSide = pieces[i][j]->getSide();
				} else if(threatenedSide != pieces[i][j]->getSide()) {
					return BOTH;
				}
			}
		}
	}
	return threatenedSide;
}
