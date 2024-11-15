#include <vars_defs_functions.h>


main(){

    unsigned long numS = 0, numZ = 0;

    CELL **current = malloc(ROWS * sizeof(CELL *));
    CELL **future = malloc(ROWS * sizeof(CELL *));
    for (int i = 0; i < ROWS; i++) {
        current[i] = malloc(COLS * sizeof(CELL));
        future[i] = malloc(COLS * sizeof(CELL));
    }

   
    initialiseWorld(current, future, &numS, &numZ);

  
}

