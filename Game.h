#ifndef GAME_H
#define GAME_H

#include "ChessPiece.h"



typedef struct{
	ChessPiece *board[8][8];
} Game;


Game *CreateGame();

void DeleteGame(Game *game);

char *PrintCoordinate(Game *game, char location[3]);

void GameLoop(int option);

#endif
