#include <stdlib.h>
#include "Move.h"


MOVE *CreateMove(int r1, int f1, int r2, int f2){
	MOVE *move = malloc(sizeof(MOVE));
	move->r1 = r1;
	move->f1 = f1;
	move->r2 = r2;
	move->f2 = f2;

	return move;
}



void DeleteMove(MOVE *move){
	free(move);
}



void Move(Game *game, MOVE *move){


}



MOVE *GetUserMove(Game *game){

	return CreateMove(1, 1, 1, 1);
}




MOVE *GetAIMove(Game *game){

	return CreateMove(1, 1, 1, 1);
}
