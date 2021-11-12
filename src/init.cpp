
#include "init.hpp"

// extern variables needs have to have one .cpp file that defines it
std::array<int,BOARD_SQ_NUM+1> Sq120_to_Sq64;
std::array<int,65> Sq64_to_Sq120;

void InitSq120To64(){

	int index = 0;
	int file = FILE_A;
	int rank = RANK_1;
	int sq120 = A1;
	int sq64 = 1;

	for(index = 0; index <= BOARD_SQ_NUM; ++index) {
		Sq120_to_Sq64[index] = 0;
	}
	
	for(index = 0; index <= 64; ++index) {
		Sq64_to_Sq120[index] = 120;
	}
	
	for(rank = RANK_1; rank <= RANK_8; ++rank) {
		for(file = FILE_A; file <= FILE_H; ++file) {
			sq120 = (21 + (file-1)) + 10 * (rank-1);
			Sq64_to_Sq120[sq64] = sq120;
			Sq120_to_Sq64[sq120] = sq64;
			sq64++;
		}
	}
}