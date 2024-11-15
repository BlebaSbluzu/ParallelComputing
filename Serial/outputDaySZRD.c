#include <stdio.h>
#include "vars_defs_functions.h"

void outputDaySZRD(FILE *fp_daySZRD, int day,
                   unsigned long numS, unsigned long numZ,
                   unsigned long numR, unsigned long numD) {
    // Cast unsigned long to int for printing, but keep them as unsigned long
    fprintf(fp_daySZRD, "%d %d %d %d %d\n", day, (int)numS, (int)numZ, (int)numR, (int)numD);

    #if DEBUG_LEVEL > 0
    printf("Day %d: S = %d, Z = %d, R = %d, D = %d\n", day, (int)numS, (int)numZ, (int)numR, (int)numD);
    #endif
}
