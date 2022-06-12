#include "makemove.hpp"

void ClearPiece(const int sq120, Board b){

    assert(checkInsideBoard(sq120));

    int piece = b.pieces[sq120];

    assert(checkPieceValid(piece));

    int color = getPieceColor(piece);
    
    int t_pieceNum = -1;

    b.position_key = un_hash_pieces(b,piece,sq120);

    b.pieces[sq120] = EMPTY;
    b.piecesInSq64[Sq120_to_Sq64[sq120]] = EMPTY;
    
    // one of the square in pieceList should be equal to sq120 (pieceExits)
    for (int index = 0; index < b.pieceNum[piece]; ++index){
        if(b.pieceList[piece][index] == sq120){
            t_pieceNum = index;
            break;
        }
    }

    assert(t_pieceNum != -1);

    b.pieceNum[piece]--;
    b.pieceList[piece][t_pieceNum] = b.pieceList[piece][b.pieceNum[piece]];
    b.pieceListInSq64[piece][t_pieceNum] = b.pieceListInSq64[piece][b.pieceNum[piece]];
}