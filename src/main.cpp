
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

    std::string FEN = "r1bqkbnr/ppp1pppp/2n5/3p4/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq d6 2 3";
    b.parseFEN(FEN);

    b.print_board();
    std::cout << b.squareAttacked(D5,BLACK);
    

    return 0;
}