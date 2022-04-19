#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Game.h"
#include "Board.h"
#include "UI.h"

Game *CreateGame(){
	Game *game = malloc(sizeof(Game));
	assert(game);


	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			game->board[i][j] = NULL;
		}
	}

	
	game->board[7][0] = CreatePiece(BLACK, ROOK);
	game->board[7][1] = CreatePiece(BLACK, KNIGHT);
	game->board[7][2] = CreatePiece(BLACK, BISHOP);
	game->board[7][3] = CreatePiece(BLACK, QUEEN);
	game->board[7][4] = CreatePiece(BLACK, KING);
	game->board[7][5] = CreatePiece(BLACK, BISHOP);
	game->board[7][6] = CreatePiece(BLACK, KNIGHT);
	game->board[7][7] = CreatePiece(BLACK, ROOK);

	game->board[6][0] = CreatePiece(BLACK, PAWN);
	game->board[6][1] = CreatePiece(BLACK, PAWN);
	game->board[6][2] = CreatePiece(BLACK, PAWN);
	game->board[6][3] = CreatePiece(BLACK, PAWN);
	game->board[6][4] = CreatePiece(BLACK, PAWN);
	game->board[6][5] = CreatePiece(BLACK, PAWN);
	game->board[6][6] = CreatePiece(BLACK, PAWN);
	game->board[6][7] = CreatePiece(BLACK, PAWN);


	game->board[0][0] = CreatePiece(WHITE, ROOK);
	game->board[0][1] = CreatePiece(WHITE, KNIGHT);
	game->board[0][2] = CreatePiece(WHITE, BISHOP);
	game->board[0][3] = CreatePiece(WHITE, QUEEN);
	game->board[0][4] = CreatePiece(WHITE, KING);
	game->board[0][5] = CreatePiece(WHITE, BISHOP);
	game->board[0][6] = CreatePiece(WHITE, KNIGHT);
	game->board[0][7] = CreatePiece(WHITE, ROOK);

	game->board[1][0] = CreatePiece(WHITE, PAWN);
	game->board[1][1] = CreatePiece(WHITE, PAWN);
	game->board[1][2] = CreatePiece(WHITE, PAWN);
	game->board[1][3] = CreatePiece(WHITE, PAWN);
	game->board[1][4] = CreatePiece(WHITE, PAWN);
	game->board[1][5] = CreatePiece(WHITE, PAWN);
	game->board[1][6] = CreatePiece(WHITE, PAWN);
	game->board[1][7] = CreatePiece(WHITE, PAWN);

	return game;
}


void DeleteGame(Game *game){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			DeletePiece(game->board[i][j]);
		}
	}
	
	free(game);
}

void GameLoop(int option){
	Game *game = CreateGame();
	if (option == 1){
		int userSelection = 0;
		
		while (userSelection != 1 && userSelection != 2){
			printf("What color do you want to be?\n\n");
			printf("1 - White\n");
			printf("2 - Black\n\n");
			printf("Enter color here (1-2): ");
			scanf("%d", &userSelection);
		}
		
		if (userSelection == 1){
			game->PLAYERW = HUMAN;
			game->PLAYERB = COMPUTER;
		}
		else {
			game->PLAYERB = HUMAN;
			game->PLAYERW = COMPUTER;
		}	
	}
	else {
		game->PLAYERW = COMPUTER;
		game->PLAYERB = COMPUTER;
	}
}

