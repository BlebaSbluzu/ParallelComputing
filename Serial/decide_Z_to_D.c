#include "vars_defs_functions.h"
#include <stdlib.h>


void decide_Z_to_D(int row, int col, int num_Susceptible_Neighbours,
                   unsigned long *ptr_to_numZ, unsigned long *ptr_to_numD,
                   CELL **current, CELL **future) {
    float probKill = BASE_PROB_Z_TO_D + (num_Susceptible_Neighbours - MIN_NUM_S_TO_KILL_Z) * EXTRA_PROB_Z_TO_D_PER_EXTRA_S;
    if (num_Susceptible_Neighbours >= MIN_NUM_S_TO_KILL_Z && ((float)rand() / RAND_MAX) < probKill) {
        future[row][col].state = 'D';
        future[row][col].counter_D_to_Empty = TIME_D_TO_EMPTY;
        (*ptr_to_numD)++;
    } else {
        future[row][col] = current[row][col];
        (*ptr_to_numZ)++;
    }
}
