#include <stdlib.h>
#include <stdio.h>
#include "Rules.h"
#include "ChessPiece.h"

int isCheckmate(Game *game){
	return 0;
}



int isValidMove(Game *game, MOVE *move){
	Color who = game->whoTurn;
	int r1, r2, f1, f2;
	r1 = move->r1;
	f1 = move->f1;
	r2 = move->r2;
	f2 = move->f2;


	// check if the move is on the board
	if (move->r1 < 0 || move->r1 > 7 || move->f1 < 0 || move->f1 > 7 || move->r2 < 0 || move->r2 > 7 || move->f2 < 0 || move->f2 > 7){
		return 0;
	}

	// check if the move is onto the same square it's coming from
	if (move->r1 == move->r2 && move->f1 == move->f2){
		return 0;
	}

	if (game->board[move->r1][move->f1] == NULL || who != game->board[move->r1][move->f1]->color){
		return 0;
	}	

	// check if the user is moving the correct piece or is landing on their own piece
	if (game->board[move->r2][move->f2] != NULL && who == game->board[move->r2][move->f2]->color){
		return 0;
	}

	if (exposesKing(game, move)){
		return 0;
	}

	PieceType pType = game->board[move->r1][move->f1]->p_type;

	if (pType == PAWN){
		
	}
	else if (pType == ROOK){

	}
	else if (pType == ROOK){

	}
	else if (pType == KNIGHT){
		if (!((abs(r1 - r2) == 1 && abs(f1 - f2) == 2) || (abs(r1 - r2) == 2 && abs(f1 - f2) == 1))){
			return 0;
		}
	}
	else if (pType == BISHOP){

	}
	else if (pType == QUEEN){

	}
	else if (pType == KING){

	}

	return 1;

}

int exposesKing(Game *game, MOVE *move){
	return 0;
}
