#include <stdlib.h>

#include "AI.h"
#include "Game.h"
#include "Rules.h"
#include "Move.h"
#include "ChessPiece.h"


MOVE *GetBestMove(Game *game){
	
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			ChessPiece *piece = game->board[i][j];
			if (piece != NULL && piece->color == game->whoTurn){
				for (int r = 0; r < 8; r++){
					for (int f = 0; f < 8; f++){
						MOVE *move = CreateMove(i, j, r, f);
						if (isLegalMove(game, move) && !exposesKing(game, move)){
							return move;
						}
						DeleteMove(move);
					}
				}
			}
		}
	}

	return NULL;
	
}
