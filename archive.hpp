#pragma once

#include "defs.h"

// old functions that are replaced with something else
std::vector<int> getRightDiagonalSq(int sq);
std::vector<int> getLeftDiagonalSq(int sq);
std::vector<int> getAllDiagonalSq(int sq);

std::vector<int> getUpDownHorizontalSq(int sq);
std::vector<int> getLeftRightHorizontalSq(int sq);
std::vector<int> getAllHorizontalSq(int sq);

std::vector<int> getAllSquareAround(int sq);
std::vector<int> getOppPawnAttackSq(int sq,int color);
std::vector<int> getKnightSqAround(int sq);