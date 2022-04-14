#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ChessPiece.h"

ChessPiece *CreatePiece(Color color, PieceType p_type){
	ChessPiece *piece = malloc(sizeof(ChessPiece));
	assert(piece);

	piece->color = color;
	piece->p_type = p_type;

	piece->name[3] = '\0';

	if (color == WHITE){
		piece->name[0] = 'w';
	}
	else{
		piece->name[0] = 'b';
	}


	if (p_type == PAWN){
		piece->name[1] = 'P';
	}
	else if (p_type == ROOK){
		piece->name[1] = 'R';
	}
	else if (p_type == KNIGHT){
		piece->name[1] = 'N';
	}
	else if (p_type == BISHOP){
		piece->name[1] = 'B';
	}
	else if (p_type == QUEEN){
		piece->name[1] = 'Q';
	}
	else if (p_type == KING){
		piece->name[1] = 'K';
	}
	

	return piece;
}

void DeletePiece(ChessPiece *piece){
	if (piece){
		free(piece);
	}
}

