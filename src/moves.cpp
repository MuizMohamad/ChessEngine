
#include "moves.hpp"

Move::Move(U64 movebits){
    moves = movebits;
}

int Move::fromSq(){
    return (moves & 0x7F);
}
int Move::toSq(){
    return (moves >> 7) & 0x7F;
}

int Move::captured(){
    return (moves >> 14) & 0xF;
}

int Move::promoted(){
    return (moves >> 20) & 0xF;
}

int Move::enPassant(){
    return moves & 0x40000;
}

int Move::pawnStart(){
    return moves & 0x80000;
}

int Move::castle(){
    return moves & 0x1000000;
}

static U64 createMove(int fromSq,int toSq,int captured,int enPassant,int pawnStart,int promoted,int castle){
    return ( (fromSq) | (toSq << 7) | ( captured << 14) | (enPassant << 18) | (pawnStart << 19) | (promoted << 20) | (castle << 24));
}

static std::vector<Move> generatePawnMoves(int pawnSquare,Board b){

    std::vector<Move> allmoves = {};

    if (b.turn == WHITE){

        for (int i = 1 ; i <= 64 ; i++){
            if (b.pieceListInSq64[wP][i] == 1){

            }
        }
    }
}