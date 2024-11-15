#include "vars_defs_functions.h"
void decide_D_to_Empty(int row,
                       int col,
                       unsigned long *ptr_to_numD,
                       CELL **current,
                       CELL **future) {
    if (current[row][col].counter_D_to_Empty >= 2) {
        future[row][col].state = ' '; // Becomes empty
        (*ptr_to_numD)--;
    } else {
        future[row][col] = current[row][col]; // No change, increment counter
        future[row][col].counter_D_to_Empty++;
    }
}
