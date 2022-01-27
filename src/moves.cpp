
#include "moves.hpp"

Move::Move(U64 movebits){
    moves = movebits;
}

int Move::fromSq(){
    return (moves & 0x7F);
}
int Move::toSq(){
    return (moves >> 7) & 0x7F;
}

int Move::captured(){
    return (moves >> 14) & 0xF;
}

int Move::promoted(){
    return (moves >> 20) & 0xF;
}

int Move::enPassant(){
    return moves & 0x40000;
}

int Move::pawnStart(){
    return moves & 0x80000;
}

int Move::castle(){
    return moves & 0x1000000;
}

U64 Move::createMoveBits(int fromSq,int toSq,int captured,int enPassant,int pawnStart,int promoted,int castle){
    return ( (fromSq) | (toSq << 7) | ( captured << 14) | (enPassant << 18) | (pawnStart << 19) | (promoted << 20) | (castle << 24));
}

std::vector<Move> Move::generateWhitePawnMove(int pawnSq120,Board b){

    assert (checkInsideBoard(pawnSq120));
    std::vector<Move> possible_moves = {};
    
    // move forward one square
    if(b.pieces[pawnSq120 + 10] == EMPTY){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,0,0);
        possible_moves.push_back(Move(movebits));

        // need to be inside this because rank + 10 need to be empty to be able to move forward 2 square
        if(getRankFromSq120(pawnSq120) == 2 && b.pieces[pawnSq120 + 20] == EMPTY){
            U64 movebits = createMoveBits(pawnSq120,pawnSq120+20,0,0,0,0,0);
            possible_moves.push_back(Move(movebits));
        }

        if (getRankFromSq120(pawnSq120) == 7){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }
    }


    if (checkInsideBoard(pawnSq120 + 9) && getPieceColor(b.pieces[pawnSq120 + 9]) == BLACK ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120+9,b.pieces[pawnSq120 + 9],0,0,0,0);
        possible_moves.push_back(Move(movebits));

        if (getRankFromSq120(pawnSq120) == 7){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }
    }
   
    if (checkInsideBoard(pawnSq120 + 11) && getPieceColor(b.pieces[pawnSq120 + 11]) == BLACK ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120+11,b.pieces[pawnSq120 + 11],0,0,0,0);
        possible_moves.push_back(Move(movebits));

        if (getRankFromSq120(pawnSq120) == 7){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,wQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }
    }
    
    // enPassant on opposite pawn (black pawn)
    if (checkInsideBoard(pawnSq120 + 9) && b.enPassantSquare == pawnSq120 + 9 ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120+9,bP,1,0,0,0);
        possible_moves.push_back(Move(movebits));


    }
    std::cout << "test5: " << possible_moves.size() << "\n";
    if (checkInsideBoard(pawnSq120 + 11) && b.enPassantSquare == pawnSq120 + 11 ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120+11,bP,1,0,0,0);
        possible_moves.push_back(Move(movebits));
    }

    return possible_moves;
    /*
    #define MFLAGEP 0x40000
    #define MFLAGPS 0x80000
    #define MFLAGCA 0x1000000

    #define MFLAGCAP 0x7C000
    #define MFLAGPROM 0xF00000


    */
    
}

std::vector<Move> Move::generatePawnMoves(Board b){

    std::vector<Move> all_moves = {};
    if (b.turn == WHITE){
        
        int whitePwnNum = b.pieceNum[wP];
        for (int i = 0 ; i < whitePwnNum ; i++){
            std::vector<Move> all_moves_by_piece =  generateWhitePawnMove(b.pieceList[wP][i],b);
            all_moves.insert(all_moves.end(), all_moves_by_piece.begin(), all_moves_by_piece.end());
        }
    }

    return all_moves;
}

std::string Move::move_format_print(Move move){

    int fromSq120 = move.fromSq();
    int toSq120 = move.toSq();
    int captured = move.captured();

    std::string fromSqStr = sq64ToSqStr(Sq120_to_Sq64[fromSq120]);
    std::string toSqStr = sq64ToSqStr(Sq120_to_Sq64[toSq120]);
    char captured_piece = pieceToChar(captured);
    std::string cap = std::string(1, captured_piece);

    return "FromSq:" + fromSqStr + " toSqStr:" + toSqStr + " cap:" + cap;
}