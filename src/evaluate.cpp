
#include "evaluate.hpp"

int evalPosition(Board b){

    int total_score = 0;
    
    // White Pawn
    for (int i = 0; i < b.pieceNum[wP]; i++){
        int sq = b.pieceListInSq64[wP][i];
        assert(checkInsideBoard(sq));
        total_score += PieceSq_Pawn[sq];
    }

    // Black Pawn
    for (int i = 0; i < b.pieceNum[bP]; i++){
        int sq = b.pieceListInSq64[bP][i];
        assert(checkInsideBoard(sq));
        total_score -= PieceSq_Pawn[MirrorSq64[sq]];
    }

    // White Knight
    for (int i = 0; i < b.pieceNum[wN]; i++){
        int sq = b.pieceListInSq64[wN][i];
        assert(checkInsideBoard(sq));
        total_score += PieceSq_Knight[sq];
    }

    // Black Knight
    for (int i = 0; i < b.pieceNum[bN]; i++){
        int sq = b.pieceListInSq64[bN][i];
        assert(checkInsideBoard(sq));
        total_score -= PieceSq_Knight[MirrorSq64[sq]];
    }

    // White Bishop
    for (int i = 0; i < b.pieceNum[wB]; i++){
        int sq = b.pieceListInSq64[wB][i];
        assert(checkInsideBoard(sq));
        total_score += PieceSq_Bishop[sq];
    }

    // Black Bishop
    for (int i = 0; i < b.pieceNum[bB]; i++){
        int sq = b.pieceListInSq64[bB][i];
        assert(checkInsideBoard(sq));
        total_score -= PieceSq_Bishop[MirrorSq64[sq]];
    }

    // White Rook
    for (int i = 0; i < b.pieceNum[wR]; i++){
        int sq = b.pieceListInSq64[wR][i];
        assert(checkInsideBoard(sq));
        total_score += PieceSq_Rook[sq];
    }

    // Black Rook
    for (int i = 0; i < b.pieceNum[bR]; i++){
        int sq = b.pieceListInSq64[bR][i];
        assert(checkInsideBoard(sq));
        total_score -= PieceSq_Rook[MirrorSq64[sq]];
    }

    // White Queen
    for (int i = 0; i < b.pieceNum[wQ]; i++){
        int sq = b.pieceListInSq64[wQ][i];
        assert(checkInsideBoard(sq));
        total_score += PieceSq_Queen[sq];
    }

    // Black Queen
    for (int i = 0; i < b.pieceNum[bQ]; i++){
        int sq = b.pieceListInSq64[bQ][i];
        assert(checkInsideBoard(sq));
        total_score -= PieceSq_Queen[MirrorSq64[sq]];
    }

    if (b.turn == WHITE){
        return total_score;
    }
    else {
        return -total_score;
    }

}