#include "vars_defs_functions.h"
#include <stdlib.h> 

void decide_R_to_ZorE
(int row, int col, CELL **current, CELL **future) {
    
    if (current[row][col].counter_R_to_Z < TIME_R_TO_EMPTY) { 
        if ((rand() / (double)RAND_MAX) <= BASE_PROB_S_TO_Z) { 
            future[row][col].state = 'Z';
            future[row][col].counter_R_to_Z = 0; 
        } else { 
           
            future[row][col].state = 'R';
	    current[row][col].counter_R_to_Z++;
        }
    } else if (current[row][col].counter_R_to_Z >= TIME_R_TO_EMPTY) { 
        future[row][col].state = 'E';
	future[row][col].counter_R_to_Z = 0;
	
    } 
}
