#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// including local modules
#include "UI.h" // responsible for drawing the game and showing it to the user
#include "Game.h" // responsible for the game loop and game logic
#include "ChessPiece.h" // responsible for the chess piece structs and rules

int main(){
	Game *game = CreateGame();
	PrintBoard(game);
	DeleteGame(game);
}
