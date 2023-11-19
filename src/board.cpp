
#include "board.hpp"

Board::Board(){
    
    enPassantSquare = 0;
    turn = WHITE;

    fullMove = 0;
    halfMove = 0;

    // 1111 for castling
    castlingKey = 15;

    fiftyMove = 0;

    empty_board();
    init_pieces();

}

void Board::resetListValues(){

    for (int i = 0 ; i < 2 ; i ++){
        materialValue[i] = 0;
    }
}
void Board::empty_board(){

    // empty piece list
    for (int i = 0 ; i < 13 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            pieceList[i][j] = NO_SQ;
            pieceListInSq64[i][j] = NO_SQ;
        }
    }

    // empty pieces 120 squares
    for (int i = 0 ; i < 120 ; i++){
        pieces[i] = EMPTY;
    }

    // empty piecesInSq
    for (int i = 0 ; i <= 65 ; i++){
        piecesInSq64[i] = EMPTY;
    }

    // empty piece Num
    for (int i = 0 ; i < 13 ; i++){
        pieceNum[i] = 0;
    }
}

void Board::init_pieces(){

    empty_board();

    // initiate pawns
    for (int i = 0 ; i < 8 ; i++){

        pieceList[wP][i] = wPawnStart[i];
        pieceList[bP][i] = bPawnStart[i];

        pieceListInSq64[wP][i] = Sq120_to_Sq64[wPawnStart[i]];
        pieceListInSq64[bP][i] = Sq120_to_Sq64[bPawnStart[i]];

        pieces[wPawnStart[i]] = wP;
        pieces[bPawnStart[i]] = bP;
        if (wPawnStart[i] == 53 || bPawnStart[i] == 53) std::cout << "ayam paw" << "\n";
        piecesInSq64[Sq120_to_Sq64[wPawnStart[i]]] = wP;
        piecesInSq64[Sq120_to_Sq64[bPawnStart[i]]] = bP;

        pieceNum[wP] += 1;
        pieceNum[bP] += 1;
    }
    
    

    // initiate knight
    for (int i = 0 ; i < 2 ; i++){

        pieceList[wN][i] = wKnightStart[i];
        pieceList[bN][i] = bKnightStart[i];
        
        pieceListInSq64[wN][i] = Sq120_to_Sq64[wKnightStart[i]];
        pieceListInSq64[bN][i] = Sq120_to_Sq64[bKnightStart[i]];

        pieces[wKnightStart[i]] = wN;
        pieces[bKnightStart[i]] = bN;

        piecesInSq64[Sq120_to_Sq64[wKnightStart[i]]] = wN;
        piecesInSq64[Sq120_to_Sq64[bKnightStart[i]]] = bN;

        pieceNum[wN] += 1;
        pieceNum[bN] += 1;
    }

    
    // initiate bishop
    for (int i = 0 ; i < 2 ; i++){

        pieceList[wB][i] = wBishopStart[i];
        pieceList[bB][i] = bBishopStart[i];

        pieceListInSq64[wB][i] = Sq120_to_Sq64[wBishopStart[i]];
        pieceListInSq64[bB][i] = Sq120_to_Sq64[bBishopStart[i]];

        pieces[wBishopStart[i]] = wB;
        pieces[bBishopStart[i]] = bB;
        if (wBishopStart[i] == 53 || bBishopStart[i] == 53) std::cout << "ayam bis" << "\n";
        piecesInSq64[Sq120_to_Sq64[wBishopStart[i]]] = wB;
        piecesInSq64[Sq120_to_Sq64[bBishopStart[i]]] = bB;

        pieceNum[wB] += 1;
        pieceNum[bB] += 1;
    }

    // initiate rook
    for (int i = 0 ; i < 2 ; i++){

        pieceList[wR][i] = wRookStart[i];
        pieceList[bR][i] = bRookStart[i];

        pieceListInSq64[wR][i] = Sq120_to_Sq64[wRookStart[i]];
        pieceListInSq64[bR][i] = Sq120_to_Sq64[bRookStart[i]];

        pieces[wRookStart[i]] = wR;
        pieces[bRookStart[i]] = bR;
        if (wRookStart[i] == 53 || bRookStart[i] == 53) std::cout << "ayam rok" << "\n";
        piecesInSq64[Sq120_to_Sq64[wRookStart[i]]] = wR;
        piecesInSq64[Sq120_to_Sq64[bRookStart[i]]] = bR;

        pieceNum[wR] += 1;
        pieceNum[bR] += 1;
    }

    

    // initiate queen
    for (int i = 0 ; i < 1 ; i++){

        pieceList[wQ][i] = wQueenStart[i];
        pieceList[bQ][i] = bQueenStart[i];

        pieceListInSq64[wQ][i] = Sq120_to_Sq64[wQueenStart[i]];
        pieceListInSq64[bQ][i] = Sq120_to_Sq64[bQueenStart[i]];

        pieces[wQueenStart[i]] = wQ;
        pieces[bQueenStart[i]] = bQ;
        
        piecesInSq64[Sq120_to_Sq64[wQueenStart[i]]] = wQ;
        piecesInSq64[Sq120_to_Sq64[bQueenStart[i]]] = bQ;

        pieceNum[wQ] += 1;
        pieceNum[bQ] += 1;
    }

    

    // initiate king
    for (int i = 0 ; i < 1 ; i++){

        pieceList[wK][i] = wKingStart[i];
        pieceList[bK][i] = bKingStart[i];

        pieceListInSq64[wK][i] = Sq120_to_Sq64[wKingStart[i]];
        pieceListInSq64[bK][i] = Sq120_to_Sq64[bKingStart[i]];

        pieces[wKingStart[i]] = wK;
        pieces[bKingStart[i]] = bK;
        
        piecesInSq64[Sq120_to_Sq64[wKingStart[i]]] = wK;
        piecesInSq64[Sq120_to_Sq64[bKingStart[i]]] = bK;

        pieceNum[wK] += 1;
        pieceNum[bK] += 1;
    }

    // char pieceChar1 = pieceToChar(getPieceAtSq64(43));
    // std::cout << pieceChar1 << "\n";
    this->updateListsMaterial();
    
}

// debugging purposes
void Board::printCharPieceAtSq64(int sq64){
    char pieceChar1 = pieceToChar(getPieceAtSq64(sq64));
    std::cout << "CharPiece: " << pieceChar1 << "\n";
}

void Board::printCharPieceAtSq120(int sq120){

    int sq64 = Sq120_to_Sq64[sq120];
    char pieceChar1 = pieceToChar(getPieceAtSq64(sq64));
    std::cout << "CharPiece: " << pieceChar1 << "\n";
}

void Board::print_board(){

    std::cout << "--------\n";
    // print from up to down so start from rank 8 till rank 1
    for (int rank = RANK_8 ; rank >= RANK_1 ; rank--){
        std::string current_row = "--------";
        for (int file = FILE_A ; file <= FILE_H ; file++){
            int sq = 8*(rank-1) + file;
            char pieceChar = pieceToChar(getPieceAtSq64(sq));
            //if (pieceChar == 'N') std::cout << "(s:" << sq64 << ")\n";
            current_row[file-1] = pieceChar;
        }

        std::cout << current_row << "\n";
    }
    std::cout << "--------\n";
}

// get square 120 of king with side
int Board::getKingSquare(int side){
    if (side == WHITE){
        return this->pieceList[wK][0];
    }
    else {
        return this->pieceList[bK][0];
    }
}

int Board::getPieceAtSq64(int sq64){

    //return piecesInSq64[square];
    return pieces[Sq64_to_Sq120[sq64]];
}


void Board::parseFEN(std::string fen){

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
                int piece_number = pieceNum[piece];
                
                pieceListInSq64[piece][piece_number] = sq64 ;
                piecesInSq64[sq64] = piece;

                int sq120 = Sq64_to_Sq120[sq64];
                pieceList[piece][piece_number] = sq120 ;
                pieces[sq120] = piece;

                file++;
                pieceNum[piece]++;
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
        setNthBitFromNumber(&castlingKey,1);
    }
    else {
        clearNthBitFromNumber(&castlingKey,1);
    }

    // white can castle queenside
    if (castling_status.find('Q') != std::string::npos){
        setNthBitFromNumber(&castlingKey,2);
    }
    else {
        clearNthBitFromNumber(&castlingKey,2);
    }

    // black can castle kingside
    if (castling_status.find('k') != std::string::npos){
        setNthBitFromNumber(&castlingKey,3);
    }
    else {
        clearNthBitFromNumber(&castlingKey,3);
    }

    // black can castle queenside
    if (castling_status.find('K') != std::string::npos){
        setNthBitFromNumber(&castlingKey,4);
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
        enPassantSquare = Sq64_to_Sq120[sqStrToSq64(enPasStr)];
    }

    // parse half-move counter
    halfMove = std::stoi(fen_split[4]);

    // parse full-move
    fullMove = std::stoi(fen_split[5]);

    position_key = Board::generatePositionKeys(*this);

    // update list materials
    updateListsMaterial();
}



// check based on the defending side,
// that is if E4 with defending side white, then check if black piece attack the square E4
// square 120

bool Board::squareAttacked(int sq120, int defending_side){

    assert (checkInsideBoard(sq120));
    assert (checkValidSide(defending_side));

    int piece_color = defending_side;

    // check diagonal for bishop / queen

    std::vector<int> opp_bishop_queen = {bB,bQ};
    if (piece_color == BLACK) opp_bishop_queen = {wB,wQ};

    int opp_bishop = opp_bishop_queen.at(0);
    int opp_queen = opp_bishop_queen.at(1);

    for (int direction : diagonal_direction){
        
        int cur_sq = sq120;

        while(checkInsideBoard(cur_sq + direction) && pieces[cur_sq+direction] == EMPTY){
            cur_sq = cur_sq + direction;
        }
        
        if (checkInsideBoard(cur_sq + direction) && pieces[cur_sq+direction] != EMPTY){
            cur_sq = cur_sq + direction;
        }

        bool queen_or_bishop = (pieces[cur_sq] == opp_bishop || pieces[cur_sq] == opp_queen);
        if (checkInsideBoard(cur_sq) && queen_or_bishop) return true;
    }
    
    // check horizontal for rook / queen
    std::vector<int> opp_rook_queen = {bR,bQ};
    if (piece_color == BLACK) opp_rook_queen = {wR,wQ};

    int opp_rook = opp_rook_queen.at(0);

    for (int direction : horizontal_direction){
        
        int cur_sq = sq120;



        while(checkInsideBoard(cur_sq + direction) && pieces[cur_sq+direction] == EMPTY){
            cur_sq = cur_sq + direction;
        }

        if (checkInsideBoard(cur_sq + direction) && pieces[cur_sq+direction] != EMPTY){
            cur_sq = cur_sq + direction;
        }

        bool queen_or_bishop = (pieces[cur_sq] == opp_rook || pieces[cur_sq] == opp_queen);
        if (checkInsideBoard(cur_sq) && queen_or_bishop) return true;
    }

   
    // check l shape for knight
    int opp_knight = bN;
    if (piece_color == BLACK) opp_knight = wN;

    for (int direction : knight_direction){
        int new_sq120 = sq120 + direction;
        if (checkInsideBoard(new_sq120)){
            if (pieces[new_sq120] == opp_knight){
                return true;
            }
        }
    }

    // check for pawn attack 
    int opp_pawn = bP;
    if (piece_color == BLACK) opp_pawn = wP;

    std::array<int,2> correct_direction = b_pawn_atk_direction;
    if (defending_side == BLACK) correct_direction = w_pawn_atk_direction;

    for (int direction : correct_direction){
        int new_sq120 = sq120 + direction;
        if (checkInsideBoard(new_sq120)){
            if (pieces[new_sq120] == opp_pawn){
                return true;
            }
        }
    }

    // check for king attack
   
    int opp_king = bK;
    if (piece_color == BLACK) {
        opp_king = wK;
    } 

    for (int direction : king_direction){
        int new_sq120 = sq120 + direction;
        if (checkInsideBoard(new_sq120)){
            if (pieces[new_sq120] == opp_king){
                return true;
            }
        }
    }
    
     return false;
}


void Board::updateListsMaterial() {	
	
	int piece,sq,index,colour;
	
	for(index = 0; index < BOARD_SQ_NUM; ++index) {
		sq = index;
		piece = pieces[index];
		if(piece!= EMPTY) {

			colour = getPieceColor(piece);

            // this variables are not added yet
		    // if( PieceBig[piece] == TRUE) pos->bigPce[colour]++;
		    // if( PieceMin[piece] == TRUE) pos->minPce[colour]++;
		    // if( PieceMaj[piece] == TRUE) pos->majPce[colour]++;
			
			materialValue[colour] += PieceValue[piece];
		}
	}
}

void Board::hash_piece(int piece, int sq120){
    (this->position_key ^= (PieceKeys[piece][sq120]));
}

void Board::hash_castling_key(){
    (this->position_key ^= (CastleKeys[(this->castlingKey)]));
}

void Board::hash_side(){
    (this->position_key ^= (SideKey));
}
void Board::hash_en_passant(){
    (this->position_key ^= (PieceKeys[EMPTY][(this->enPassantSquare)]));
}

U64 Board::generatePositionKeys(Board b) {

	int sq = 0;
	U64 finalKey = 0;
	int piece = EMPTY;
	
	// pieces
	for(sq = 0; sq < BOARD_SQ_NUM; ++sq) {
		piece = b.pieces[sq];
		if(piece!=NO_SQ && piece!=EMPTY) {
			assert(piece>=wP && piece<=bK);
			finalKey ^= PieceKeys[piece][sq];
		}		
	}
	
	if(b.turn == WHITE) {
		finalKey ^= SideKey;
	}
		
	if(b.enPassantSquare != NO_SQ) {
		assert(b.enPassantSquare>=0 && b.enPassantSquare<BOARD_SQ_NUM);
		finalKey ^= PieceKeys[EMPTY][b.enPassantSquare];
	}
	
    std::cout << b.castlingKey << "\n";

	assert(b.castlingKey>=0 && b.castlingKey<=15);
	
	finalKey ^= CastleKeys[b.castlingKey];
	
	return finalKey;
}



