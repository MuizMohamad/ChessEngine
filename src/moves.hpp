
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
       
    0000 0000 0000 0000 0000 0111 1111 -> From 0x7F (1st to 7th bits) in sq 120 format
    0000 0000 0000 0011 1111 1000 0000 -> To >> 7, 0x7F (8th to 14th bits) in sq 120 format
    0000 0000 0011 1100 0000 0000 0000 -> Captured piece >> 14, 0xF (15th to 18th bits)
    0000 0000 0100 0000 0000 0000 0000 -> EnPassant indicator & 0x40000 (19th bits)
    0000 0000 1000 0000 0000 0000 0000 -> Pawn Start & 0x80000 (20th bits) == if pawn moves two step to the front
    0000 1111 0000 0000 0000 0000 0000 -> to-be-Promoted Piece type >> 20, 0xF (21th to 24th bits)
    0001 0000 0000 0000 0000 0000 0000 -> Castle 0x1000000 (25th bits)
    */

    // store moves
    U64 moves;

    // store score of the move
    U64 score;

    public :

        Move();
        Move(U64 movebits);

        static const std::vector<int> loopPieces ;
        static const std::vector<int> nonLoopPieces ;

        static const std::vector<int> loopPieceIndex;
        static const std::vector<int> nonLoopPieceIndex;

        static const std::vector<std::vector<int>> pceDir;
        static const std::vector<int> numDir;

        // get something from field
        int fromSq(); // in sq120
        int toSq(); // in sq120
        int captured();
        int enPassant();
        int pawnStart();
        int promoted();
        int castle();

        int getMoves();
        
        void print();

        // static functions
        static U64 createMoveBits(int fromSq,int toSq,int captured,int enPassant,int pawnStart,int promoted,int castle);

        static std::vector<Move> generateWhitePawnMove(int pawnSq64,Board b);
        static std::vector<Move> generateBlackPawnMove(int pawnSq64,Board b);
        static std::vector<Move> generatePawnMoves(Board b); // general all pawns

        static std::vector<Move> generateLoopPieceMoves(Board b);
        static std::vector<Move> generateNonLoopPieceMoves(Board b);

        static std::vector<Move> generateCastlingMoves(Board b);

        static std::vector<Move> generateAllMoves(Board b);
  
};