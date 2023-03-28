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