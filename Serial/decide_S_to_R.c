#include "vars_defs_functions.h"
#include <stdlib.h>

void decide_S_to_R(int row, int col, int num_Zombie_Neighbours,
                   CELL **current, CELL **future) {
    float probDeath = PROB_S_TO_R;
    if (((float)rand() / RAND_MAX) < probDeath) {
        future[row][col].state = 'R';


    } else {
        future[row][col] = current[row][col];

    }
}
