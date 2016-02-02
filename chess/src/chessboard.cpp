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
								{new Rook(WHITE), new Knight(WHITE), new Bishop(WHITE), new Queen(WHITE), new King(WHITE), new Bishop(WHITE), new Knight(WHITE), new Rook(WHITE)},
								{new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE), new Pawn(WHITE)},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece(), new Piece()},
								{new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK), new Pawn(BLACK)},
								{new Rook(BLACK), new Knight(BLACK), new Bishop(BLACK), new Queen(BLACK), new King(BLACK), new Bishop(BLACK), new Knight(BLACK), new Rook(BLACK)}
							},
							logFile(NULL) {

	logFile = fopen("chess.log",  "w");
	if(logFile == NULL) {
		printf("Failed to open log file! No log file will be used for this game.\n");
	}
}

//Destructor
ChessBoard::~ChessBoard() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			delete pieces[i][j];
		}
	}

	if(logFile != NULL) {
		fclose(logFile);
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
		printf("%d║│", i + 1);
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
				//Return the side causing the checkmate, not the losing side
				if(pieces[i][j]->getSide() == WHITE) {
					return BLACK;
				} else {
					return WHITE;
				}
			}
		}
	}
	return NEITHER;
}

//Check if a move is possible
bool ChessBoard::checkMove(side_t side, int fromRow, int fromCol, int toRow, int toCol, bool displayErrors /* = false */) {
	//Bounds checking
	if(fromRow < 0 || fromRow > 7 || fromCol < 0 || fromCol > 7 || toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7) {
		if(displayErrors) {
			printf("Error; move is out of bounds!\n");
		}
		return false;
	}

	//No moving in place
	if(fromRow == toRow && fromCol == toCol) {
		if(displayErrors) {
			printf("Error; no move made!\n");
		}
		return false;
	}

	//No moving on top of your own pieces
	if(!pieces[toRow][toCol]->getCaptured() && pieces[fromRow][fromCol]->getSide() == pieces[toRow][toCol]->getSide()) {
		if(displayErrors) {
			printf("Error; capturing your own pieces is not allowed!");
		}
		return false;
	}

	//No moving the opponent's pieces
	if(pieces[fromRow][fromCol]->getSide() != side) {
		if(displayErrors) {
			printf("Error; you do not control that piece!\n");
		}
		return false;
	}

	//Make sure the piece exists
	if(pieces[fromRow][fromCol]->getCaptured()) {
		if(displayErrors) {
			printf("Error; piece does not exist!\n");
		}
		return false;
	}

	//Move validation
	if(!pieces[fromRow][fromCol]->checkMove(*this, fromRow, fromCol, toRow, toCol)) {
		if(displayErrors) {
			printf("Error; invalid move!\n");
		}
		return false;
	}

	//All tests have passed
	return true;
}

//Move a piece
bool ChessBoard::move(side_t side, int fromRow, int fromCol, int toRow, int toCol) {
	//Move validation
	if(!checkMove(side, fromRow, fromCol, toRow, toCol, true)) {
		//Invalid move
		return false;
	} else {
		//Move the piece
		if(!pieces[fromRow][fromCol]->move(*this, fromRow, fromCol, toRow, toCol)) {
			printf("Error moving piece!\n");
			return false;
		}

		//FIXME: Preliminary log
		printf("%c%d %c%d\n", fromCol + 'a', fromRow + 1, toCol + 'a', toRow + 1);
		if(logFile != NULL) {
			fprintf(logFile, "%c%d %c%d\n", fromCol + 'a', fromRow + 1, toCol + 'a', toRow + 1);
			fflush(logFile);
		}
	}
	return true;
}

//Swap two pieces
void ChessBoard::swap(int fromRow, int fromCol, int toRow, int toCol) {
	Piece *temp = pieces[toRow][toCol];
	pieces[toRow][toCol] = pieces[fromRow][fromCol];
	pieces[fromRow][fromCol] = temp;
}

//Pawn promotion
void ChessBoard::promote(side_t side, int row, int col) {
	if(pieces[row][col]->getType() != PAWN) {
		printf("Error; only pawns can be promoted!\n");
		return;
	}

	//Determine what piece to promote to
	char promoteType = 'q';
	printf("Promote pawn to:\n");
	printf("q - Queen\n");
	printf("r - Rook\n");
	printf("k - Knight\n");
	printf("b - Bishop\n");
	printf("Enter choice: \n");
	scanf(" %c", &promoteType);

	//Promote the pawn
	switch(promoteType) {
		case 'q':
			delete pieces[row][col];
			pieces[row][col] = new Queen(side);
			break;
		case 'r':
			delete pieces[row][col];
			pieces[row][col] = new Rook(side);
			break;
		case 'k':
			delete pieces[row][col];
			pieces[row][col] = new Knight(side);
			break;
		case 'b':
			delete pieces[row][col];
			pieces[row][col] = new Bishop(side);
			break;
		default:
			printf("Invalid selection! Defaulted to queen.\n");
			delete pieces[row][col];
			pieces[row][col] = new Queen(side);
			break;
	}
}

//Determine if a square is threatened by another piece (i.e. it could move there next turn)
side_t ChessBoard::isThreatened(int row, int col) {
	side_t threatenedSide = NEITHER;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			//Check white pieces
			if(checkMove(WHITE, i, j, row, col)) {
				if(threatenedSide == NEITHER) {
					threatenedSide = WHITE;
				} else if(threatenedSide != pieces[i][j]->getSide()) {
					return BOTH;
				}
			}
			//Check black pieces
			if(checkMove(BLACK, i, j, row, col)) {
				if(threatenedSide == NEITHER) {
					threatenedSide = BLACK;
				} else if(threatenedSide != pieces[i][j]->getSide()) {
					return BOTH;
				}
			}
		}
	}
	return threatenedSide;
}

//Store a list of all possible moves in a 4D array
void ChessBoard::availableMoves(int moves[8][8][8][8], side_t side) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			for(int k = 0; k < 8; k++) {
				for(int l = 0; l < 8; l++) {
					moves[i][j][k][l] = checkMove(side, i, j, k, l) ? 1 : 0;
					printf("%d", moves[i][j][k][l]);
				}
			}
		}
	}
}
