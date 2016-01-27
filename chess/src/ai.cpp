//AI.cpp

//Includes
#include <stdio.h>
#include "chessboard.hpp"
#include "types.hpp"
#include "player.hpp"

//Constructor
AI::AI() {

}

//Destructor
AI::~AI() {

}

//Functions
void AI::getMove(ChessBoard &board, int *fromRow, int *fromCol, int *toRow, int *toCol) {
        int i,j,k,l;
        int kingx,kingy,newx,newy,oldx,oldy;
        bool threat=false,haveit=false,haveit1=false;
        for (i = 0;i<8;i++){
            for (j=0;j<8;j++){
                if ((board.getPiece(i, j)-> getSide() == side) && board.getPiece(i,j)->getType()==KING){
                    oldx=i;
                    oldy=j;
                    haveit=true;
                    break;
                }
            }
            if (haveit){
                break;
            }
        }
        side_t threat = board.isThreatened(oldx,oldy);
        if(threat){
            for (i=0;i<8;i++){
                for (j=0;j<8;j++){
                        if(board.getPiece(oldx,oldy)->checkMove(board,oldx,oldy,i,j)){
                            newx=i;
                            newy=j;
                            haveit1=true;
                            break;
                        }
                }
            if (haveit1){
                break;
                }
            }
            return 1000*oldx+100*oldy+10*newx+newj;
        }
        for (i=0;i<8;i++){
            for (j=0;j<8;j++){
                if (!board.getPiece(i,j)->getCaptured()&& board.getPiece(i, j)-> getSide() == side){
                   for(k=0;k<8;k++){
                        for (l=0;l<8;l++){
                            if(board.getPiece(i,j)->checkMovie(board,i,j,k,l)){
                                oldx=i;
                                oldy=j;
                                newx=k;
                                newy=l;
                                haveit2=true;
                                break;
                            }
                        }
                   if (haveit2){
                    break;
                   }
                   }
                }
            if(haveit2){
                break;
            }
            }
            if(haveit2){
                break;
            }

        }
        return 1000*oldx+100*oldy+10*newx+y;
}
