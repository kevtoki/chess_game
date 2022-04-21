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

	if (isObstructed(game, move)){
		return 0;
	}

	ChessPiece *piece = game->board[move->r1][move->f1];
	PieceType pType = piece->p_type;
	Color pColor = piece->color;

	if (pType == PAWN){
		if (pColor == WHITE){
			// move forward one square case
			if ((f2 - f1 == 1) && (r2 - r1 == 0)&& game->board[move->r2][move->f2] == NULL){
				return 1;
			}
			
			// take diagonal case	
			if (abs(r2 - r1) == 1 && f2 - f1 == 1 && game->board[move->r2][move->f2] != NULL){
				return 1;

			}

			// move forward two squares on the first move case
			if ((f2 - f1 == 2) && (r2 - r1 == 0) && game->board[move->r2][move->f2] == NULL && piece->numberOfMoves == 0){
				return 1;
			}

			return 0;
		}
		else {
			// move forward one square case
			if ((f2 - f1 == -1) && (r2 - r1 == 0)&& game->board[move->r2][move->f2] == NULL){
				return 1;
			}
			
			// take diagonal case	
			if (abs(r2 - r1) == 1 && f2 - f1 == -1 && game->board[move->r2][move->f2] != NULL){
				return 1;

			}

			// move forward two squares on the first move case
			if ((f2 - f1 == -2) && (r2 - r1 == 0) && game->board[move->r2][move->f2] == NULL && piece->numberOfMoves == 0){
				return 1;
			}

			return 0;

		}	
	}
	else if (pType == ROOK){
		if ((abs(r1 - r2) > 0 && abs(f1 - f2) == 0 )){
			return 1;
		}

		if ((abs(r1 - r2) == 0 && abs(f1 - f2) > 0)){
			return 1;
		}

		return 0;
	}
	else if (pType == KNIGHT){
		if ((abs(r1 - r2) == 1 && abs(f1 - f2) == 2)){
			return 1;
		}
		if ((abs(r1 - r2) == 2 && abs(f1 - f2) == 1)){
			return 1;
		}

		return 0;
	}
	else if (pType == BISHOP){
		if ((abs(r1 - r2) == abs(f1 - f2))){
			return 1;
		}
		
		return 0;
	}
	else if (pType == QUEEN){
		if ((abs(r1 - r2) > 0 && abs(f1 - f2) == 0 )){
			return 1;
		}

		if ((abs(r1 - r2) == 0 && abs(f1 - f2) > 0)){
			return 1;
		}

		if ((abs(r1 - r2) == abs(f1 - f2))){
			return 1;
		}
		
		return 0;
	}
	else if (pType == KING){
		if (abs(r1 - r2) <= 1 && abs(f1 - f2) <= 1){
			return 1;
		}
		return 0;
	}

	return 0;

}

int exposesKing(Game *game, MOVE *move){
	return 0;
}

int isObstructed(Game *game, MOVE *move){
	ChessPiece *piece = game->board[move->r1][move->f1];

	int r1 = move->r1;
	int f1 = move->f1;
	int r2 = move->r2;
	int f2 = move->f2;


	if (piece->p_type == ROOK){
		if (r1 < r2){
			for (int i = r1 + 1; i < r2; i++){
				if (game->board[i][f1] != NULL){
					return 1;
				}
			}
		}
		else if (r1 > r2){
			for (int i = r2 + 1; i < r1; i++){
				if (game->board[i][f1] != NULL){
					return 1;
				}
			}
			
		}
		else if (f1 < f2){
			for (int i = f1 + 1; i < f2; i++){
				if (game->board[r1][i] != NULL){
					return 1;
				}
			}
			
		}
		else if (f1 > f2){
			for (int i = f2 + 1; i < f1; i++){
				if (game->board[r1][i] != NULL){
					return 1;
				}
			}
			
		}

	}
	else if (piece->p_type == BISHOP){
	
	}
	else if (piece->p_type == QUEEN){

	}

	return 0;

}


void checkPromotions(Game *game){
	Color who = game->whoTurn;
	for (int i = 0; i < 8; i++){
		if (who == WHITE && game->PLAYERW == HUMAN){
			if (game->board[i][7] != NULL && game->board[i][7]->p_type == PAWN){
				printf("A pawn on %c8 is ready for promotion!\n", 'a' + i);
			}
		}
		else if (who == BLACK && game->PLAYERB == HUMAN){
			if (game->board[i][0] != NULL && game->board[i][0]->p_type == PAWN){
				printf("A pawn on %c1 is ready for promotion!\n", 'a' + i);
			}
			
		}
		else if (who == WHITE){
			if (game->board[i][7] != NULL && game->board[i][7]->p_type == PAWN){
				PromotePiece(game->board[i][7], QUEEN);
			}
			
		}
		else if (who == BLACK){
			if (game->board[i][0] != NULL && game->board[i][0]->p_type == PAWN){
				PromotePiece(game->board[i][0], QUEEN);
			}
			
		}
	}
}
