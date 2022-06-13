
#include "defs.hpp"
#include "board.hpp"

// macros for Hashing
// where ^ is operator for XOR
#define HASH_PCE(pce,sq) 
#define HASH_CA 
#define HASH_SIDE 
#define HASH_EP 

U64 generatePositionKeys(Board b);

U64 hash_piece(Board b,int piece, int sq120);
U64 hash_castling_key(Board b);
U64 hash_side(Board b);
U64 hash_en_passant(Board b);