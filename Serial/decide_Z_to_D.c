#include "vars_defs_functions.h"
#include <stdlib.h>


void decide_Z_to_D(int row,
                   int col,
                   int num_Susceptible_Neighbours,
                   unsigned long *ptr_to_numZ,
                   unsigned long *ptr_to_numD,
                   CELL **current,
                   CELL **future) {
    if (num_Susceptible_Neighbours < 3) {
        future[row][col] = current[row][col]; // No change if fewer than 3 susceptibles
        return;
    }

    double killChance = 0.5 + 0.1 * (num_Susceptible_Neighbours - 3);
    double randomValue = (double)rand() / RAND_MAX;

    if (randomValue < killChance) {
        future[row][col].state = 'D'; // Zombie dies
        (*ptr_to_numD)++;
        (*ptr_to_numZ)--;
    } else {
        future[row][col] = current[row][col]; // No change
    }
}
