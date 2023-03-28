#include "makemove.hpp"

void clearPiece(const int sq120, Board b){

    assert(checkInsideBoard(sq120));

    int piece = b.pieces[sq120];
    
    assert(checkPieceValid(piece));

    // color / side
    int color = getPieceColor(piece);
    
    int t_pieceNum = -1;

    // initially piece was included in the hash, so we hash again to clear it
    b.hash_piece(piece,sq120);

    b.pieces[sq120] = EMPTY;
    b.piecesInSq64[Sq120_to_Sq64[sq120]] = EMPTY;
    
    // reduce material value of the side
    b.materialValue[color] -= PieceValue[piece];

    // one of the square in pieceList should be equal to sq120 (pieceExits)
    for (int index = 0; index < b.pieceNum[piece]; ++index){
        if(b.pieceList[piece][index] == sq120){
            t_pieceNum = index;
            break;
        }
    }

    assert(t_pieceNum != -1);

    b.pieceNum[piece]--;

    // swap the cleared slot with the last piece in piece list
    // that's why we take value from b.pieceNum[piece], which is essentially last piece
    b.pieceList[piece][t_pieceNum] = b.pieceList[piece][b.pieceNum[piece]];
    b.pieceListInSq64[piece][t_pieceNum] = b.pieceListInSq64[piece][b.pieceNum[piece]];
}

// add piece at a sq120
void addPiece(const int sq120, int piece, Board b){

    assert(checkInsideBoard(sq120));
    assert(checkPieceValid(piece));

    int color = getPieceColor(piece);
    
    b.hash_piece(piece,sq120);

    b.pieces[sq120] = piece;
    b.piecesInSq64[Sq120_to_Sq64[sq120]] = piece;
    
    // add material value to the side
    b.materialValue[color] += PieceValue[piece];

    // set last piece in piecelist to be sq120
    b.pieceList[piece][b.pieceNum[piece]] = sq120;
    b.pieceListInSq64[piece][b.pieceNum[piece]] = Sq120_to_Sq64[sq120];
    
    // increase because we add a piece
    b.pieceNum[piece]++;
}

void movePiece(const int from, const int to, Board b){

    assert(checkInsideBoard(from));
    assert(checkInsideBoard(to));

    int piece = b.pieces[from];
    int piece_color = getPieceColor(piece);

    int piece_exist_from = false;

    // unhash the piece from the position key
    b.hash_piece(piece,from);
    b.pieces[from] = EMPTY;

    // hash the new piece location to the position key
    b.hash_piece(piece,to);
    b.pieces[to] = piece;

    for (int index = 0 ; index < b.pieceNum[piece]; ++index){
        if (b.pieceList[piece][index] == from){
            b.pieceList[piece][index] = to;
            piece_exist_from = true;
            break;
        }
    }

    assert(piece_exist_from);
}


int makeMove(Move move, Board b){
    
    int from = move.fromSq();
    int to = move.toSq();
    int side = b.turn;

    assert(checkInsideBoard(from));
    assert(checkInsideBoard(to));
    assert(checkValidSide(side));
    assert(checkPieceValid(b.pieces[from]));
    

    b.history[b.halfMoveHistory].position_key = b.position_key;

    // enPassant
    if (move.enPassant()){
        if (side == WHITE){
            clearPiece(to-10,b); // clear piece at behind (en passant)
        }
        else {
            clearPiece(to+10,b);
        }
    }
    else if (move.castle()){
        // destination must be one of these squares
        switch(to){
            // white castling
            case C1:
                movePiece(A1,D1,b);
            break;
            case C8:
                movePiece(A8,D8,b);
            break;
            // black castling
            case G1:
                movePiece(H1,F1,b); 
            break;
            case G8:
                movePiece(H8,F8,b);
            break;
            default : assert(false); break;
            
        }
    }

    if (b.enPassantSquare != NO_SQ) {
        b.hash_en_passant();
    }

    // hash out prev castling
    b.hash_castling_key();

    // update history
    b.history[b.halfMoveHistory].move_bits = move.getMoves();
    b.history[b.halfMoveHistory].fiftyMove = b.fiftyMove;
    b.history[b.halfMoveHistory].enPassantSquare = b.enPassantSquare;
    b.history[b.halfMoveHistory].castlingKey = b.castlingKey;

    // clear bit of castling permission
    b.castlingKey &= CastlePerm[from];
    b.castlingKey &= CastlePerm[to];
    b.enPassantSquare = NO_SQ;

    // hash in back
    b.hash_castling_key();

    // check if got capture
    int captured = move.captured();
    b.fiftyMove++;

    if (captured != EMPTY){
        assert(checkPieceValid(captured));
        clearPiece(to,b);
        b.fiftyMove = 0;
    }

    b.halfMoveHistory++;
    b.halfMove++;

    // set enpasssant squares
    int from_piece = b.pieces[from];

    if (from_piece == wP || from_piece == bP){
        b.fiftyMove = 0;
        if (move.pawnStart()){
            if (side == WHITE){
                b.enPassantSquare = from+10;
                assert(getRankFromSq120(b.enPassantSquare) == RANK_3);
            }
            else {
                b.enPassantSquare = from-10;
                assert(getRankFromSq120(b.enPassantSquare) == RANK_6);
            }
        }
    }

    // move piece
    movePiece(from,to, b);

    // add promoted piece
    int promotedPiece = move.promoted();

    if (promotedPiece != EMPTY){
        assert(checkPieceValid(promotedPiece) && promotedPiece != wP && promotedPiece != bP);
        clearPiece(to,b);
        addPiece(to, promotedPiece, b);
    }

    b.turn ^= 1;
    b.hash_side();

    if (b.squareAttacked(b.getKingSquare(side), b.turn)){
        takeMove(b);
        return false;
    }

    return true;

}

// Re-do moves (so reverse of makeMove)
void takeMove(Board b) {

    b.halfMoveHistory--;
    b.halfMove--;

    Move move = Move(b.history[b.halfMoveHistory].move_bits); // get last move
    int from = move.fromSq();
    int to = move.toSq();

    assert(checkInsideBoard(from));
    assert(checkInsideBoard(to));

    if (b.enPassantSquare != NO_SQ) {
        b.hash_en_passant();
    }
    b.hash_castling_key();

    b.turn ^= 1;
    b.hash_side();

    if (move.enPassant()){
        if (b.turn == WHITE){
            addPiece(to-10, bP, b);
        }
        else {
            addPiece(to+10, wP, b);
        }
    }
    else if (move.castle()){
        switch(to){
            // white castling
            case C1:
                movePiece(D1,A1,b);
            break;
            case C8:
                movePiece(D8,A8,b);
            break;
            // black castling
            case G1:
                movePiece(F1,H1,b); 
            break;
            case G8:
                movePiece(F8,H8,b);
            break;
            default : assert(false); break;
            
        }
    }

    movePiece(to, from, b);

    // check if got capture
    int captured = move.captured();

    if (captured != EMPTY){
        assert(checkPieceValid(captured));
        addPiece(to,captured,b);
    }

    // add promoted piece
    int promotedPiece = move.promoted();

    if (promotedPiece != EMPTY){
        assert(checkPieceValid(promotedPiece) && promotedPiece != wP && promotedPiece != bP);
        clearPiece(from,b);
        addPiece(from, getPieceColor(promotedPiece) == WHITE ? wP : bP, b);
    }

}