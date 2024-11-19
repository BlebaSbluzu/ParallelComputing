#include "vars_defs_functions.h"
#include <stdlib.h> // For rand()

void decide_R_to_Z(int row, int col, CELL **current, CELL **future) {
    // Check if the cell's counter for R_to_Z has expired
    if (current[row][col].counter_R_to_Z < TIME_R_TO_EMPTY) { 
        if ((rand() / (double)RAND_MAX) <= BASE_PROB_S_TO_Z) { 
            future[row][col].state = 'Z';
            future[row][col].counter_R_to_Z = 0; // Reset counter for safety
        } else { 
            // If the 30% chance fails, cell becomes empty
            future[row][col].state = 'R';
	    current[row][col].counter_R_to_Z++;
        }
    } else if (current[row][col].counter_R_to_Z >= TIME_R_TO_EMPTY) { 
        // If the counter exceeds the allowed time, cell becomes empty
        future[row][col].state = 'E';
	future[row][col].counter_R_to_Z = 0;
	
    } 
}
