
#pragma once
// Typedef for short form
typedef unsigned long long  U64;


// enum
enum { EMPTY, wP , wN , wB , wR , wQ , wK , bP , bN , bB , bR , bQ , bK }
enum { NONE, FILE_A , FILE_B , FILE_C , FILE_D , FILE_E , FILE_F , FILE_G , FILE_H  }
enum { NONE, RANK_1 , RANK_2 , RANK_3 , RANK_4 , RANK_5 , RANK_6 , RANK_7 , RANK_8  }
enum { WHITE , BLACK , BOTH }
enum { FALSE , TRUE}

enum {
    A1 = 1 , A2 , A3 , A4 , A5 , A6 , A7, A8 ,
    B1 = 9 , B2 , B3 , B4 , B5 , B6 , B7, B8 ,
    C1 = 17, C2 , C3 , C4 , C5 , C6 , C7, C8 ,
    D1 = 25, D2 , D3 , D4 , D5 , D6 , D7, D8 ,
    E1 = 33 , E2 , E3 , E4 , E5 , E6 , E7, E8 ,
    F1 = 41 , F2 , F3 , F4 , F5 , F6 , F7, F8 ,
    G1 = 49 , G2 , G3 , G4 , G5 , G6 , G7, G8 ,
    H1 = 57 , H2 , H3 , H4 , H5 , H6 , H7, H8 ,
}

// Put each piece location as bits
// where first bit is a1 ... 2nd is b1 ... 9th bit is a2






