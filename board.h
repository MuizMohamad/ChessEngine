// A2DD.h
#pragma once

class Board{
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

        int getSum();

};



