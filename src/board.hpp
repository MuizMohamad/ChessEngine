
#pragma once

#include "defs.hpp"
#include "helper.hpp"
#include "validation.hpp"
#include "undo.hpp"
#include "moves.hpp"

// class Board or in another words chess 'positions'
class Board {

    public:
        // Put each piece location in square based on enum
        // extra 65 for square 1-64

        // by default we calculate using 12x10 board representation (start with index 0 - 119)
        int pieceList[13][10];
        int pieces[120];
    
        int pieceListInSq64[13][10];
        int piecesInSq64[65];

        int pieceNum[13];
        
        // material value for both sides 0 - white , 1 - black
        int materialValue[2];

        int enPassantSquare; // en Passant square (sq 120)
        int turn; // 0 for white , 1 for black

        // castling permission
        // 0000 : 4th bit - black can castle queen, 3rd bit - black can castle king, 2nd -, white castle queen , 1st - white castle king
        int castlingKey; 

        // current number of moves, eg after 1 c4 , current total move is 1
        int fullMove;

        // number of completed moves since last pawn capture or PLY
        int halfMove;
        
        int fiftyMove;

        U64 position_key;

        int halfMoveHistory;
        Undo history[MAX_GAME_MOVES];

        // Principal Variation table to store best line
        std::unordered_map<U64,Move> pvTable;

        int searchHistory[13][BOARD_SQ_NUM];
        int searchKillers[2][MAX_DEPTH];

    public:

        Board();

        // initialization or reset functions
        void empty_board();
        void resetListValues();
        void init_pieces();

        // helper functions
        void updateListsMaterial();
        int getPieceAtSq64(int square);
        int getKingSquare(int side);

        // functional functions
        void parseFEN(std::string fen);
        bool squareAttacked(int square, int defending_side);
        bool checkRepetition();
        
        // printing functions
        void print_board();
        void printCharPieceAtSq120(int sq120);
        void printCharPieceAtSq64(int sq64);

        void hash_piece(int piece, int sq120);
        void hash_castling_key();
        void hash_side();
        void hash_en_passant();

        // Static functions to calculate hash keys
        static U64 generatePositionKeys(Board b);
        
        
};



