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
   lastPiece = NULL;
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
	//No moving on top of your own pieces (block overlap)
	if(!pieces[toRow][toCol]->getCaptured() && pieces[fromRow][fromCol]->getSide() == pieces[toRow][toCol]->getSide()) {
		if(displayErrors) {
			printf("Error; capturing your own pieces is not allowed!");
		}
		return false;
	}

	//Call lower-level checkMove
	return checkMoveAllowOverlap(side, fromRow, fromCol, toRow, toCol, displayErrors);
}

//Check if a move is possible, allowing players to capture their own pieces
bool ChessBoard::checkMoveAllowOverlap(side_t side, int fromRow, int fromCol, int toRow, int toCol, bool displayErrors /* = false */) {
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
		//Make sure the king isn't in check
		if(!moveResolvesCheck(side, fromRow, fromCol, toRow, toCol)) {
			printf("Error moving piece; the king cannot be left in check!\n");
			return false;
		}

		//Move the piece
		if(!pieces[fromRow][fromCol]->move(*this, fromRow, fromCol, toRow, toCol)) {
			printf("Error moving piece!\n");
			return false;
		}

  lastPiece = pieces[toRow][toCol];

		printf("%c%d %c%d\n", fromCol + 'a', fromRow + 1, toCol + 'a', toRow + 1);
		if(logFile != NULL) {
            //log player color 
            switch(pieces[fromRow][fromCol]->getSide()){
                case WHITE:
                    fprintf(logFile, "White ");
                    printf("%d", pieces[fromRow][fromCol]->getSide());
                    break;
                case BLACK:
                    fprintf(logFile, "Black ");
                    printf("%d", pieces[fromRow][fromCol]->getSide());
                    break;
                default:
                    printf("%d", pieces[fromRow][fromCol]->getSide());
                    break;
            }
            //log the piece type
            switch(pieces[fromRow][fromCol]->getType()){
                case PAWN:
                    fprintf(logFile, "P ");
                    break;
                case ROOK:
                    fprintf(logFile, "R ");
                    break;
                case KNIGHT:
                    fprintf(logFile, "N ");
                    break;
                case BISHOP:
                    fprintf(logFile, "B ");
                    break;
                case QUEEN:
                    fprintf(logFile, "Q ");
                    break;
                case KING:
                    fprintf(logFile, "K ");
                    break;
                default:
                    printf("%d", pieces[fromRow][fromCol]->getType());
                    break;
            }
            //log positions
            switch(pieces[fromRow][fromCol]->getSide()){
                case WHITE:
                    fprintf(logFile, "%c%d -> %c%d \n", fromCol + 'a', fromRow + 1, toCol + 'a', toRow + 1);
                    if (getWinner() == WHITE){
                      fprintf(logFile, "White is the winner!");
                    }
                    fflush(logFile);
                    break;
                case BLACK:
                    fprintf(logFile, "%c%d -> %c%d \n ", fromCol + 'a', fromRow + 1, toCol + 'a', toRow + 1);
                    if (getWinner() == BLACK){
                      fprintf(logFile, "Black is the winner!");
                    }                    
                    fflush(logFile);
                    break;
                default:
                    printf("%d", pieces[fromRow][fromCol]->getSide());
                    break;
		        }
	}
	return true;
 }
}

//Swap two pieces
void ChessBoard::swap(int fromRow, int fromCol, int toRow, int toCol) {
	Piece *temp = pieces[toRow][toCol];
	pieces[toRow][toCol] = pieces[fromRow][fromCol];
	pieces[fromRow][fromCol] = temp;
}


Piece* ChessBoard::getLast(){
  return lastPiece;
}

//Pawn promotion
void ChessBoard::promote(side_t side, int fromRow, int fromCol, int toRow, int toCol) {
	if(pieces[fromRow][fromCol]->getType() != PAWN) {
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
			delete pieces[toRow][toCol];
			pieces[toRow][toCol] = new Queen(side);
			break;
		case 'r':
			delete pieces[toRow][toCol];
			pieces[toRow][toCol] = new Rook(side);
			break;
		case 'k':
			delete pieces[toRow][toCol];
			pieces[toRow][toCol] = new Knight(side);
			break;
		case 'b':
			delete pieces[toRow][toCol];
			pieces[toRow][toCol] = new Bishop(side);
			break;
		default:
			printf("Invalid selection! Defaulted to queen.\n");
			delete pieces[toRow][toCol];
			pieces[toRow][toCol] = new Queen(side);
			break;
	}
  if(logFile != NULL){
    fprintf(logFile, "Pawn promoted to %c \n", promoteType);
  }
}

//Determine if a square is threatened by another piece (i.e. it could move there next turn)
side_t ChessBoard::isThreatened(int row, int col) {
	side_t threatenedSide = NEITHER;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			//Check white pieces
			if(checkMoveAllowOverlap(WHITE, i, j, row, col)) {
				if(threatenedSide == NEITHER) {
					threatenedSide = WHITE;
				} else if(threatenedSide == BLACK) {
					return BOTH;
				}
			}
			//Check black pieces
			if(checkMoveAllowOverlap(BLACK, i, j, row, col)) {
				if(threatenedSide == NEITHER) {
					threatenedSide = BLACK;
				} else if(threatenedSide == WHITE) {
					return BOTH;
				}
			}
		}
	}
	return threatenedSide;
}

bool ChessBoard::moveResolvesCheck(side_t side, int fromRow, int fromCol, int toRow, int toCol) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			//Find the king
			if(pieces[i][j]->getType() == KING && pieces[i][j]->getSide() == side) {
				//Check if the king is threatened
				side_t threat = isThreatened(i, j);
				if(threat != side && threat != NEITHER) {
					//Test for moving out of check (temporarily move the king to the new location)
					if(i == fromRow && j == fromCol) {
						swap(fromRow, fromCol, toRow, toCol);
						threat = isThreatened(i, j);
						swap(toRow, toCol, fromRow, fromCol);
						if(threat == side || threat == NEITHER) {
							//Move resolves conflict
							return true;
						}
					}

					//Test for capturing the threatening piece
					pieces[toRow][toCol]->setCaptured(true);
					threat = isThreatened(i, j);
					pieces[toRow][toCol]->setCaptured(false);
					if(threat == side || threat == NEITHER) {
						//Move resolves conflict
						return true;
					}

					//Test for blocking the threatening piece (temporarily swap target piece with a knight of the same color)
					Piece *temp = pieces[toRow][toCol];
					pieces[toRow][toCol] = new Knight(side);
					threat = isThreatened(i, j);
					delete pieces[toRow][toCol];
					pieces[toRow][toCol] = temp;
					if(threat == side || threat == NEITHER) {
						//Move resolves conflict
						return true;
					}

					//All tests have failed
					return false;
				}
			}
		}
	}

	//King was not in check, or no king was found
	return true;
}

//Store a list of all pieces and their positions in the provided array
void ChessBoard::listPieces(chess_t list[8][8]) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
					list[i][j] = pieces[i][j]->getType();
		}
	}
}

/*void copyboard(ChessBoard &bdto,ChessBoard &bdorigin){
    int i,j;//needs to be done,someone help
    for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			bdto.Pieces[i][j]=bdorigin.getPiece(i,j);
		}
    }
}
*/




