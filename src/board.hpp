
#pragma once

#include "defs.hpp"
#include "helper.hpp"

class Board{

     // Put each piece location in square based on enum
     // extra 65 for square 1-64
    int pieceListInSq64[13][65];
    int piecesInSq64[65];

    U64 enPassantSquare; // en Passant square
    U64 turn; // 0 for white , 1 for black

    // 0000 : 4th bit - black can castle queen, 3rd bit - black can castle king, 2nd -, white castle queen , 1st - white castle king
    U64 castlingKey; 

    // current number of moves, eg after 1 c4 , current total move is 1
    int fullMove;

    // number of completed moves since last pawn capture
    int halfMove;

    public:

        Board();
        void empty_board();
        void print_board();
        void init_pieces();
        int getPieceAtSq64(int square);
        void parsingFEN(std::string fen);
        bool squareAttacked(int square, int attacking_side);
        
};



