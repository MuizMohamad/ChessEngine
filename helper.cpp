
#include "helper.h"

int getNthBitFromNumber(U64 num,int n){
    return (num >> (n-1)) & 1;
}

void setNthBitFromNumber(U64* num,int n){
    *num |= 1ULL << (n-1);
}

void clearNthBitFromNumber(U64* num,int n){
    *num &= ~(1ULL << (n-1));
}