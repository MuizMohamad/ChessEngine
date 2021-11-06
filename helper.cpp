
int getNthBitFromNumber(int num,int n){
    return (num >> (n-1)) & 1;
}

int setNthBitFromNumber(int num,int n){
    num |= 1UL << (n-1);
    return num;
}

int clearNthBitFromNumber(int num,int n){
    num &= ~(1UL << (n-1));
    return num;
}