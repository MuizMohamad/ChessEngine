#pragma once

// get nth bit 1-based index
// and goes from left to right
// eg 100 , 1st bit is 0 , 2nd bit is 0 and 3rd bit is 1
int getNthBitFromNumber(int num,int n);

// set nth bit to 1 (1-based index)
int setNthBitFromNumber(int num,int n);

// set nth bit to 0 (1-based index)
int clearNthBitFromNumber(int num,int n);