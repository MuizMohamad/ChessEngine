#include "validation.hpp"

bool checkInsideBoard(std::string sqStr){

    char file = sqStr[0];
    char rank = sqStr[1];

    bool checkFile = int(file) >= 'a' && int(file) <= 'h';
    bool checkRank = int(rank) >= '1' && int(rank) <= '8';

    return checkFile && checkRank;
}

// always sq120
bool checkInsideBoard(int sq120){
    int sq64 = Sq120_to_Sq64[sq120];
    return checkInsideBoard(sq64ToSqStr(sq64));
}


bool checkValidSide(int side){
    return (side == WHITE || side == BLACK) ? 1 : 0;
}

bool checkValidFileRank(int fr){
    return (fr >= 0 && fr <= 7) ? 1 : 0;
}

bool checkPieceValidEmpty(int piece){
    return (piece >= EMPTY && piece <= bK) ? 1 : 0;
}

bool checkPieceValid(int piece){
    return (piece >= wP && piece <= bK) ? 1 : 0;
}
