#include "vars_defs_functions.h"
void decide_R_to_Z(int row,
                   int col,
                   unsigned long *ptr_to_numR,
                   unsigned long *ptr_to_numZ,
                   CELL **current,
                   CELL **future) {
    if (current[row][col].counter_I_to_Z >= 2) {
        future[row][col].state = 'Z'; // Becomes a zombie
        (*ptr_to_numZ)++;
        (*ptr_to_numR)--;
    } else {
        future[row][col] = current[row][col]; // No change, increment counter
        future[row][col].counter_I_to_Z++;
    }
}
