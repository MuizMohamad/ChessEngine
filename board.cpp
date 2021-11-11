
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

    // initiate empty space
    for (int i = A3 ; i <= H6 ; i++ ){
        pieceListInSq[0][i] = 1;
    }

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

// check based on the current turn,
// that is if E4 with turn white, then check if black pieces attack the square
bool Board::squareAttacked(int square){

    int piece_color = turn;
    
    // check diagonal for bishop / queen
    std::vector<int> diagonal_squares = getAllDiagonalSq(square);

    std::vector<int> opp_bishop_queen = {bB,bQ};
    if (piece_color == BLACK) opp_bishop_queen = {wB,wQ};

    for (int d_sq : diagonal_squares){
        
        int opp_bishop = opp_bishop_queen.at(0);
        int opp_queen = opp_bishop_queen.at(1);

        if (pieceListInSq[opp_bishop][d_sq] == 1){
            std::cout << "Bishop attack" << "\n";
            return true;
        }
        if (pieceListInSq[opp_queen][d_sq] == 1){
            std::cout << "Queen attack" << "\n";
            return true;
        }

    }
    
    // check horizontal for rook / queen
    std::vector<int> horizontal_squares = getAllHorizontalSq(square);

    std::vector<int> opp_rook_queen = {bR,bQ};
    if (piece_color == BLACK) opp_rook_queen = {wR,wQ};

    for (int h_sq : horizontal_squares){
        
        int opp_rook = opp_rook_queen.at(0);
        int opp_queen = opp_rook_queen.at(1);

        if (pieceListInSq[opp_rook][h_sq] == 1){
            std::cout << "Rook attack" << "\n";
            return true;
        }
        if (pieceListInSq[opp_queen][h_sq] == 1){
            std::cout << "Queen attack" << "\n";
            return true;
        }

    }

   
    // check l shape for knight
    std::vector<int> knight_attack_sq = getKnightSqAround(square);

    int opp_knight = bN;
    if (piece_color == BLACK) opp_knight = wN;

    for (int n_sq : knight_attack_sq){
        
        if (pieceListInSq[opp_knight][n_sq] == 1){
            std::cout << "Knight attack" << "\n";
            return true;
        }
    }

    // check for pawn attack 
    std::vector<int> pawn_attack_sq = getOppPawnAttackSq(square,piece_color);

    int opp_pawn = bP;
    if (piece_color == BLACK) opp_pawn = wP;

    for (int p_sq : pawn_attack_sq){
        
        if (pieceListInSq[opp_pawn][p_sq] == 1){
            std::cout << "Pawn attack" << "\n";
            return true;
        }
    }

    // check for king attack
    std::vector<int> king_attack_sq = getAllSquareAround(square);

    int opp_king = bK;
    if (piece_color == BLACK) opp_king = wK;

    for (int k_sq : king_attack_sq){
        
        if (pieceListInSq[opp_king][k_sq] == 1){
            std::cout << "King attack" << "\n";
            return true;
        }
    }
    
     return false;
}

