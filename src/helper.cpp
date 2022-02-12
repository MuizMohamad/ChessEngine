
#include "helper.hpp"

int getNthBitFromNumber(U64 num,int n){
    return (num >> (n-1)) & 1;
}


void setNthBitFromNumber(U64* num,int n){
    *num |= 1ULL << (n-1);
}

void clearNthBitFromNumber(U64* num,int n){
    *num &= ~(1ULL << (n-1));
}

char pieceToChar(int piece){
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
            return 'p';
            break;
        case bN:
            return 'n';
            break;
        case bB:
            return 'b';
            break;
        case bR:
            return 'r';
            break;
        case bQ:
            return 'q';
            break;
        case bK:
            return 'k';
            break;
        default:
            return ' ';
            break;

    };

}

int charToPiece(char ch){
    switch (ch){
        case 'P':
            return wP;
            break;
        case 'N':
            return wN;
            break;
        case 'B':
            return wB;
            break;
        case 'R':
            return wR;
            break;
        case 'Q':
            return wQ;
            break;
        case 'K':
            return wK;
            break;
        case 'p':
            return bP;
            break;
        case 'n':
            return bN;
            break;
        case 'b':
            return bB;
            break;
        case 'r':
            return bR;
            break;
        case 'q':
            return bQ;
            break;
        case 'k':
            return bK;
            break;
        default:
            return EMPTY;
            break;

    };

}

// credit to https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split_string(std::string str,std::string delimiter){
   
    std::vector<std::string> tokens;

    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        tokens.push_back(token);
    }
    // add last token 
    tokens.push_back(str);
    return tokens;
}

std::string sq64ToSqStr(int sq){

    int nth_rank = ceil(sq*1.0/8);
    int nth_file = sq - (8*(nth_rank-1));

    char file_char = 'a' + (nth_file- 1);
    char rank_char = '1' + (nth_rank - 1);
   
    std::string ans = "";

    ans.push_back(file_char);
    ans.push_back(rank_char);

    return ans;
}

int sqStrToSq64(std::string sq){
    int file = int(sq[0]) - 96;
    int rank = int(sq[1]) - 48;

    int square = 8*(rank-1) + file;
    return square;
}



int getPieceColor(int piece){

    if (piece >= wP && piece <= wK) return WHITE;
    else if (piece >= bP && piece <= bK) return BLACK;
    else return BOTH;

}

std::string combineFileRankStr(char file,char rank){
    return std::string(1,file) + std::string(1,rank);
}

int getRankFromSq120(int sq120){
    return floor(sq120/10) - 1;
}

/**
bool is_valid_fen(const std::string &fen) {
   std::istringstream iss(fen);
   std::string board, side, castleRights, ep;

   if (!iss) return false;

   iss >> board;

   if (!iss) return false;

   iss >> side;

   if (!iss) {
      castleRights = "-";
      ep = "-";
   } else {
      iss >> castleRights;
      if (iss)
         iss >> ep;
      else
         ep = "-";
   }

   // Let's check that all components of the supposed FEN are OK.
   if (side != "w" && side != "b") return false;
   if (castleRights != "-" && castleRights != "K" && castleRights != "Kk"
       && castleRights != "Kkq" && castleRights != "Kq" && castleRights !="KQ"
       && castleRights != "KQk" && castleRights != "KQq" && castleRights != "KQkq"
       && castleRights != "k" && castleRights != "q" && castleRights != "kq"
       && castleRights != "Q" && castleRights != "Qk" && castleRights != "Qq"
       && castleRights != "Qkq")
      return false;
   if (ep != "-") {
      if (ep.length() != 2) return false;
      if (!(ep[0] >= 'a' && ep[0] <= 'h')) return false;
      if (!((side == "w" && ep[1] == '6') || (side == "b" && ep[1] == '3')))
         return false;
   }

   // The tricky part: The board.
   // Seven slashes?
   if (std::count(board.begin(), board.end(), '/') != 7) return false;
   // Only legal characters?
   for (int i = 0; i < board.length(); i++)
      if (!(board[i] == '/' || (board[i] >= '1' && board[i] <= '8')
            || piece_type_is_ok(piece_type_from_char(board[i]))))
         return false;
   // Exactly one king per side?
   if (std::count(board.begin(), board.end(), 'K') != 1) return false;
   if (std::count(board.begin(), board.end(), 'k') != 1) return false;
   // Other piece counts reasonable?
   size_t wp = std::count(board.begin(), board.end(), 'P'),
      bp = std::count(board.begin(), board.end(), 'p'),
      wn = std::count(board.begin(), board.end(), 'N'),
      bn = std::count(board.begin(), board.end(), 'n'),
      wb = std::count(board.begin(), board.end(), 'B'),
      bb = std::count(board.begin(), board.end(), 'b'),
      wr = std::count(board.begin(), board.end(), 'R'),
      br = std::count(board.begin(), board.end(), 'r'),
      wq = std::count(board.begin(), board.end(), 'Q'),
      bq = std::count(board.begin(), board.end(), 'q');
   if (wp > 8 || bp > 8 || wn > 10 || bn > 10 || wb > 10 || bb > 10
       || wr > 10 || br > 10 || wq > 9 || bq > 10
       || wp + wn + wb + wr + wq > 15 || bp + bn + bb + br + bq > 15)
      return false;

   // OK, looks close enough to a legal position. Let's try to parse
   // the FEN and see!
   Position p;
   p.from_fen(board + " " + side + " " + castleRights + " " + ep);
   return p.is_ok(true);
}
*/