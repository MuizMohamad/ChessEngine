
#pragma once

#include "defs.h"

// get nth bit 1-based index
// and goes from left to right
// eg 100 , 1st bit is 0 , 2nd bit is 0 and 3rd bit is 1
int getNthBitFromNumber(U64 num,int n);

// set nth bit to 1 (1-based index)
void setNthBitFromNumber(U64* num,int n);

// set nth bit to 0 (1-based index)
void clearNthBitFromNumber(U64* num,int n);