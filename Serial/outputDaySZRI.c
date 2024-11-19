#include <stdio.h>
#include "vars_defs_functions.h"

void outputDaySZRI(FILE *fp_daySZRI, int day,
                   unsigned long numS, unsigned long numZ,
                   unsigned long numR, unsigned long numI) {
  
  fprintf(fp_daySZRI, "%d %d %d %d %d\n", day, (int)numS, (int)numZ, (int)numR, (int)numI);

    #if DEBUG_LEVEL > 0
  printf("Day %d: S = %d, Z = %d, R = %d, I = %d\n", day, (int)numS, (int)numZ, (int)numR, (int)numI);
    #endif
}
