#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Move.h"
#include "Game.h"
#include "Rules.h"
#include "ChessPiece.h"


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
    int currentRank, currentFile, newRank, newFile;
    
    currentRank = move->r1;
    currentFile = move->f1;
    newRank = move->r2;
    newFile = move->f2;

	if (game->board[newRank][newFile] != NULL){
		DeletePiece(game->board[newRank][newFile]);
	}

	game->board[newRank][newFile] = game->board[currentRank][currentFile];
	game->board[currentRank][currentFile] = NULL;

}



MOVE *GetUserMove(Game *game){

    char *currentPos = NULL;
	char *newPos = NULL;
	MOVE *m = CreateMove(0, 0, 0, 0);

	while(!isValidMove(game, m)){
		do{
    		printf("Enter the position of the piece you want to move: ");
			scanf("%s", currentPos);

	    	m->r1 = charToInt(currentPos[0]);
		    m->f1 = (currentPos[1]) - '0' - 1;
    		

			printf("Enter the position of the square you want to move your piece to: ");
			scanf("%s", newPos);

    		m->r2 = charToInt(newPos[0]);
    		m->f2 = (newPos[1]) - '0' - 1;

		} while(m->r1 < 0 || m->r1 > 7 || m->f1 < 0 || m->f1 > 7 || m->r2 < 0 || m->r2 > 7 || m->f2 < 0 || m->f2 > 7);

	}
    return m;
}




MOVE *GetAIMove(Game *game){

	return CreateMove(1, 1, 1, 1);
}

int charToInt(char c)
{
    switch(c)
    {
        case 'A' :
            return 0;
        case 'a' :
            return 0;
        case 'B' :
            return 1;
        case 'b' :
            return 1;
        case 'C' :
            return 2;
        case 'c' :
            return 2;
        case 'D' :
            return 3;
        case 'd' :
            return 3;
        case 'E' :
            return 4;
        case 'e' :
            return 4;
        case 'F' :
            return 5;
        case 'f' :
            return 5;
        case 'G' :
            return 6;
        case 'g' :
            return 6;
        case 'H' :
            return 7;
        case 'h' :
            return 7;
        default :
            return -1;
    }
}
