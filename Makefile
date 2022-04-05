# Default target
.DEFAULT_GOAL := r_chess


##################### Generate object files ##################### 
# Target for r_chess.o
r_chess.o: r_chess.c
	gcc -c r_chess.c -o r_chess.o -Wall -std=c11

# Target for UI.o
UI.o: UI.c
	gcc -c UI.c -o UI.o  -Wall -std=c11


##################### Generate the executable ###################
# Target for r_chess
r_chess: r_chess.o UI.o
	gcc r_chess.o UI.o -o r_chess -Wall -std=c11


##################### Otehr functions ###########################
# Target for clean-up
clean:
	rm r_chess.o
	rm UI.o
	rm r_chess
