
#pragma once

#include "defs.h"
#include "helper.h"

class Board{

    
     // Put each piece location in square based on enum
    int pieceListInSq[13][64];

    int enPassantKey; // en Passant square
    int turn; // 0 for white , 1 for black

    // 0000 : 4th bit - black can castle queen, 3rd bit - black can castle king, 2nd -, white castle queen , 1st - white castle king
    int castlingKey; 

    // current number of moves, eg after 1 c4 , current total move is 1
    int fullMove;

    // number of completed moves since last pawn capture
    int halfMove;

    public:

        Board();
        void printBoard();
        void init_pieces();
        int getPieceAtSquare(int square);
        char pieceToChar(int piece);
        void parsingFEN(string fen);
};



