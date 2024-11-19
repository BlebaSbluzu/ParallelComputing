#include "vars_defs_functions.h"

void decide_D_to_Empty(int row,
		       int col,
		       CELL **current,
		       CELL **future) {
    if (current[row][col].state == 'D') {
        current[row][col].counter_R_to_Z++;
        if (current[row][col].counter_R_to_Z >= TIME_D_TO_EMPTY) {
            current[row][col].state = 'E'; 
                 
        }
    }
}
