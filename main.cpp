
#include "defs.h"
#include "board.h"
#include "helper.h"


int main(){

    

    
    std::vector<int> allE4diagonals = getLeftRightHorizontalSq(E4);
    for (int sq : allE4diagonals){
        std::cout << sqToSqStr(sq) << "\n";
    }
    
    return 0;
}