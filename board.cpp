
#include "board.h"


    
Board::Board(){
    
    enPassantKey = 0;
    turn = WHITE;

    for (int i = 0 ; i < 13 ; i++){
        for (int j = 0 ; j < 64 ; j++){
            pieceListInSq[i][j] = 0;
        }
    }
    
    init_pieces();
    
}

void Board::init_pieces(){
    // initiate pawns
    for (int i = 0 ; i < 8 ; i++){
        pieceListInSq[wP][wPawnStart[i]] = 1;
        pieceListInSq[bP][bPawnStart[i]] = 1;
    }
 
    // initiate knight
    for (int i = 0 ; i < 2 ; i++){
        pieceListInSq[wN][wKnightStart[i]] = 1;
        pieceListInSq[bN][bKnightStart[i]] = 1;
    }

    // initiate bishop
    for (int i = 0 ; i < 2 ; i++){
        pieceListInSq[wB][wBishopStart[i]] = 1;
        pieceListInSq[bB][bBishopStart[i]] = 1;
    }

    // initiate rook
    for (int i = 0 ; i < 2 ; i++){
        pieceListInSq[wR][wRookStart[i]] = 1;
        pieceListInSq[bR][bRookStart[i]] = 1;
    }

    // initiate queen
    for (int i = 0 ; i < 1 ; i++){
        pieceListInSq[wQ][wQueenStart[i]] = 1;
        pieceListInSq[bQ][bQueenStart[i]] = 1;
    }

    // initiate king
    for (int i = 0 ; i < 1 ; i++){
        pieceListInSq[wK][wKingStart[i]] = 1;
        pieceListInSq[bK][bKingStart[i]] = 1;
    }
}

void Board::printBoard(){

    std::cout << "--------\n";
    for (int i = RANK_8 ; i >= RANK_1 ; i--){
        std::string current_row = "--------";
        for (int j = FILE_A ; j <= FILE_H ; j++){
            int square = 8*(i-1) + j;
            current_row[j-1] = pieceToChar(getPieceAtSquare(square));
        }

        std::cout << current_row << "\n";
    }
    std::cout << "--------\n";
}

int Board::getPieceAtSquare(int square){

    int piece = EMPTY;
    for (int i = 0; i < 13; i++){
        if (pieceListInSq[i][square] == 1){
            return i;
        }
    }
    
    return piece;
}

char Board::pieceToChar(int piece){
    switch (piece){
        case wP:
            return 'P';
            break;
        case wN:
            return 'N';
            break;
        case wB:
            return 'B';
            break;
        case wR:
            return 'R';
            break;
        case wQ:
            return 'Q';
            break;
        case wK:
            return 'K';
            break;
        case bP:
            return 'P';
            break;
        case bN:
            return 'N';
            break;
        case bB:
            return 'B';
            break;
        case bR:
            return 'R';
            break;
        case bQ:
            return 'Q';
            break;
        case bK:
            return 'K';
            break;
        default:
            return ' ';
            break;

    };

}
