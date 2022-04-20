#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Move.h"
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
    Color color;
    PieceType p_type;
    char name[3];
    
    currentRank = move->r1;
    currentFile = move->f1;
    newRank = move->r2;
    newFile = move->f2;

    color = game->board[currentRank][currentFile]->color;
    p_type = game->board[currentRank][currentFile]->p_type;
    memcpy(name, game->board[currentRank][currentFile]->name, sizeof(name));
 
    game->board[currentRank][currentFile] = NULL;

    game->board[newRank][newFile] = CreatePiece(color, p_type, newRank, newFile);

}



MOVE *GetUserMove(Game *game){

    char currentPOS[2];
    char newPOS[2];
    int currentRank, currentFile, newRank, newFile;

    printf("Enter the position of the piece you want to move: ");
    scanf("%s", currentPOS);
    
    currentRank = charToInt(currentPOS[0]);
    currentFile = (currentPOS[1]) - '0'- 1;

    while (currentRank < 0 || currentRank > 7  
    || currentFile < 0 || currentFile > 7)
    {
        printf("You have selected an invalid piece to move!\n");
        printf("\nRe-enter the position of the piece you want to move: ");
        scanf("%s", currentPOS);
        currentRank = charToInt(currentPOS[0]);
        currentFile = (currentPOS[1]) - '0' - 1;
    }

    while (game->board[currentRank][currentFile] == NULL)
    {
        printf("You have selected an empty space!\n");
        printf("\nRe-enter the position of the piece you want to move: ");
        scanf("%s", currentPOS);
        currentRank = charToInt(currentPOS[0]);
        currentFile = (currentPOS[1]) - '0' - 1;
    }
    
    printf("\nEnter the new position you want your piece to move to: ");
    scanf("%s", newPOS);

    newRank = charToInt(newPOS[0]);
    newFile = (newPOS[1]) - '0' - 1;

    while (newRank < 0 || newRank > 7
    || newFile < 0 || newFile > 7)
    {
        printf("You have selected an invalid place to move to!\n");
        printf("\nRe-enter the position of the place you want to move to: ");
        scanf("%s", newPOS);
        newRank = charToInt(newPOS[0]);
        newFile = (newPOS[1]) - '0' - 1;
    }
    
    while (game->board[newRank][newFile] != NULL)
    {
        printf("You have selected an invalid place to move to!\n");
        printf("\nRe-enter the position of the place you want to move to: ");
        scanf("%s", newPOS);
        newRank = charToInt(newPOS[0]);
        newFile = (newPOS[1]) - '0' - 1;
    }

    MOVE *m = CreateMove(currentRank, currentFile, newRank, newFile);
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
