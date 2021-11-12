
#pragma once

#include "defs.hpp"

// get nth bit 1-based index
// and goes from left to right
// eg 100 , 1st bit is 0 , 2nd bit is 0 and 3rd bit is 1
int getNthBitFromNumber(U64 num,int n);
// set nth bit to 1 (1-based index)
void setNthBitFromNumber(U64* num,int n);
// set nth bit to 0 (1-based index)
void clearNthBitFromNumber(U64* num,int n);

char pieceToChar(int piece);
int charToPiece(char ch);
std::vector<std::string> split_string(std::string fen,std::string delimiter);

std::string sq64ToSqStr(int sq);
int sqStrToSq64(std::string sq);

bool checkInsideBoard(std::string sq);
bool checkInsideBoard(int sq);

int getPieceColor(int piece);
std::string combineFileRankStr(char file,char rank);

