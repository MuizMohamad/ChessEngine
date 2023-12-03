#include "perft.hpp"

long long leafNodes;

void Perft(int depth, Board& b){

    if (depth == 0){
        leafNodes++;
        return;
    }

    std::vector<Move> all_moves = Move::generateAllMoves(b);
    
    for (long long i = 0 ; i < all_moves.size() ; i++){
        Move move = all_moves.at(i);

        if (!makeMove(move,b)){
            continue;
        }

        Perft(depth-1,b);
        takeMove(b);

        
    }

}

void PerftTest(int depth, Board& b){

    b.print_board();

    std::cout << "\nStarting Test to Depth: " << depth << "\n";

    leafNodes = 0;

    std::vector<Move> all_moves = Move::generateAllMoves(b);

    for (long long i = 0 ; i < all_moves.size(); i++){
        
        Move move = all_moves.at(i);

        if (!makeMove(move,b)){
            continue;
        }

        long long cumulative_nodes = leafNodes;

        Perft(depth-1,b);
        takeMove(b);

        long long oldnodes = leafNodes - cumulative_nodes;

        std::cout << "Moves : " << i+1 << " :: ";
        move.print();
        std::cout << " :: " << oldnodes << "\n";

    } 

    std::cout << "\nTest Complete : " << leafNodes << " nodes visited. " << "\n";
}


void perft(int depth, std::string fen){

    Board b;
    b.parseFEN(fen);

    leafNodes = 0;

    std::vector<Move> all_moves = Move::generateAllMoves(b);

    for (long long i = 0 ; i < all_moves.size(); i++){
        
        Move move = all_moves.at(i);

        if (!makeMove(move,b)){
            continue;
        }

        long long cumulative_nodes = leafNodes;

        Perft(depth-1,b);
        takeMove(b);

        long long oldnodes = leafNodes - cumulative_nodes;

    } 

}

void perftUnitTest(int depth){
    
    std::cout << "-------------------------\nPerft Test running\n-------------------------\nDisplaying failed results only\n-------------------------\n";

    std::ifstream perftFile("perftsuite.epd");
    std::string currentLine;

    int line = 0;

    if ( perftFile.is_open() ) {    
        while ( perftFile ) {
            line++;
            std::getline(perftFile, currentLine);
          
            std::vector<std::string> splitted_string = split_string(currentLine," ;");
            
            std::string fen = splitted_string.at(0);
            std::string d1 = splitted_string.at(1);

            // get expected result
            std::string depthStr = splitted_string.at(depth);
            std::vector<std::string> splitted_depthStr = split_string(depthStr," ");

            long long expected = std::stoll(splitted_depthStr.at(1));
            
            // do actual tests and updates global var leafNodes
            perft(depth, fen);
            long long actual = leafNodes;
            
            if (actual != expected){
                std::cout << "Line " << line << " ,FEN: [" << fen << "], Depth " << depth << " : FAILED (Actual: " << actual << ", Expected: " << expected << ")\n" ;  
            }

        }          
    }

    std::cout << "-------------------------\nTest completed\n-------------------------"
}