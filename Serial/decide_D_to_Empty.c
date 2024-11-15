#include "vars_defs_functions.h"

void decide_D_to_Empty(int row,
		       int col,
		       unsigned long *ptr_to_numD,
		       CELL **current,
		       CELL **future) {
    if (current[row][col].state == 'D') { // Dead
        current[row][col].counter_D_to_Empty++;  // Increment the counter for decay
        if (current[row][col].counter_D_to_Empty >= TIME_D_TO_EMPTY) {
            current[row][col].state = 'E';  // Become Empty space
            (*ptr_to_numD)--;              // Decrease Dead count
        }
    }
}
