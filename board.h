
#pragma once

#include "defs.h"
#include "helper.h"

class Board{

     // Put each piece location in square based on enum
    int pieceListInSq[13][64];

    int enPassantKey; // en Passant square
    int turn; // 0 for white , 1 for black

    // 0000 : 4th bit - black castle queen, 3rd bit - black castle king, 2nd bi -, white castle queen , 1st - white castle king
    int castlingKey; 

    public:

        Board();
        void printBoard();
        void init_pieces();
        int getPieceAtSquare(int square);
        char pieceToChar(int piece);
};



