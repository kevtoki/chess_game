#include "Rules.h"
#include "ChessPiece.h"

int isCheckmate(Game *game){
	return 0;
}



int isValidMove(Game *game, MOVE *move){
	Color who = game->whoTurn;


	// check if the move is on the board
	if (move->r1 < 0 || move->r1 > 7 || move->f1 < 0 || move->f1 > 7 || move->r2 < 0 || move->r2 > 7 || move->f2 < 0 || move->f2 > 7){
		return 0;
	}

	// check if the user is moving the correct piece or is landing on their own piece
	if (who == game->board[move->r2][move->f2]->color || who != game->board[move->r1][move->f1]->color){
		return 0;
	}


	return 1;

}
