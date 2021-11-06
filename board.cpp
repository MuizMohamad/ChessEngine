
#include "board.h"

class Board {
    
    Board(){
        wPawnLocations = 0LL;
        bPawnLocations = 0LL;

        wBishopLocations = 0LL;
        bBishopLocations = 0LL;

        wKnightLocations = 0LL;
        bKnightLocations = 0LL;

        wRookLocations = 0LL;
        bRookLocations = 0LL;

        wQueenLocations = 0LL;
        bQueenLocations = 0LL;

        wKingLocations = 0LL;
        bKingLocations = 0LL;

    }

    void init_pieces(){

        // initiate white pawn
        for (int square : wPawnStart){
            setNthBitFromNumber(this->wPawnLocations,square);
        }

        for (int square : bPawnStart){
            setNthBitFromNumber(this->bPawnLocations,square);
        }

        for (int square : wKnightStart){
            setNthBitFromNumber(this->wKnightLocations,square);
        }

        for (int square : bKnightStart){
            setNthBitFromNumber(this->bKnightLocations,square);
        }

        for (int square : wPawnStart){
            setNthBitFromNumber(this->wPawnLocations,square);
        }

        for (int square : bPawnStart){
            setNthBitFromNumber(this->bPawnLocations,square);
        }
    }
}