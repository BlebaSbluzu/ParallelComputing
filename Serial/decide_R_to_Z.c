#include "vars_defs_functions.h"


void decide_R_to_Z(int row, int col, CELL **current, CELL **future) {
    if (current[row][col].counter_R_to_Z <= 0) { 
        future[row][col].state = 'Z';

    } else { 
        future[row][col] = current[row][col];
        future[row][col].counter_R_to_Z--;

    }
}
