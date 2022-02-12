
#include "defs.hpp"
#include "init.hpp"
#include "board.hpp"
#include "moves.hpp"
#include "helper.hpp"

// g++ helper.cpp validation.cpp board.cpp init.cpp moves.cpp main.cpp -o chessengine

int main(){

    InitSq120To64();

    Board b;
    b.print_board();
    
    // std::string FEN = "r1bqkbnr/ppp1pppp/2n5/3p4/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq d6 2 3";
    // std::string fenTestWPMoves = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
    //std::string fenTestBPMoves = "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1";
    std::string fenTestKnightKingMoves ="5k2/1n6/4n3/6N1/8/3N4/8/5K2 b - - 0 1";

    b.parseFEN(fenTestKnightKingMoves);

    //b.print_board();
    // std::cout << b.squareAttacked(D5,BLACK);
    //b.printCharPieceAtSq120(D3);
    
    std::vector<Move> test = Move::generateNonLoopPieceMoves(b);
    std::cout << "How many moves: "<< test.size() << "\n";

    for (Move m : test){
        m.move_format_print();
    }
    return 0;
}