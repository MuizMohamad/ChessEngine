
#include "defs.hpp"
#include "init.hpp"
#include "board.hpp"
#include "moves.hpp"
#include "helper.hpp"
#include "makemove.hpp"
#include "perft.hpp"

// g++ helper.cpp validation.cpp board.cpp init.cpp moves.cpp perft.cpp makemove.cpp main.cpp -o chessengine

// FEN board position for testing

// std::string FEN = "r1bqkbnr/ppp1pppp/2n5/3p4/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq d6 2 3";
// std::string fenTestWPMoves = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
// std::string fenTestBPMoves = "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1";
// std::string fenTestKnightKingMoves ="5k2/1n6/4n3/6N1/8/3N4/8/5K2 b - - 0 1";
// std::string fenTestQueensMoves = "6k1/8/4nq2/8/1nQ5/5N2/1N6/6K1 w - - 0 1";
// std::string fenTestBishopsMoves = "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 b - - 0 1";
// std::string fenTestRookMoves = "6k1/8/5r2/8/1nR5/5N2/8/6K1 b - - 0 1";
// std::string fenTestCastle1Moves = "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1";
// std::string fenTestCastle2Moves =  "3rk2r/8/8/8/8/8/6p1/R3K2R b KQk - 0 1";

int main(){

    InitAll();
    
    std::string perft_fen = START_FEN;
    //std::string perft_fen = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";

    Board b;
    b.parseFEN(perft_fen);

    //PerftTest(1, b);
    PerftTest(5, b);
    // PerftTest(3, b);
    // PerftTest(4, b);

    return 0;
}