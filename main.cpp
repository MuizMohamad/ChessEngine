#include <iostream>
#include "helper.h"


using namespace std;

int main(){

    for (int i = 9 ; i >= 1 ; i--){
        int nthbit = getNthBitFromNumber(361,i);
        cout << nthbit;
    }
   
    return 0;
}