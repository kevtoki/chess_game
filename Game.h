#ifndef GAME_H
#define GAME_H

#include "ChessPiece.h"

typedef enum {HUMAN = 0, COMPUTER = 1} PLAYER_TYPE;

typedef struct{
	ChessPiece *board[8][8];
	PLAYER_TYPE PLAYERW;
	PLAYER_TYPE PLAYERB;
} Game;


Game *CreateGame();

void DeleteGame(Game *game);

char *PrintCoordinate(Game *game, char location[3]);

void GameLoop(int option);


void EndGame(Game *game);

#endif
