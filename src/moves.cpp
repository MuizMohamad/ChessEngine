
#include "moves.hpp"

const std::vector<int> Move::loopPieces = {wB,wR,wQ,0,bB,bR,bQ,0};
const std::vector<int> Move::nonLoopPieces = {wN,wK,0,bN,bK,0};

const std::vector<int> Move::loopPieceIndex = {0,4};
const std::vector<int> Move::nonLoopPieceIndex = {0,3};


// direction for each piece
const std::vector<std::vector<int>> Move::pceDir = {
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ -8, -19,	-21, -12, 8, 19, 21, 12 },
	{ -9, -11, 11, 9, 0, 0, 0, 0 },
	{ -1, -10,	1, 10, 0, 0, 0, 0 },
	{ -1, -10,	1, 10, -9, -11, 11, 9 },
	{ -1, -10,	1, 10, -9, -11, 11, 9 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ -8, -19,	-21, -12, 8, 19, 21, 12 },
	{ -9, -11, 11, 9, 0, 0, 0, 0 },
	{ -1, -10,	1, 10, 0, 0, 0, 0 },
	{ -1, -10,	1, 10, -9, -11, 11, 9 },
	{ -1, -10,	1, 10, -9, -11, 11, 9 }
};

const std::vector<int> Move::numDir = { 0, 0, 8, 4, 4, 8, 8, 0, 8, 4, 4, 8, 8};

Move::Move(){
    moves = 0;
}

Move::Move(U64 movebits){
    moves = movebits;
}

int Move::getMoves(){
    return this->moves;
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
   
    if (moves & 0x40000 ) return 1;
    return 0;
}

int Move::pawnStart(){
    
    if (moves & 0x80000 ) return 1;
    return 0;
}

int Move::castle(){

    if (moves & 0x1000000 ) return 1;
    return 0;
}

U64 Move::createMoveBits(int fromSq,int toSq,int captured,int enPassant,int pawnStart,int promoted,int castle){
    return ( (fromSq) | (toSq << 7) | ( captured << 14) | (enPassant << 18) | (pawnStart << 19) | (promoted << 20) | (castle << 24));
}

std::vector<Move> Move::generateWhitePawnMove(int pawnSq120, Board b){

    assert (checkInsideBoard(pawnSq120));
    std::vector<Move> possible_moves;
    
    // move forward one square
    if(b.pieces[pawnSq120 + 10] == EMPTY){
        
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
        else {
            U64 movebits = createMoveBits(pawnSq120,pawnSq120+10,0,0,0,0,0);
            possible_moves.push_back(Move(movebits));

            // need to be inside this because rank + 10 need to be empty to be able to move forward 2 square
            if(getRankFromSq120(pawnSq120) == 2 && b.pieces[pawnSq120 + 20] == EMPTY){
                U64 movebits = createMoveBits(pawnSq120,pawnSq120+20,0,0,1,0,0);
                possible_moves.push_back(Move(movebits));
            }
        }
    }

    if (checkInsideBoard(pawnSq120 + 9) && getPieceColor(b.pieces[pawnSq120 + 9]) == BLACK ){
        
        if (getRankFromSq120(pawnSq120) == 7){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120+9,b.pieces[pawnSq120 + 9],0,0,wR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120+9,b.pieces[pawnSq120 + 9],0,0,wN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120+9,b.pieces[pawnSq120 + 9],0,0,wB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120+9,b.pieces[pawnSq120 + 9],0,0,wQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }
        else {
            U64 movebits = createMoveBits(pawnSq120,pawnSq120+9,b.pieces[pawnSq120 + 9],0,0,0,0);
            possible_moves.push_back(Move(movebits));
        }
    }
   
    if (checkInsideBoard(pawnSq120 + 11) && getPieceColor(b.pieces[pawnSq120 + 11]) == BLACK ){

        if (getRankFromSq120(pawnSq120) == 7){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120+11,b.pieces[pawnSq120 + 11],0,0,wR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120+11,b.pieces[pawnSq120 + 11],0,0,wN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120+11,b.pieces[pawnSq120 + 11],0,0,wB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120+11,b.pieces[pawnSq120 + 11],0,0,wQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }

        else {
            U64 movebits = createMoveBits(pawnSq120,pawnSq120+11,b.pieces[pawnSq120 + 11],0,0,0,0);
            possible_moves.push_back(Move(movebits));
        }
    }
    
    // enPassant on opposite pawn (black pawn)
    if (checkInsideBoard(pawnSq120 + 9) && b.enPassantSquare == pawnSq120 + 9 ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120+9,bP,1,0,0,0);
        possible_moves.push_back(Move(movebits));

    }

    if (checkInsideBoard(pawnSq120 + 11) && b.enPassantSquare == pawnSq120 + 11 ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120+11,bP,1,0,0,0);
        possible_moves.push_back(Move(movebits));
    }

    return possible_moves;

}

std::vector<Move> Move::generateBlackPawnMove(int pawnSq120,Board b){

    assert (checkInsideBoard(pawnSq120));
    std::vector<Move> possible_moves;
    
    // move forward one square
    if(b.pieces[pawnSq120 - 10] == EMPTY){
        
        if (getRankFromSq120(pawnSq120) == 2){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120-10,0,0,0,bR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120-10,0,0,0,bN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120-10,0,0,0,bB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120-10,0,0,0,bQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }
        else {
            U64 movebits = createMoveBits(pawnSq120,pawnSq120-10,0,0,0,0,0);
            possible_moves.push_back(Move(movebits));

            // need to be inside this because rank + 10 need to be empty to be able to move forward 2 square
            if(getRankFromSq120(pawnSq120) == 7 && b.pieces[pawnSq120 - 20] == EMPTY){
                U64 movebits = createMoveBits(pawnSq120,pawnSq120-20,0,0,1,0,0);
                possible_moves.push_back(Move(movebits));
            }
        }
    }

    if (checkInsideBoard(pawnSq120 - 9) && getPieceColor(b.pieces[pawnSq120 - 9]) == WHITE ){
        
        if (getRankFromSq120(pawnSq120) == 2){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120-9,b.pieces[pawnSq120 - 9],0,0,bR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120-9,b.pieces[pawnSq120 - 9],0,0,bN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120-9,b.pieces[pawnSq120 - 9],0,0,bB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120-9,b.pieces[pawnSq120 - 9],0,0,bQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }
        else {
            U64 movebits = createMoveBits(pawnSq120,pawnSq120-9,b.pieces[pawnSq120 - 9],0,0,0,0);
            possible_moves.push_back(Move(movebits));
        }
    }
   
    if (checkInsideBoard(pawnSq120 - 11) && getPieceColor(b.pieces[pawnSq120 - 11]) == WHITE ){

        if (getRankFromSq120(pawnSq120) == 2){
            U64 movePromoteRook = createMoveBits(pawnSq120,pawnSq120-11,b.pieces[pawnSq120 - 11],0,0,bR,0);
            possible_moves.push_back(Move(movePromoteRook));

            U64 movePromoteKnight = createMoveBits(pawnSq120,pawnSq120-11,b.pieces[pawnSq120 - 11],0,0,bN,0);
            possible_moves.push_back(Move(movePromoteKnight));

            U64 movePromoteBishop = createMoveBits(pawnSq120,pawnSq120-11,b.pieces[pawnSq120 - 11],0,0,bB,0);
            possible_moves.push_back(Move(movePromoteBishop));

            U64 movePromoteQueen = createMoveBits(pawnSq120,pawnSq120-11,b.pieces[pawnSq120 - 11],0,0,bQ,0);
            possible_moves.push_back(Move(movePromoteQueen));
        }

        else {
            U64 movebits = createMoveBits(pawnSq120,pawnSq120-11,b.pieces[pawnSq120 - 11],0,0,0,0);
            possible_moves.push_back(Move(movebits));
        }
    }
    
    // enPassant on opposite pawn (black pawn)
    if (checkInsideBoard(pawnSq120 - 9) && b.enPassantSquare == pawnSq120 - 9 ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120-9,wP,1,0,0,0);
        possible_moves.push_back(Move(movebits));

    }

    if (checkInsideBoard(pawnSq120 - 11) && b.enPassantSquare == pawnSq120 - 11 ){
        U64 movebits = createMoveBits(pawnSq120,pawnSq120-11,wP,1,0,0,0);
        possible_moves.push_back(Move(movebits));
    }

    return possible_moves;

}

std::vector<Move> Move::generatePawnMoves(Board b){

    std::vector<Move> all_moves;
    if (b.turn == WHITE){
        
        int whitePwnNum = b.pieceNum[wP];
        for (int i = 0 ; i < whitePwnNum ; i++){
            std::vector<Move> all_moves_by_piece =  generateWhitePawnMove(b.pieceList[wP][i],b);
            all_moves.insert(all_moves.end(), all_moves_by_piece.begin(), all_moves_by_piece.end());
        }
    }
    if (b.turn == BLACK){
        int blackPwnNum = b.pieceNum[bP];
        for (int i = 0 ; i < blackPwnNum ; i++){
            std::vector<Move> all_moves_by_piece =  generateBlackPawnMove(b.pieceList[bP][i],b);
            all_moves.insert(all_moves.end(), all_moves_by_piece.begin(), all_moves_by_piece.end());
        }
    }

    return all_moves;
}

std::vector<Move> Move::generateLoopPieceMoves(Board b){
    
    std::vector<Move> all_moves;

    int turn = b.turn;

    int pieceIndex = loopPieceIndex[turn];
    int cur_piece = loopPieces[pieceIndex];

    while(loopPieces[pieceIndex] != 0){

        cur_piece = loopPieces[pieceIndex];

        if (b.turn == WHITE){
            
            int curPieceNum = b.pieceNum[cur_piece];
            for (int i = 0 ; i < curPieceNum ; i++){
                int curSq = b.pieceList[cur_piece][i];
                for (int j = 0 ; j < numDir[cur_piece];j++){
                    int dir = pceDir[cur_piece][j];
                    int sqAfter = curSq + dir;

                    while(checkInsideBoard(sqAfter)){
                        if (!checkInsideBoard(sqAfter)) continue;

                        if (b.pieces[sqAfter] == EMPTY){
                            U64 movebits = createMoveBits(curSq,sqAfter,0,0,0,0,0);
                            all_moves.push_back(Move(movebits));    
                        }

                        if (getPieceColor(b.pieces[sqAfter]) == BLACK){
                            U64 movebits = createMoveBits(curSq,sqAfter,b.pieces[sqAfter],0,0,0,0);
                            all_moves.push_back(Move(movebits));
                            break;    
                        }
                        if (getPieceColor(b.pieces[sqAfter]) == WHITE){
                            break;     
                        }
                        sqAfter += dir;
                    }
                }
            }
        }
        if (b.turn == BLACK){
            int curPieceNum = b.pieceNum[cur_piece];

            for (int i = 0 ; i < curPieceNum ; i++){
                int curSq = b.pieceList[cur_piece][i];

                for (int j = 0 ; j < numDir[cur_piece];j++){
                    int dir = pceDir[cur_piece][j];
                    int sqAfter = curSq + dir;

                    while(checkInsideBoard(sqAfter)){
                        if (!checkInsideBoard(sqAfter)) continue;

                        if (b.pieces[sqAfter] == EMPTY){
                            U64 movebits = createMoveBits(curSq,sqAfter,0,0,0,0,0);
                            all_moves.push_back(Move(movebits));    
                        }
                        
                        if (getPieceColor(b.pieces[sqAfter]) == WHITE){
                            U64 movebits = createMoveBits(curSq,sqAfter,b.pieces[sqAfter],0,0,0,0);
                            all_moves.push_back(Move(movebits));
                            break;     
                        }

                        if (getPieceColor(b.pieces[sqAfter]) == BLACK){
                            break;     
                        }
                        sqAfter += dir;
                    }
                }
            }
        }
        
        pieceIndex++;
    }

    return all_moves;

}

std::vector<Move> Move::generateNonLoopPieceMoves(Board b){

    std::vector<Move> all_moves;
    int turn = b.turn;

    int pieceIndex = nonLoopPieceIndex[turn];
    int cur_piece = nonLoopPieces[pieceIndex];

    // generate moves here
    while(nonLoopPieces[pieceIndex] != 0){

        cur_piece = nonLoopPieces[pieceIndex];

        //std::cout << "CUR : " << cur_piece << '\n';
        if (b.turn == WHITE){
            
            int curPieceNum = b.pieceNum[cur_piece];
            for (int i = 0 ; i < curPieceNum ; i++){
                int curSq = b.pieceList[cur_piece][i];
                
                for (int j = 0 ; j < numDir[cur_piece];j++){
                    int dir = pceDir[cur_piece][j];
                    int sqAfter = curSq + dir;

                    if (!checkInsideBoard(sqAfter)) continue;

                    if (b.pieces[sqAfter] == EMPTY){
                        U64 movebits = createMoveBits(curSq,sqAfter,0,0,0,0,0);
                        all_moves.push_back(Move(movebits));    
                    }

                    if (getPieceColor(b.pieces[sqAfter]) == BLACK){
                        U64 movebits = createMoveBits(curSq,sqAfter,b.pieces[sqAfter],0,0,0,0);
                        all_moves.push_back(Move(movebits));    
                    }
                }


            }

            

        }
        if (b.turn == BLACK){
            int curPieceNum = b.pieceNum[cur_piece];

            for (int i = 0 ; i < curPieceNum ; i++){
                int curSq = b.pieceList[cur_piece][i];

                for (int j = 0 ; j < numDir[cur_piece];j++){
                    int dir = pceDir[cur_piece][j];
                    int sqAfter = curSq + dir;

                    if (!checkInsideBoard(sqAfter)) continue;

                    if (b.pieces[sqAfter] == EMPTY){
                        U64 movebits = createMoveBits(curSq,sqAfter,0,0,0,0,0);
                        all_moves.push_back(Move(movebits));    
                    }
                    
                    if (getPieceColor(b.pieces[sqAfter]) == WHITE){
                        U64 movebits = createMoveBits(curSq,sqAfter,b.pieces[sqAfter],0,0,0,0);
                        all_moves.push_back(Move(movebits));    
                    }
                }


            }
        }
        

        pieceIndex++;
    }

    return all_moves;
}

std::vector<Move> Move::generateCastlingMoves(Board b){

    std::vector<Move> all_moves;

    int turn = b.turn;

    int wking_castle_flag = 1;
    int wqueen_castle_flag = 2;
    int bking_castle_flag = 4;
    int bqueen_castle_flag = 8;

    bool wking_castle = (b.castlingKey & wking_castle_flag) == wking_castle_flag;
    bool wqueen_castle = (b.castlingKey & wqueen_castle_flag) == wqueen_castle_flag;
    bool bking_castle = (b.castlingKey & bking_castle_flag) == bking_castle_flag;
    bool bqueen_castle = (b.castlingKey & bqueen_castle_flag) == bqueen_castle_flag;

    if (turn == WHITE){
        if (wking_castle){
            if (b.pieces[F1] == EMPTY && b.pieces[G1] == EMPTY){
        
                if(!b.squareAttacked(E1,WHITE) && !b.squareAttacked(F1,WHITE)){
                    U64 movebits = createMoveBits(E1,G1,0,0,0,0,1);
                    all_moves.push_back(Move(movebits)); 
                }
            }
        }
        if (wqueen_castle){
            if (b.pieces[D1] == EMPTY && b.pieces[C1] == EMPTY && b.pieces[B1] == EMPTY){
                if(!b.squareAttacked(E1,WHITE) && !b.squareAttacked(D1,WHITE)){
                    U64 movebits = createMoveBits(E1,C1,0,0,0,0,1);
                    all_moves.push_back(Move(movebits)); 
                }
            }
        }
    }
    else if (turn == BLACK){
        if (bking_castle){
            if (b.pieces[F8] == EMPTY && b.pieces[G8] == EMPTY){
                if(!b.squareAttacked(E8,BLACK) && !b.squareAttacked(F8,BLACK)){
                    U64 movebits = createMoveBits(E8,G8,0,0,0,0,1);
                    all_moves.push_back(Move(movebits)); 
                }
            }
        }
        if (bqueen_castle){
            if (b.pieces[D1] == EMPTY && b.pieces[C1] == EMPTY && b.pieces[B1] == EMPTY){
                if(!b.squareAttacked(E8,BLACK) && !b.squareAttacked(D8,BLACK)){
                    U64 movebits = createMoveBits(E8,C8,0,0,0,0,1);
                    all_moves.push_back(Move(movebits)); 
                }
            }
        }
    }
    
    return all_moves;
}

std::vector<Move> Move::generateAllMoves(Board b){
    std::vector<Move> all_moves;
    
    // generate pawn moves
    std::vector<Move> all_moves_pawns =  generatePawnMoves(b);
    all_moves.insert(all_moves.end(), all_moves_pawns.begin(), all_moves_pawns.end());

    // generate non loop pieces moves
    std::vector<Move> all_moves_non_loop =  generateNonLoopPieceMoves(b);
    all_moves.insert(all_moves.end(), all_moves_non_loop.begin(), all_moves_non_loop.end());

    // generate loop pieces moves
    std::vector<Move> all_moves_loop =  generateLoopPieceMoves(b);
    all_moves.insert(all_moves.end(), all_moves_loop.begin(), all_moves_loop.end());

    // generate pawn moves
    std::vector<Move> all_moves_castling =  generateCastlingMoves(b);
    all_moves.insert(all_moves.end(), all_moves_castling.begin(), all_moves_castling.end());

    return all_moves;
}

void Move::print(){

    int fromSq120 = fromSq();
    int toSq120 = toSq();
    int cap = captured();
    int enPas = enPassant();
    int pS = pawnStart();
    int prom = promoted();
    int cas = castle();

    // std::cout << "cast" << cas << '\n';
    std::string fromSqStr = sq64ToSqStr(Sq120_to_Sq64[fromSq120]);
    std::string toSqStr = sq64ToSqStr(Sq120_to_Sq64[toSq120]);

    char captured_piece = pieceToChar(cap);
    std::string caps = std::string(1, captured_piece);

    // std::string eP = std::string(1,enPas);
    // std::string pSStr = std::string(1,pS);

    char prom_piece = pieceToChar(prom);
    std::string promStr = std::string(1,prom_piece);

    // std::string casStr = std::string(1,cas);
    

    std::cout << "FromSq:" << fromSqStr << " toSqStr:" << toSqStr << " cap:" << caps << " eP:" << enPas << " pS:" << pS << " promStr:" << promStr << " casStr:" << cas ;
}