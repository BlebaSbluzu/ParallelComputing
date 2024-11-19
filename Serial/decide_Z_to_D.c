#include "vars_defs_functions.h"
#include <stdlib.h>


void decide_Z_to_D(int row, int col, int num_Susceptible_Neighbours,
                   CELL **current, CELL **future) {
    float probKill = BASE_PROB_Z_TO_D + (num_Susceptible_Neighbours - MIN_NUM_S_TO_KILL_Z) * EXTRA_PROB_Z_TO_D_PER_EXTRA_S;
    if (num_Susceptible_Neighbours >= MIN_NUM_S_TO_KILL_Z && ((float)rand() / RAND_MAX) < probKill) {
        future[row][col].state = 'R';
        future[row][col].counter_R_to_Z = 0;

    } else {
        future[row][col] = current[row][col];

    }
}
