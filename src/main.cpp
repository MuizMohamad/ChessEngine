
#include "defs.hpp"
#include "init.hpp"
#include "board.hpp"
#include "moves.hpp"
#include "helper.hpp"

// g++ helper.cpp validation.cpp board.cpp init.cpp moves.cpp main.cpp -o chessengine

int main(){

    InitAll();

    Board b;
    //b.print_board();
    
    // FEN board position for testing

    // std::string FEN = "r1bqkbnr/ppp1pppp/2n5/3p4/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq d6 2 3";
    // std::string fenTestWPMoves = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
    // std::string fenTestBPMoves = "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1";
    // std::string fenTestKnightKingMoves ="5k2/1n6/4n3/6N1/8/3N4/8/5K2 b - - 0 1";
    // std::string fenTestQueensMoves = "6k1/8/4nq2/8/1nQ5/5N2/1N6/6K1 w - - 0 1";
    // std::string fenTestBishopsMoves = "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 b - - 0 1";
    // std::string fenTestRookMoves = "6k1/8/5r2/8/1nR5/5N2/8/6K1 b - - 0 1";
    std::string fenTestCastle1Moves = "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1";
    std::string fenTestCastle2Moves =  "3rk2r/8/8/8/8/8/6p1/R3K2R b KQk - 0 1";

    // b.parseFEN(fenTestCastle1Moves);
    // // REMEMBER sq attacks turn is defending side
    
    // b.print_board();

    // std::vector<Move> test = Move::generateCastlingMoves(b);
    // std::cout << "How many moves: "<< test.size() << "\n";

    // for (Move m : test){
    //     m.move_format_print();
    // }

    // std::string fenTestFinal = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";

    // Board b2;
    // b2.parseFEN(fenTestFinal);
    // std::vector<Move> test2 = Move::generateAllMoves(b2);
    // std::cout << "Final: "<< test2.size() << "\n";

    return 0;
}