#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Game.h"
#include "Board.h"
#include "UI.h"
#include "Rules.h"
#include "Move.h"


Game *CreateGame(){
	Game *game = malloc(sizeof(Game));
	assert(game);


	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			game->board[i][j] = NULL;
		}
	}

	
	game->board[0][7] = CreatePiece(BLACK, ROOK, 0, 7);
	game->board[1][7] = CreatePiece(BLACK, KNIGHT, 1, 7);
	game->board[2][7] = CreatePiece(BLACK, BISHOP, 2, 7);
	game->board[3][7] = CreatePiece(BLACK, QUEEN, 3, 7);
	game->board[4][7] = CreatePiece(BLACK, KING, 4, 7);
	game->board[5][7] = CreatePiece(BLACK, BISHOP, 5, 7);
	game->board[6][7] = CreatePiece(BLACK, KNIGHT, 6, 7);
	game->board[7][7] = CreatePiece(BLACK, ROOK, 7, 7);

	game->board[0][6] = CreatePiece(BLACK, PAWN, 0, 6);
	game->board[1][6] = CreatePiece(BLACK, PAWN, 1, 6);
	game->board[2][6] = CreatePiece(BLACK, PAWN, 2, 6);
	game->board[3][6] = CreatePiece(BLACK, PAWN, 3, 6);
	game->board[4][6] = CreatePiece(BLACK, PAWN, 4, 6);
	game->board[5][6] = CreatePiece(BLACK, PAWN, 5, 6);
	game->board[6][6] = CreatePiece(BLACK, PAWN, 6, 6);
	game->board[7][6] = CreatePiece(BLACK, PAWN, 7, 6);


	game->board[0][0] = CreatePiece(WHITE, ROOK, 0, 0);
	game->board[1][0] = CreatePiece(WHITE, KNIGHT, 1, 0);
	game->board[2][0] = CreatePiece(WHITE, BISHOP, 2, 0);
	game->board[3][0] = CreatePiece(WHITE, QUEEN, 3, 0);
	game->board[4][0] = CreatePiece(WHITE, KING, 4, 0);
	game->board[5][0] = CreatePiece(WHITE, BISHOP, 5, 0);
	game->board[6][0] = CreatePiece(WHITE, KNIGHT, 6, 0);
	game->board[7][0] = CreatePiece(WHITE, ROOK, 7, 0);

	game->board[0][1] = CreatePiece(WHITE, PAWN, 0, 1);
	game->board[1][1] = CreatePiece(WHITE, PAWN, 1, 1);
	game->board[2][1] = CreatePiece(WHITE, PAWN, 2, 1);
	game->board[3][1] = CreatePiece(WHITE, PAWN, 3, 1);
	game->board[4][1] = CreatePiece(WHITE, PAWN, 4, 1);
	game->board[5][1] = CreatePiece(WHITE, PAWN, 5, 1);
	game->board[6][1] = CreatePiece(WHITE, PAWN, 6, 1);
	game->board[7][1] = CreatePiece(WHITE, PAWN, 7, 1);

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
		
		if (game->PLAYERW == HUMAN){
			do{
				PrintBoard(game);
				MOVE *pmove = GetUserMove(game);
				Move(game, pmove);
				DeleteMove(pmove);				

				MOVE *AImove = GetAIMove(game);
				Move(game, AImove);
				DeleteMove(AImove);
			} while (!isCheckmate(game));
			EndGame(game);	
		}
		else{
			do{
				PrintBoardR(game);
			} while(!isCheckmate(game));
			EndGame(game);
		}
	}
	else {
		game->PLAYERW = COMPUTER;
		game->PLAYERB = COMPUTER;
	}
}


// determine the winner and clean up memory
void EndGame(Game *game){
	DeleteGame(game);
}
