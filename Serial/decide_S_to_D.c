#include "vars_defs_functions.h"
#include <stdlib.h>

void decide_S_to_D(int row, int col, int num_Zombie_Neighbours,
                   unsigned long *ptr_to_numS, unsigned long *ptr_to_numD,
                   CELL **current, CELL **future) {
    float probDeath = PROB_S_TO_D;
    if (((float)rand() / RAND_MAX) < probDeath) {
        future[row][col].state = 'D';
        future[row][col].counter_D_to_Empty = TIME_D_TO_EMPTY;
        (*ptr_to_numD)++;
    } else {
        future[row][col] = current[row][col];
        (*ptr_to_numS)++;
    }
}
