
#include "board.h"


    
Board::Board(){
    wPawnLocations = 0ULL;
    bPawnLocations = 0ULL;

    wBishopLocations = 0ULL;
    bBishopLocations = 0ULL;

    wKnightLocations = 0ULL;
    bKnightLocations = 0ULL;

    wRookLocations = 0ULL;
    bRookLocations = 0ULL;

    wQueenLocations = 0ULL;
    bQueenLocations = 0ULL;

    wKingLocations = 0ULL;
    bKingLocations = 0ULL;

    // initiate pawns
    for (int square : wPawnStart){
        setNthBitFromNumber(&wPawnLocations,square);
    }
    //std::cout << wPawnLocations;
    for (int square : bPawnStart){
        setNthBitFromNumber(&bPawnLocations,square);
    }

    // initiate knight
    for (int square : wKnightStart){
        setNthBitFromNumber(&wKnightLocations,square);
    }

    for (int square : bKnightStart){
        setNthBitFromNumber(&bKnightLocations,square);
    }

    // initiate bishop
    for (int square : wBishopStart){
        setNthBitFromNumber(&wBishopLocations,square);
    }

    for (int square : bBishopStart){
        setNthBitFromNumber(&bBishopLocations,square);
    }

    // initiate rook
    for (int square : wRookStart){
        setNthBitFromNumber(&wRookLocations,square);
    }

    for (int square : bRookStart){
        setNthBitFromNumber(&bRookLocations,square);
    }

    // initiate queen
    for (int square : wQueenStart){
        setNthBitFromNumber(&wQueenLocations,square);
    }

    for (int square : bQueenStart){
        setNthBitFromNumber(&bQueenLocations,square);
    }

    // initiate king
    for (int square : wKingStart){
        setNthBitFromNumber(&wKingLocations,square);
    }

    for (int square : bKingStart){
        setNthBitFromNumber(&bKingLocations,square);
    }
}

//void Board::init_pieces(){
//}

void Board::printBoard(){

    for (int i = RANK_8 ; i >= RANK_1 ; i--){
        std::string current_row = "--------";
        for (int j = FILE_A ; j <= FILE_H ; j++){
            int square = 8*(i-1) + j;
            current_row[j-1] = getPieceAtSquare(square);
        }

        std::cout << current_row << "\n";
    }

}

char Board::getPieceAtSquare(int square){

    char piece = ' ';

    if (getNthBitFromNumber(wPawnLocations,square) == 1 || getNthBitFromNumber(bPawnLocations,square) == 1){
        piece = 'P';
    }
    
    else if (getNthBitFromNumber(wBishopLocations,square) == 1 || getNthBitFromNumber(bBishopLocations,square) == 1){
        piece = 'B';
    }
    
    else if (getNthBitFromNumber(wKnightLocations,square) == 1 || getNthBitFromNumber(bKnightLocations,square) == 1){
        piece = 'N';
    }
    
    else if (getNthBitFromNumber(wRookLocations,square) == 1 || getNthBitFromNumber(bRookLocations,square) == 1){
        piece = 'R';
    }
    
    else if (getNthBitFromNumber(wQueenLocations,square) == 1 || getNthBitFromNumber(bQueenLocations,square) == 1){
        piece = 'Q';
    }

    else if (getNthBitFromNumber(wKingLocations,square) == 1 || getNthBitFromNumber(bKingLocations,square) == 1){
        piece = 'K';
    }
    
    return piece;
}
