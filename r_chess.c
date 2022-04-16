#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// including local modules
#include "UI.h" // responsible for drawing the game and showing it to the user
#include "Game.h" // responsible for the game loop and game logic
#include "ChessPiece.h" // responsible for the chess piece structs and rules

int main()
{
	int loop = 1;
	while(loop)
	{
	printf("Please choose from the following(Enter a number):\n");
	printf("1. Player vs. Computer\n");
	printf("2. Computer vs. Computer\n");
	printf("3. Exit\n");
	printf("4. Uninstall\n");
	int choice = 0; 
	scanf("%d", &choice);	

		switch(choice)
		{
			case 1:
				printf("You have chosen \'Player vs. Computer\'.\n");
				Game *game = CreateGame();
				int loop1 = 1;
				char *piece;
				char *destination;
				char *color;
				printf("Choose a side you want to play(black or white)\n");
				scanf("%s", &color); 
				PLAYER *newPlayer(color);
				// --funtion for dealing with sides//
				if (strcmp(color, "white") == 0)
				{
				}
				while(loop1)
				{
	       	 			PrintBoard(game);
					printf("Please enter the piece you want to move(e.g. queen): \n");
					scanf("%s", &piece);	
					printf("Please Enter Your Move(e.g. c4):\n");
					scanf("%s", &destination);
					//moveConversionFunction(piece, destination); outputting move//
					isValid(move, board);
					board = Move(move, game);
					PrintBoard(game);
					
					
					
						
				}
				break;
			case 2:
				printf("You have chosen \'Computer vs. Computer\'.\n");
				Game *game2 = CreateGame();
	      	                PrintBoard(game2);
				break;
			case 3:
				printf("You have chosen to exit the game.\n");
				loop = 0;
				break;
			case 4:
				printf("You have chosen uninstall the game.\n");
				loop = 0;
				break;
			default:
				printf("Your choice is invalid. Please enter again.\n");
		}
	}
	printf("Goodbye!");
	return 0;
}
