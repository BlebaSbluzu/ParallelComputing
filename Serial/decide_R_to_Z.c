#include "vars_defs_functions.h"


void decide_R_to_Z(int row, int col, unsigned long *ptr_to_numR, 
                   unsigned long *ptr_to_numZ, CELL **current, CELL **future) {
    if (current[row][col].counter_R_to_Z <= 0) { // Time to revive
        future[row][col].state = 'Z';
        (*ptr_to_numZ)++;
    } else { // Decrease counter and remain removed
        future[row][col] = current[row][col];
        future[row][col].counter_R_to_Z--;
        (*ptr_to_numR)++;
    }
}
