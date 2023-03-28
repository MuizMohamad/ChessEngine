#pragma once

#include "defs.hpp"

// class Undo to stores information about previous moves
class Undo {

    public:

        U64 move_bits;
        int enPassantSquare; 

        int castlingKey; 
        int fiftyMove;
        U64 position_key;

};