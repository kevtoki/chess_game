#include <stdio.h>
#include "Game.h"
#include "ChessPiece.h"


void PrintBoard(Game *game){
	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("8 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[0][0]),	
		PrintPiece(game->board[0][1]),
		PrintPiece(game->board[0][2]),
		PrintPiece(game->board[0][3]),
		PrintPiece(game->board[0][4]),
		PrintPiece(game->board[0][5]),
		PrintPiece(game->board[0][6]),
		PrintPiece(game->board[0][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("7 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[1][0]),	
		PrintPiece(game->board[1][1]),
		PrintPiece(game->board[1][2]),
		PrintPiece(game->board[1][3]),
		PrintPiece(game->board[1][4]),
		PrintPiece(game->board[1][5]),
		PrintPiece(game->board[1][6]),
		PrintPiece(game->board[1][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("6 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[2][0]),	
		PrintPiece(game->board[2][1]),
		PrintPiece(game->board[2][2]),
		PrintPiece(game->board[2][3]),
		PrintPiece(game->board[2][4]),
		PrintPiece(game->board[2][5]),
		PrintPiece(game->board[2][6]),
		PrintPiece(game->board[2][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("5 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[3][0]),	
		PrintPiece(game->board[3][1]),
		PrintPiece(game->board[3][2]),
		PrintPiece(game->board[3][3]),
		PrintPiece(game->board[3][4]),
		PrintPiece(game->board[3][5]),
		PrintPiece(game->board[3][6]),
		PrintPiece(game->board[3][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("4 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[4][0]),	
		PrintPiece(game->board[4][1]),
		PrintPiece(game->board[4][2]),
		PrintPiece(game->board[4][3]),
		PrintPiece(game->board[4][4]),
		PrintPiece(game->board[4][5]),
		PrintPiece(game->board[4][6]),
		PrintPiece(game->board[4][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("3 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[5][0]),	
		PrintPiece(game->board[5][1]),
		PrintPiece(game->board[5][2]),
		PrintPiece(game->board[5][3]),
		PrintPiece(game->board[5][4]),
		PrintPiece(game->board[5][5]),
		PrintPiece(game->board[5][6]),
		PrintPiece(game->board[5][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("2 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[6][0]),	
		PrintPiece(game->board[6][1]),
		PrintPiece(game->board[6][2]),
		PrintPiece(game->board[6][3]),
		PrintPiece(game->board[6][4]),
		PrintPiece(game->board[6][5]),
		PrintPiece(game->board[6][6]),
		PrintPiece(game->board[6][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("1 | %s | %s | %s | %s | %s | %s | %s | %s |\n", 
		PrintPiece(game->board[7][0]),	
		PrintPiece(game->board[7][1]),
		PrintPiece(game->board[7][2]),
		PrintPiece(game->board[7][3]),
		PrintPiece(game->board[7][4]),
		PrintPiece(game->board[7][5]),
		PrintPiece(game->board[7][6]),
		PrintPiece(game->board[7][7])
		);

	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("    A    B    C    D    E    F    G    H\n");
}
