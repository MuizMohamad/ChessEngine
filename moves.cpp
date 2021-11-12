
#include "moves.hpp"

Moves::Moves(U64 movebits){
    moves = movebits;
}

int Moves::fromSq(){
    return (moves & 0x3F);
}
int Moves::toSq(){
    return (moves >> 7) & 0x3F;
}

int Moves::captured(){
    return (moves >> 14) & 0xF;
}

int Moves::promoted(){
    return (moves >> 20) & 0xF;
}

int Moves::enPassant(){
    return 0;
}

int Moves::castle(){
    return 0;
}

