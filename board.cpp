
#include "board.h"

Board::Board(){
    
    enPassantSquare = 0;
    turn = WHITE;

    fullMove = 0;
    halfMove = 0;

    // 1111 for castling
    castlingKey = 15;

    empty_board();
    
    init_pieces();
    
}

void Board::empty_board(){
    for (int i = 0 ; i < 13 ; i++){
        for (int j = 1 ; j <= 64 ; j++){
            pieceListInSq[i][j] = 0;
        }
    }
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

void Board::print_board(){

    std::cout << "--------\n";
    // print from up to down so start from rank 8 till rank 1
    for (int rank = RANK_8 ; rank >= RANK_1 ; rank--){
        std::string current_row = "--------";
        for (int file = FILE_A ; file <= FILE_H ; file++){
            int square = 8*(rank-1) + file;
            current_row[file-1] = pieceToChar(getPieceAtSquare(square));
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


void Board::parsingFEN(std::string fen){

    std::vector<std::string> fen_split = split_string(fen," ");

    assert (fen_split.size() == 6);
    std::string piecePosStr = fen_split.at(0);
    std::vector<std::string> each_lines = split_string(piecePosStr,"/");

    // empty board
    empty_board();
    int count = 0;
    for (int rank = RANK_8 ; rank >= RANK_1 ; rank--){
        
        std::string line = each_lines.at(8-rank);
        int line_size = line.size();

        int file = FILE_A;

        for (int i = 0 ; i < line_size ; i++){
            int square = 8*(rank-1) + file;
            if (isalpha(line[i])){
                int piece = charToPiece(line[i]);
                
                pieceListInSq[piece][square] = 1 ;
                file++;
            }
            else if (isdigit(line[i])){
                file += int(line[i]) - '0';
            }
        }
    }

    

    // parse current turn
    std::string turnFen = fen_split.at(1);
    if (turnFen == "w") turn = WHITE;
    else if (turnFen == "b") turn = BLACK;
    
    // parse castling status
    std::string castling_status = fen_split.at(2);

    // white can castle kingside
    if (castling_status.find('K') != std::string::npos){
        setNthBitFromNumber(&castlingKey,0);
    }
    else {
        clearNthBitFromNumber(&castlingKey,0);
    }

    // white can castle queenside
    if (castling_status.find('Q') != std::string::npos){
        setNthBitFromNumber(&castlingKey,1);
    }
    else {
        clearNthBitFromNumber(&castlingKey,1);
    }

    // black can castle kingside
    if (castling_status.find('k') != std::string::npos){
        setNthBitFromNumber(&castlingKey,2);
    }
    else {
        clearNthBitFromNumber(&castlingKey,2);
    }

    // black can castle queenside
    if (castling_status.find('K') != std::string::npos){
        setNthBitFromNumber(&castlingKey,3);
    }
    else {
        clearNthBitFromNumber(&castlingKey,4);
    }         

    // parse en passant
    std::string enPasStr = fen_split.at(3);

    if (enPasStr == "-"){
        enPassantSquare = 0;
    }
    else{
        enPassantSquare = sqStrToSq(enPasStr);
    }

    // parse half-move counter
    halfMove = std::stoi(fen_split[4]);

    // parse full-move
    fullMove = std::stoi(fen_split[5]);
}

// return
bool Board::squareAttacked(int square){

    // check diagonal for bishop / queen
    // check horizontal for bishop / queen
    // check l shape for knight
    // check one diagonal for pawn/king
    // check one horizontal for king
}
