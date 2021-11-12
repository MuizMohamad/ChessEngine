
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

bool checkInsideBoard(std::string sq){

    char file = sq[0];
    char rank = sq[1];

    bool checkFile = int(file) >= 'a' && int(file) <= 'h';
    bool checkRank = int(rank) >= '1' && int(rank) <= '8';

    return checkFile && checkRank;
}

bool checkInsideBoard(int sq){
    int sq64 = Sq120_to_Sq64[sq];
    return checkInsideBoard(sq64ToSqStr(sq64));
}

int getPieceColor(int piece){

    if (piece >= wP and piece <= wK) return WHITE;
    else if (piece >= bP and piece <= bK) return BLACK;
    else return BOTH;

}

std::string combineFileRankStr(char file,char rank){
    return std::string(1,file) + std::string(1,rank);
}