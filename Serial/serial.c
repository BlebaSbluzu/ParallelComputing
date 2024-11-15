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

   

    FILE *fp_daySZRD = fopen("data/daySZRD.dat", "w");

    for (int day = 0; day < TOTAL_DAYS; day++) {
      
    unsigned long numS = 0, numZ = 0, numR = 0, numD = 0;


    fprintf(fp_daySZRD, "%d %lu %lu %lu %lu\n", day, numS, numZ, numR, numD);

  outputWorld(day, current);
  // outputDaySZRD(fp_daySZRD, day, numS, numZ, numR, numD)
}

    
fclose(fp_daySZRD);
 
fp_daySZRD = fopen("data/daySZRD.dat", "r");
if (!fp_daySZRD) {
    perror("Failed to reopen daySZRD.dat");
    return 1;
}

char buffer[256];
while (fgets(buffer, sizeof(buffer), fp_daySZRD)) {
    printf("%s", buffer); // Print each line to the console
}
fclose(fp_daySZRD);
 
    
    // Output the world state


    // Write the SZRD data for this day
;

    // Update current and future arrays for the next day (simulation logic goes here)



 return 0;
}

    


    

