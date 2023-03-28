#pragma once

#include "board.hpp"
#include "moves.hpp"
#include "makemove.hpp"

void Perft(int depth, Board& b);
void PerftTest(int depth, Board& b);