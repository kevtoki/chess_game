#include <stdio.h>
#include "Game.h"
#include "ChessPiece.h"


void PrintBoard(Game *game){



	for (int i = 8; i > 0; i--){
		printf("  +----+----+----+----+----+----+----+----+\n");

		printf("%d |", i);
		for (int j = 0; j <= 7; j++){
			char *name = "  ";
			if (game->board[i - 1][j] != NULL){
				name = game->board[i - 1][j]->name;
			}
			printf(" %s |", name);
		}
		printf("\n");
	}






	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("    A    B    C    D    E    F    G    H\n");
}
