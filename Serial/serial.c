#include "vars_defs_functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() { 
    // Declare counters for the initial state
    unsigned long numS = 0, numZ = 0;

    // Allocate memory for 2D arrays `current` and `future`
    CELL **current = malloc(ROWS * sizeof(CELL *));
    CELL **future = malloc(ROWS * sizeof(CELL *));
    for (int i = 0; i < ROWS; i++) {
        current[i] = malloc(COLS * sizeof(CELL));
        future[i] = malloc(COLS * sizeof(CELL));
    }

    // Initialize the world (populate initial cell states)
    initialiseWorld(current, future, &numS, &numZ);

    // Open the file to record SZRD data
    FILE *fp_daySZRD = fopen("data/daySZRD.dat", "w");
    if (!fp_daySZRD) {
        perror("Failed to open daySZRD.dat");
        return 1; // Exit program if file opening fails
    }

    // Simulate for TOTAL_DAYS
for (int day = 0; day < TOTAL_DAYS; day++) {
    unsigned long numS = 0, numZ = 0, numR = 0, numD = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int zombieCount = countZombieNeighbours(i, j, current);
            int susceptibleCount = countSusceptibleNeighbours(i, j, current);

            // Update state counters based on the current cell's state
            switch (current[i][j].state) {
                case '@': numS++; break;
                case 'Z': numZ++; break;
                case 'R': numR++; break;
                case 'D': numD++; break;
            }
        }
    }

    // Write SZRD data for this day to the file
    fprintf(fp_daySZRD, "%d %lu %lu %lu %lu\n", day, numS, numZ, numR, numD);

    // Output the world state for the current day
    outputWorld(day, current);

    // Update the world for the next day (simulation logic goes here)
}


  
    fclose(fp_daySZRD);


    fp_daySZRD = fopen("data/daySZRD.dat", "r");


    // Print the SZRD data to the console
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp_daySZRD)) {
        printf("%s", buffer);
    }
    fclose(fp_daySZRD);

    // Free the 2D arrays `current` and `future` after simulation ends
    for (int i = 0; i < ROWS; i++) {
        free(current[i]);
        free(future[i]);
    }
    free(current);
    free(future);

    return 0;
}

    


    

