
#include "init.h"

void InitSq120To64(){

	int index = 0;
	int file = FILE_A;
	int rank = RANK_1;
	int sq = A1;
	int sq64 = 0;
	for(index = 0; index < BOARD_SQ_NUM; ++index) {
		Sq120_to_Sq64[index] = 65;
	}
	
	for(index = 0; index < 64; ++index) {
		Sq64_to_Sq120[index] = 120;
	}
	
	for(rank = RANK_1; rank <= RANK_8; ++rank) {
		for(file = FILE_A; file <= FILE_H; ++file) {
			sq = 21*file + 10*rank;
			Sq64_to_Sq120[sq64] = sq;
			Sq120_to_Sq64[sq] = sq64;
			sq64++;
		}
	}
}