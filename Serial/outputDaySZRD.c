#include <stdio.h>
#include "vars_defs_functions.h"

void outputDaySZRD(FILE *fp_daySZRD, int day,
                   unsigned long numS, unsigned long numZ,
                   unsigned long numR, unsigned long numD) {
   
    if (!fp_daySZRD) {
        fprintf(stderr, "Error: Invalid file pointer for SZRD data.\n");
        return;
    }

    fprintf(fp_daySZRD, "%d %lu %lu %lu %lu\n", day, numS, numZ, numR, numD);

    
    #if DEBUG_LEVEL > 0
    printf("Day %d: S = %lu, Z = %lu, R = %lu, D = %lu\n", day, numS, numZ, numR, numD);
    #endif
}
