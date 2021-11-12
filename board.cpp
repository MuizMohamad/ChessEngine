
#include "board.hpp"

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
            pieceListInSq64[i][j] = 0;
        }
    }

    for (int i = 0 ; i <= 65 ; i++){
        piecesInSq64[i] = EMPTY;
    }
}

void Board::init_pieces(){

    // initiate empty space
    for (int i = A3 ; i <= H6 ; i++ ){
        pieceListInSq64[0][i] = 1;
    }

    // initiate pawns
    for (int i = 0 ; i < 8 ; i++){
        pieceListInSq64[wP][Sq120_to_Sq64[wPawnStart[i]]] = 1;
        pieceListInSq64[bP][Sq120_to_Sq64[bPawnStart[i]]] = 1;

        piecesInSq64[Sq120_to_Sq64[wPawnStart[i]]] = wP;
        piecesInSq64[Sq120_to_Sq64[bPawnStart[i]]] = bP;
    }
 
    // initiate knight
    for (int i = 0 ; i < 2 ; i++){

        pieceListInSq64[wN][Sq120_to_Sq64[wKnightStart[i]]] = 1;
        pieceListInSq64[bN][Sq120_to_Sq64[bKnightStart[i]]] = 1;

        piecesInSq64[Sq120_to_Sq64[wKnightStart[i]]] = wN;
        piecesInSq64[Sq120_to_Sq64[bKnightStart[i]]] = bN;

    }

    // initiate bishop
    for (int i = 0 ; i < 2 ; i++){
        pieceListInSq64[wB][Sq120_to_Sq64[wBishopStart[i]]] = 1;
        pieceListInSq64[bB][Sq120_to_Sq64[bBishopStart[i]]] = 1;

        piecesInSq64[Sq120_to_Sq64[wBishopStart[i]]] = wB;
        piecesInSq64[Sq120_to_Sq64[bBishopStart[i]]] = bB;
    }

    // initiate rook
    for (int i = 0 ; i < 2 ; i++){
        pieceListInSq64[wR][Sq120_to_Sq64[wRookStart[i]]] = 1;
        pieceListInSq64[bR][Sq120_to_Sq64[bRookStart[i]]] = 1;

        piecesInSq64[Sq120_to_Sq64[wRookStart[i]]] = wR;
        piecesInSq64[Sq120_to_Sq64[bRookStart[i]]] = bR;
    }

    // initiate queen
    for (int i = 0 ; i < 1 ; i++){
        pieceListInSq64[wQ][Sq120_to_Sq64[wQueenStart[i]]] = 1;
        pieceListInSq64[bQ][Sq120_to_Sq64[bQueenStart[i]]] = 1;

        piecesInSq64[Sq120_to_Sq64[wQueenStart[i]]] = wQ;
        piecesInSq64[Sq120_to_Sq64[bQueenStart[i]]] = bQ;
    }

    // initiate king
    for (int i = 0 ; i < 1 ; i++){
        pieceListInSq64[wK][Sq120_to_Sq64[wKingStart[i]]] = 1;
        pieceListInSq64[bK][Sq120_to_Sq64[bKingStart[i]]] = 1;

        piecesInSq64[Sq120_to_Sq64[wKingStart[i]]] = wK;
        piecesInSq64[Sq120_to_Sq64[bKingStart[i]]] = bK;
    }
}

void Board::print_board(){

    std::cout << "--------\n";
    // print from up to down so start from rank 8 till rank 1
    for (int rank = RANK_8 ; rank >= RANK_1 ; rank--){
        std::string current_row = "--------";
        for (int file = FILE_A ; file <= FILE_H ; file++){
            int square = 8*(rank-1) + file;
            current_row[file-1] = pieceToChar(getPieceAtSq64(square));
        }

        std::cout << current_row << "\n";
    }
    std::cout << "--------\n";
}

int Board::getPieceAtSq64(int square){

    return piecesInSq64[square];
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
            int sq64 = 8*(rank-1) + file;
            if (isalpha(line[i])){
                int piece = charToPiece(line[i]);
                
                pieceListInSq64[piece][sq64] = 1 ;
                piecesInSq64[sq64] = piece;
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
        enPassantSquare = sqStrToSq64(enPasStr);
    }

    // parse half-move counter
    halfMove = std::stoi(fen_split[4]);

    // parse full-move
    fullMove = std::stoi(fen_split[5]);
}

// check based on the defending side,
// that is if E4 with defending side white, then check if black piece attack the square E4
bool Board::squareAttacked(int square, int defending_side){

    int piece_color = defending_side;

    // check diagonal for bishop / queen

    std::vector<int> opp_bishop_queen = {bB,bQ};
    if (piece_color == BLACK) opp_bishop_queen = {wB,wQ};

    int opp_bishop = opp_bishop_queen.at(0);
    int opp_queen = opp_bishop_queen.at(1);

    for (int direction : diagonal_direction){
        
        int cur_sq = square;
        while(piecesInSq64[cur_sq+direction] != EMPTY && checkInsideBoard(cur_sq + direction)){
            cur_sq = cur_sq + direction;
        }

        bool queen_or_bishop = piecesInSq64[cur_sq] == opp_bishop || piecesInSq64[cur_sq] == opp_queen;
        if (checkInsideBoard(cur_sq) && queen_or_bishop) return true;
    }
    
    // check horizontal for rook / queen
    std::vector<int> opp_rook_queen = {bR,bQ};
    if (piece_color == BLACK) opp_rook_queen = {wR,wQ};

    int opp_rook = opp_rook_queen.at(0);

     for (int direction : horizontal_direction){
        
        int cur_sq = square;
        while(piecesInSq64[cur_sq+direction] != EMPTY && checkInsideBoard(cur_sq + direction)){
            cur_sq = cur_sq + direction;
        }

        bool queen_or_bishop = piecesInSq64[cur_sq] == opp_rook || piecesInSq64[cur_sq] == opp_queen;
        if (checkInsideBoard(cur_sq) && queen_or_bishop) return true;
    }

   
    // check l shape for knight
    int opp_knight = bN;
    if (piece_color == BLACK) opp_knight = wN;

    for (int direction : knight_direction){
        int new_sq120 = square + direction;
        int new_sq64 = Sq120_to_Sq64[new_sq120];
        if (checkInsideBoard(new_sq120)){
            if (piecesInSq64[new_sq64] == opp_knight){
                std::cout << "Knight attack" << "\n";
                return true;
            }
        }
    }

    // check for pawn attack 
    int opp_pawn = bP;
    if (piece_color == BLACK) opp_pawn = wP;

    std::array<int,2> correct_direction = b_pawn_atk_direction;
    if (defending_side = BLACK) correct_direction = w_pawn_atk_direction;

    for (int direction : correct_direction){
        int new_sq120 = square + direction;
        int new_sq64 = Sq120_to_Sq64[new_sq120];
        if (checkInsideBoard(new_sq120)){
            if (piecesInSq64[new_sq64] == opp_pawn){
                std::cout << "Pawn attack" << "\n";
                return true;
            }
        }
    }

    // check for king attack
   
    int opp_king = bK;
    if (piece_color == BLACK) opp_king = wK;

    for (int direction : king_direction){
        int new_sq120 = square + direction;
        int new_sq64 = Sq120_to_Sq64[new_sq120];
        if (checkInsideBoard(new_sq120)){
            if (piecesInSq64[new_sq64] == opp_king){
                std::cout << "King attack" << "\n";
                return true;
            }
        }
    }
    
     return false;
}

