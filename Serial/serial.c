#include "vars_defs_functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() { // Specify the return type as int
    unsigned long numS = 0, numZ = 0;

    CELL **current = malloc(ROWS * sizeof(CELL *));
    CELL **future = malloc(ROWS * sizeof(CELL *));
    for (int i = 0; i < ROWS; i++) {
        current[i] = malloc(COLS * sizeof(CELL));
        future[i] = malloc(COLS * sizeof(CELL));
    }

    initialiseWorld(current, future, &numS, &numZ);

    // Free allocated memory to avoid memory leaks
    for (int i = 0; i < ROWS; i++) {
        free(current[i]);
        free(future[i]);
    }
    free(current);
    free(future);

    return 0; // Add return statement
}
