# Default target
.DEFAULT_GOAL := r_chess


##################### Generate object files ##################### 
# Target for r_chess.o
r_chess.o: r_chess.c
	gcc -c r_chess.c -o r_chess.o -Wall -std=c11

# Target for UI.o
UI.o: UI.c
	gcc -c UI.c -o UI.o -Wall -std=c11

# Target for ChessPiece.o
ChessPiece.o: ChessPiece.c
	gcc -c ChessPiece.c -o ChessPiece.o -Wall -std=c11

# Target for Game.o
Game.o: Game.c
	gcc -c Game.c -o Game.o -Wall -std=c11

# Target for Rules.o
Rules.o: Rules.c
	gcc -c Rules.c -o Rules.o -Wall -std=c11

# Target for Move.o
Move.o: Move.c
	gcc -c Move.c -o Move.o -Wall -std=c11


##################### Generate the executable ###################
# Target for r_chess
r_chess: r_chess.o UI.o ChessPiece.o Game.o Rules.o Move.o
	gcc r_chess.o UI.o ChessPiece.o Game.o Rules.o Move.o -o r_chess -Wall -std=c11


##################### Otehr functions ###########################
# Target for clean-up
clean:
	rm r_chess.o
	rm UI.o
	rm ChessPiece.o
	rm Game.o
	rm r_chess
