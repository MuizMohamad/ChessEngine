#pragma once

#include "defs.hpp"
#include "board.hpp"

void checkUp(); // check if time up, or if any interruptions from GUI

void clearForSearch(Board b, SearchInfo s);

int quiescence(int alpha, int beta, int depth, Board b, SearchInfo info);

int alphaBeta(int alpha, int beta, int depth, Board b, SearchInfo info, bool doNull);

void searchPosition(Board b, SearchInfo info);