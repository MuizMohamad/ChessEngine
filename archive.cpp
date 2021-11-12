
#include "archive.h"
#include "helper.h"

std::vector<int> getRightDiagonalSq(int sq){
    
    std::vector<int> all_diagonals = {};

    std::string sq_str = sqToSqStr(sq);

     // going up right
    char file_up = sq_str[0] + 1;
    char rank_up = sq_str[1] + 1;

    std::string up_square = std::string(1,file_up) + std::string(1,rank_up);
   
    while(checkInsideBoard(up_square)){

        all_diagonals.push_back(sqStrToSq(up_square));

        file_up = file_up + 1;
        rank_up = rank_up + 1; 

        up_square = std::string(1,file_up) + std::string(1,rank_up);
    }

    // gping down left
    char file_down = sq_str[0] - 1;
    char rank_down = sq_str[1] - 1;

    std::string down_square = std::string(1,file_down) + std::string(1,rank_down);

    while(checkInsideBoard(down_square)){

        all_diagonals.push_back(sqStrToSq(down_square));

        file_down = file_down - 1;
        rank_down = rank_down - 1; 

        down_square = std::string(1,file_down) + std::string(1,rank_down);
        
    }

    return all_diagonals;
}

std::vector<int> getLeftDiagonalSq(int sq){
    
    std::vector<int> all_diagonals = {};

    std::string sq_str = sqToSqStr(sq);

    // going up left
    char file_up = sq_str[0] - 1;
    char rank_up = sq_str[1] + 1;

    std::string up_square = std::string(1,file_up) + std::string(1,rank_up);
 
    while(checkInsideBoard(up_square)){

        all_diagonals.push_back(sqStrToSq(up_square));

        file_up = file_up - 1;
        rank_up = rank_up + 1; 

        up_square = std::string(1,file_up) + std::string(1,rank_up);
    }

    // going down right
    char file_down = sq_str[0] + 1;
    char rank_down = sq_str[1] - 1;

     std::string down_square = std::string(1,file_down) + std::string(1,rank_down);

    while(checkInsideBoard(down_square)){

        all_diagonals.push_back(sqStrToSq(down_square));

        file_down = file_down + 1;
        rank_down = rank_down - 1; 

        down_square = std::string(1,file_down) + std::string(1,rank_down);
    }

    return all_diagonals;

}

std::vector<int> getAllDiagonalSq(int sq){
    std::vector<int> all_diagonal = {};

    std::vector<int> right_diagonal = getRightDiagonalSq(sq);
    std::vector<int> left_diagonal = getLeftDiagonalSq(sq);

    all_diagonal.insert(all_diagonal.end(),right_diagonal.begin(),right_diagonal.end());
    all_diagonal.insert(all_diagonal.end(),left_diagonal.begin(),left_diagonal.end());

    return all_diagonal;
}

std::vector<int> getUpDownHorizontalSq(int sq){
    std::vector<int> all_horizontal = {};

    std::string sq_str = sqToSqStr(sq);

    // going up left
    char file_up = sq_str[0] + 0;
    char rank_up = sq_str[1] + 1;

    std::string up_square = std::string(1,file_up) + std::string(1,rank_up);
 
    while(checkInsideBoard(up_square)){

         all_horizontal.push_back(sqStrToSq(up_square));

        file_up = file_up + 0;
        rank_up = rank_up + 1; 

        up_square = std::string(1,file_up) + std::string(1,rank_up);
    }

    // going down right
    char file_down = sq_str[0] + 0;
    char rank_down = sq_str[1] - 1;

     std::string down_square = std::string(1,file_down) + std::string(1,rank_down);

    while(checkInsideBoard(down_square)){

        all_horizontal.push_back(sqStrToSq(down_square));

        file_down = file_down + 0;
        rank_down = rank_down - 1; 

        down_square = std::string(1,file_down) + std::string(1,rank_down);
    }

    return  all_horizontal;
}

std::vector<int> getLeftRightHorizontalSq(int sq){

    std::vector<int> all_horizontal = {};

    std::string sq_str = sqToSqStr(sq);

    // going up left
    char file_up = sq_str[0] + 1;
    char rank_up = sq_str[1] + 0;

    std::string up_square = std::string(1,file_up) + std::string(1,rank_up);
 
    while(checkInsideBoard(up_square)){

         all_horizontal.push_back(sqStrToSq(up_square));

        file_up = file_up + 1;
        rank_up = rank_up + 0; 

        up_square = std::string(1,file_up) + std::string(1,rank_up);
    }

    // going down right
    char file_down = sq_str[0] - 1;
    char rank_down = sq_str[1] + 0;

     std::string down_square = std::string(1,file_down) + std::string(1,rank_down);

    while(checkInsideBoard(down_square)){

        all_horizontal.push_back(sqStrToSq(down_square));

        file_down = file_down - 1;
        rank_down = rank_down + 0; 

        down_square = std::string(1,file_down) + std::string(1,rank_down);
    }

    return  all_horizontal;

}

std::vector<int> getAllHorizontalSq(int sq){

    std::vector<int> all_horizontal = {};

    std::vector<int> up_down_horizontal = getUpDownHorizontalSq(sq);
    std::vector<int> right_left_horizontal = getLeftRightHorizontalSq(sq);

    all_horizontal.insert(all_horizontal.end(),up_down_horizontal.begin(),up_down_horizontal.end());
    all_horizontal.insert(all_horizontal.end(),right_left_horizontal.begin(),right_left_horizontal.end());

    return all_horizontal;
}

std::vector<int> getAllSquareAround(int sq){

    std::vector<int> squares = {};

    std::string sq_str = sqToSqStr(sq);
    
    char file = sq_str[0];
    char rank = sq_str[1];

    for (int f = -1 ; f <=  1 ; f++){
        for (int r = -1 ; r <= 1 ; r++){
            char file_sq = file + f;
            char rank_sq = rank + r;
            std::string around_sq = combineFileRankStr(file_sq,rank_sq);

            if (checkInsideBoard(around_sq) && !(around_sq == sqToSqStr(sq))) squares.push_back(sqStrToSq(around_sq));
        }
    }

    return squares;
}

// generate all 8 knight squares
std::vector<int> getKnightSqAround(int sq){

    std::vector<int> squares = {};

    std::string sq_str = sqToSqStr(sq);

    char file = sq_str[0];
    char rank = sq_str[1];

    std::vector<std::string> possible_squares = {};

    // go left (up/down)
    char file_l = file - 2;
    char rank_l_up = rank - 1;
    char rank_l_down = rank + 1;

    possible_squares.push_back(combineFileRankStr(file_l,rank_l_up));
    possible_squares.push_back(combineFileRankStr(file_l,rank_l_down));

    // go up (left/right)
    char rank_u = rank + 2;
    char file_u_left = file - 1;
    char file_u_right = file + 1;

    possible_squares.push_back(combineFileRankStr(file_u_left,rank_u));
    possible_squares.push_back(combineFileRankStr(file_u_right,rank_u));

    // go right (up/down)
    char file_r = file + 2;
    char rank_r_up = rank - 1;
    char rank_r_down = rank + 1;

    possible_squares.push_back(combineFileRankStr(file_r,rank_r_up));
    possible_squares.push_back(combineFileRankStr(file_r,rank_r_down));

    // go down (left/right)
    char rank_d = rank - 2;
    char file_d_left = file - 1;
    char file_d_right = file + 1;

    possible_squares.push_back(combineFileRankStr(file_d_left,rank_d));
    possible_squares.push_back(combineFileRankStr(file_d_right,rank_d));

    for (std::string sq : possible_squares){
        if (checkInsideBoard(sq)) squares.push_back(sqStrToSq(sq));
    }

    return squares;

}

std::vector<int> getOppPawnAttackSq(int sq,int sq_piece_color){

    std::vector<int> attack_sq = {};

    std::string sq_str = sqToSqStr(sq);

    // going up left
    char file = sq_str[0];
    char rank = sq_str[1];

    if (sq_piece_color == WHITE){

        // up_right square
        char file_ur = file + 1;
        char rank_ur = rank + 1;
        std::string up_right_sq = combineFileRankStr(file_ur,rank_ur);

        // up_left square
        char file_ul = file - 1;
        char rank_ul = rank + 1;
        std::string up_left_sq = combineFileRankStr(file_ul,rank_ul);

        if (checkInsideBoard(up_right_sq)) attack_sq.push_back(sqStrToSq(up_right_sq));
        if (checkInsideBoard(up_left_sq)) attack_sq.push_back(sqStrToSq(up_left_sq));

    }
    else {

        // down_right square
        char file_dr = file + 1;
        char rank_dr = rank - 1;
        std::string down_right_sq = combineFileRankStr(file_dr,rank_dr);

        // up_left square
        char file_dl = file - 1;
        char rank_dl = rank - 1;
        std::string down_left_sq = combineFileRankStr(file_dl,rank_dl);

        if (checkInsideBoard(down_right_sq)) attack_sq.push_back(sqStrToSq(down_right_sq));
        if (checkInsideBoard(down_left_sq)) attack_sq.push_back(sqStrToSq(down_left_sq));
    }

    return attack_sq;
}