
#include "defs.h"
#include "board.h"
#include "helper.h"


int main(){

    std::cout << isdigit('1') << "\n";

    Board b;    
    b.print_board();
    
    std::cout << "\n";
    b.parsingFEN("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
    b.print_board();
    

    return 0;
}