#include "vars_defs_functions.h"
#include <stdlib.h>

void decide_S_to_ZorR(int row, int col, int num_Zombie_Neighbours, 
                      unsigned long *ptr_to_numS, unsigned long *ptr_to_numZ, 
                      unsigned long *ptr_to_numR, CELL **current, CELL **future) {
    float probInfection = BASE_PROB_S_TO_Z + num_Zombie_Neighbours * EXTRA_PROB_S_TO_Z_PER_ZOMBIE;
    if (probInfection > 1.0) probInfection = 1.0; // Cap probability at 100%

    if (((float)rand() / RAND_MAX) < probInfection) { // Infected by zombies
        future[row][col].state = 'I';
        future[row][col].counter_I_to_Z = INFECTED_TO_ZOMBIE_DAYS; // Start infection countdown
        (*ptr_to_numZ)++;
    } else if (((float)rand() / RAND_MAX) < PROB_S_TO_D) { // Death by natural causes
        future[row][col].state = 'D';
        future[row][col].counter_D_to_Empty = TIME_D_TO_EMPTY;
        (*ptr_to_numR)++;
    } else { // Remains susceptible
        future[row][col] = current[row][col];
        (*ptr_to_numS)++;
    }
}
