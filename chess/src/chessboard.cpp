//ChessBoard.cpp

//Includes
#include <stdio.h>
#include "chessboard.hpp"
#include "piece.hpp"

//Constructor
ChessBoard::ChessBoard() : pieces{
							{Rook(BLACK), Knight(BLACK), Bishop(BLACK), King(BLACK), Queen(BLACK), Bishop(BLACK), Knight(BLACK), Rook(BLACK)},
							{Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK)},
							{Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()},
							{Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()},
							{Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()},
							{Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece(), Piece()},
							{Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE)},
							{Rook(WHITE), Knight(WHITE), Bishop(WHITE), Queen(WHITE), King(WHITE), Bishop(WHITE), Knight(WHITE), Rook(WHITE)}
						   }
{

}


//Destructor
ChessBoard::~ChessBoard() {

}

//Functions
//Display the chess board on the screen
void ChessBoard::display() {
	//Standard terminal is 80x25; clear screen
	for(int i = 0; i <= 25; i++) {
		printf("\n");
	}

	printf(" ╔═════════════════╗ \n");
	printf(" ║┌─┬─┬─┬─┬─┬─┬─┬─┐║ \n");

	for(int i = 7; i >= 0; i--) {
		printf("%d║│", i);
		for(int j = 0; j < 8; j++) {
			printf("%c│", pieces[i][j].getDisplayChar());
		}
		printf("║ \n");
		printf(" ║├─┼─┼─┼─┼─┼─┼─┼─┤║ \n");
	}

	printf(" ║└─┴─┴─┴─┴─┴─┴─┴─┘║ \n");
	printf(" ╚═════════════════╝ \n");
	printf("   A B C D E F G H   \n");
	printf("\n");
}

//Determine if the game is over
side_t ChessBoard::getWinner() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(pieces[i][j].checkmate()) {
				return pieces[i][j].getSide();
			}
		}
	}
	return NONE;
}

//Move a piece
bool ChessBoard::move(int fromRow, int fromCol, int toRow, int toCol) {
	if(!pieces[fromRow][fromCol].checkMove(pieces, fromRow, fromCol, toRow, toCol, isThreatened(toRow, toCol))) {
		printf("Error; invalid move!\n");
		return false;
	} else {
		pieces[fromRow][fromCol].move(pieces, fromRow, fromCol, toRow, toCol);
	}
	return true;
}

//Swap two pieces
void ChessBoard::swap(int fromRow, int fromCol, int toRow, int toCol) {
	Piece temp = &pieces[toRow][toCol];
	pieces[toRow][toCol] = pieces[fromRow][fromCol];
	pieces[fromRow][fromCol] = temp;
}

//Determine if a square is threatened by another piece (i.e. it could move there next turn)
side_t ChessBoard::isThreatened(int row, int col) {
	side_t threatenedSide = Piece::NEITHER;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(pieces[i][j].checkMove(pieces, i, j, row, col, true)) {
				if(threatenedSide == Piece::NEITHER) {
					threatenedSide = pieces[i][j].getSide();
				} else if(threatenedSide != pieces[i][j].getSide()) {
					return Pieces::BOTH;
				}
			}
		}
	}
	return threatenedSide;
}
