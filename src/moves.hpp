
#pragma once

#include "defs.hpp"
#include "board.hpp"
#include "helper.hpp"
#include "validation.hpp"

class Move{

    /*
    Move formatting in one U64

    7 bits for from square
    7 bits for to square
    use hexadecimal with 6 blocks
    0000 0000 0000 0000 0000 0000

    0x hexadecimal prefix
       
    0000 0000 0000 0000 0000 0111 1111 -> From 0x7F (1st to 7th bits)
    0000 0000 0000 0011 1111 1000 0000 -> To >> 7, 0x7F (8th to 14th bits)
    0000 0000 0011 1100 0000 0000 0000 -> Captured >> 14, 0xF (15th to 18th bits)
    0000 0000 0100 0000 0000 0000 0000 -> EnPassant & 0x40000 (19th bits)
    0000 0000 1000 0000 0000 0000 0000 -> Pawn Start & 0x80000 (20th bits)
    0000 1111 0000 0000 0000 0000 0000 -> Promoted Piece >> 20, 0xF (21th to 24th bits)
    0001 0000 0000 0000 0000 0000 0000 -> Castle 0x1000000 (25th bits)
    */

    // store moves
    U64 moves;

    // store score of the move
    U64 score;

    public :

        Move(U64 movebits);
        
        // get something from field
        int fromSq();
        int toSq();
        int captured();
        int enPassant();
        int pawnStart();
        int promoted();
        int castle();
    
        static U64 createMove(int fromSq,int toSq,int enPassant,int castle,int promoted,int captured,int pawnStart);

        static std::vector<Move> generatePawnMoves(int pawnSquare,Board b);
    /*
    generateKnightMoves();
    generateQueenMoves();
    generateBishopMoves();
    generateKingMoves();
    */

};