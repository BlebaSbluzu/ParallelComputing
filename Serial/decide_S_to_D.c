#include "vars_defs_functions.h"
#include <stdlib.h>

void decide_S_to_D(int row,
                   int col,
                   int num_Zombie_Neighbours,
                   unsigned long *ptr_to_numS,
                   unsigned long *ptr_to_numD,
                   CELL **current,
                   CELL **future) {
    double deathChance = 0.3 + 0.1 * (num_Zombie_Neighbours - 1); // Death chance based on zombies
    double randomValue = (double)rand() / RAND_MAX;

    if (randomValue < deathChance) {
        future[row][col].state = 'D'; // Dies
        (*ptr_to_numD)++;
        (*ptr_to_numS)--; // One less susceptible
    } else {
        future[row][col] = current[row][col]; // No change
    }
}
