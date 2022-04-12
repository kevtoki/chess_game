#include <stdlib.h>
#include <assert.h>
#include "ChessPiece.h"

ChessPiece *CreatePiece(Color color, PieceType p_type){
	ChessPiece *piece = malloc(sizeof(ChessPiece));
	assert(piece);

	piece->color = color;
	piece->p_type = p_type;

	return piece;
}

void DeletePiece(ChessPiece *piece){
	if (piece){
		free(piece);
	}
}

char *PrintPiece(ChessPiece *piece){
	if (!piece){
		return "  ";
	}

	return "pp";

}
