#pragma once

#include "defs.hpp"
#include "board.hpp"
#include "moves.hpp"
#include "makemove.hpp"
#include "helper.hpp"

void Perft(int depth, Board& b);
void PerftTest(int depth, Board& b);

void perft(int depth, std::string fen);
void perftUnitTest(int depth);