
#include "defs.h"
#include "board.h"
#include "helper.h"


int main(){


    Board b;
    b.print_board();

    std::string FEN = "r1bqkbnr/ppp1pppp/2n5/3p4/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq d6 2 3";
    b.parsingFEN(FEN);

    b.print_board();
    std::cout << b.squareAttacked(D5,BLACK);

    return 0;
}