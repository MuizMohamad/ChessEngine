
#pragma once

#include "defs.hpp"

class Moves{

    /*
    
    Move formatting in one U64

    7 bits for from square
    7 bits for to square
    use hexadecimal with 6 blocks
    0000 0000 0000 0000 0000 0000

    0x hexadecimal prefix
       
    0000 0000 0000 0000 0000 0111 1111 -> From 0x3F (1st to 7th bits)
    0000 0000 0000 0011 1111 1000 0000 -> To >> 7, 0x3F (8th to 14th bits)
    0000 0000 0011 1100 0000 0000 0000 -> Captured >> 14, 0xF (15th to 18th bits)
    0000 0000 0100 0000 0000 0000 0000 -> EnPassant & 0x40000 (19th bits)
    0000 0000 1000 0000 0000 0000 0000 -> Pawn Start & 0x80000 (20th bits)
    0000 1111 0000 0000 0000 0000 0000 -> Promoted Piece >> 20, 0xF (21th to 24th bits)
    0001 0000 0000 0000 0000 0000 0000 -> Castle 0x1000000 (25th bits)
    */

    // store moves
    U64 moves;

    public :
        Moves(U64 movebits);

        int fromSq();
        int toSq();
        int enPassant();
        int castle();
        int promoted();
        int captured();

    /*
    std::vector<int> generatePawnMoves(int pawnSquare);
    generateKnightMoves();
    generateQueenMoves();
    generateBishopMoves();
    generateKingMoves();
    */

};