
#pragma once

#include "defs.h"
#include "helper.h"

class Board{

    // Put each piece location as bits
    // where first bit is a1 ... 2nd is b1 ... 9th bit is a2
    U64 wPawnLocations;
    U64 bPawnLocations;

    U64 wBishopLocations;
    U64 bBishopLocations;

    U64 wKnightLocations;
    U64 bKnightLocations;

    U64 wRookLocations;
    U64 bRookLocations;

    U64 wQueenLocations;
    U64 bQueenLocations;

    U64 wKingLocations;
    U64 bKingLocations;

    public:

        Board();
        void printBoard();
        char getPieceAtSquare(int square);
};



