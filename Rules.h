#ifndef RULES_H
#define RULES_H

#include "Game.h"
#include "Move.h"
#include "ChessPiece.h"

int isCheckmate(Game *game);

int isValidMove(Game *game, MOVE *move);


int exposesKing(Game *game, MOVE *move);

#endif
