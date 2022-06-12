
#pragma once

#include "defs.hpp"
#include "helper.hpp"
#include "validation.hpp"
#include "hashkeys.hpp"

// class Board or in another words chess 'position'
class Board{


    public:
        // Put each piece location in square based on enum
        // extra 65 for square 1-64

        // by default we calculate using 12x10 board representation (start with index 0 - 119)
        int pieceList[13][10];
        int pieces[120];
    
        int pieceListInSq64[13][10];
        int piecesInSq64[65];

        int pieceNum[13];

        U64 enPassantSquare; // en Passant square (sq 120)
        U64 turn; // 0 for white , 1 for black

        // castling permission
        // 0000 : 4th bit - black can castle queen, 3rd bit - black can castle king, 2nd -, white castle queen , 1st - white castle king
        U64 castlingKey; 

        // current number of moves, eg after 1 c4 , current total move is 1
        int fullMove;

        // number of completed moves since last pawn capture
        int halfMove;

        U64 position_key;

    public:

        Board();
        void empty_board();
        void print_board();
        void init_pieces();
        int getPieceAtSq64(int square);
        void parseFEN(std::string fen);
        bool squareAttacked(int square, int attacking_side);

        void printCharPieceAtSq120(int sq120);
        void printCharPieceAtSq64(int sq64);
};



