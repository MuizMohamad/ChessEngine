
#include "hashkeys.hpp"

U64 generatePositionKey(Board b) {

	int sq = 0;
	U64 finalKey = 0;
	int piece = EMPTY;
	
	// pieces
	for(sq = 0; sq < BOARD_SQ_NUM; ++sq) {
		piece = b.pieces[sq];
		if(piece!=NO_SQ && piece!=EMPTY) {
			assert(piece>=wP && piece<=bK);
			finalKey ^= PieceKeys[piece][sq];
		}		
	}
	
	if(b.turn == WHITE) {
		finalKey ^= SideKey;
	}
		
	if(b.enPassantSquare != NO_SQ) {
		assert(b.enPassantSquare>=0 && b.enPassantSquare<BOARD_SQ_NUM);
		finalKey ^= PieceKeys[EMPTY][b.enPassantSquare];
	}
	
	assert(b.castlingKey>=0 && b.castlingKey<=15);
	
	finalKey ^= CastleKeys[b.castlingKey];
	
	return finalKey;
}

U64 un_hash_pieces(Board b,int piece, int sq120){
    return (b.position_key ^= (PieceKeys[piece][sq120]));
}

U64 un_hash_castling_key(Board b){
    return (b.position_key ^= (CastleKeys[(b.castlingKey)]));
}

U64 un_hash_side(Board b){
    return (b.position_key ^= (SideKey));
}
U64 un_hash_en_passant(Board b){
    return (b.position_key ^= (PieceKeys[EMPTY][(b.enPassantSquare)]));
}
