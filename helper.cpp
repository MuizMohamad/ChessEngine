
#include "helper.h"

int getNthBitFromNumber(int num,int n){
    return (num >> (n-1)) & 1;
}

void setNthBitFromNumber(int* num,int n){
    *num |= 1UL << (n-1);
}

void clearNthBitFromNumber(int* num,int n){
    *num &= ~(1UL << (n-1));
}