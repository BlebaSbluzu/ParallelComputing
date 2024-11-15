#include "vars_defs_functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() { 
    unsigned long numS = 0, numZ = 0;

    CELL **current = malloc(ROWS * sizeof(CELL *));
    CELL **future = malloc(ROWS * sizeof(CELL *));
    for (int i = 0; i < ROWS; i++) {
        current[i] = malloc(COLS * sizeof(CELL));
        future[i] = malloc(COLS * sizeof(CELL));
    }

    initialiseWorld(current, future, &numS, &numZ);


    for (int i = 0; i < ROWS; i++) {
        free(current[i]);
        free(future[i]);
    }
    free(current);
    free(future);

    return 0;

    FILE *fp_daySZRD = fopen("data/daySZRD.dat", "w");

    for (int day = 0; day < TOTAL_DAYS; day++) {
    unsigned long numS = 0, numZ = 0, numR = 0, numD = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (current[i][j].state) {

	      //CHANGE THIS
                case 'S': numS++; break;  // S state
                case 'Z': numZ++; break;  // Z state
                case 'R': numR++; break;  // R state
                case 'D': numD++; break;  // D state

		  
            }
        }
    }
char buffer[256]; // Buffer to store each line of the file
    while (fgets(buffer, sizeof(buffer), *fp_daySZRD)) {
        printf("%s", buffer); // Print each line to the console
    }

    fclose(*fp_daySZRD);

    
    // Output the world state
    outputWorld(day, current);

    // Write the SZRD data for this day
    outputDaySZRD(fp_daySZRD, day, numS, numZ, numR, numD);

    // Update current and future arrays for the next day (simulation logic goes here)
}

    


    
}
