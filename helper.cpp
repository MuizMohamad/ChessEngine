
int getNthBitFromNumber(int num,int n){
    return (num >> (n-1)) & 1;
}