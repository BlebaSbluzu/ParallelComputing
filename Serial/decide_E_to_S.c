#include "vars_defs_functions.h"
#include <stdlib.h> 
void decide_E_to_S(int row,
		       int col,
		       CELL **current,
		       CELL **future) {
    if ((rand() / (double)RAND_MAX) <=  BASE_PROB_NEW_S) {
 future[row][col].state = 'S';
        }
    else{
        future[row][col].state = 'E';
    }
}
