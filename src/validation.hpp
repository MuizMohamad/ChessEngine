#pragma once

#include "defs.hpp"
#include "helper.hpp"

bool checkInsideBoard(std::string sq);
bool checkInsideBoard(int sq);

bool checkValidSide(int side);
bool checkValidFileRank(int fr);
bool checkPieceValidEmpty(int piece);
bool checkPieceValid(int piece);

//TODO add validate FEN string