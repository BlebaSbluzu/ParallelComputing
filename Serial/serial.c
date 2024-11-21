#include "vars_defs_functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
  unsigned long numS = 0, numZ = 0, numR = 0, numD = 0,numI = 0;

    CELL **current = malloc(ROWS * sizeof(CELL *));
    CELL **future = malloc(ROWS * sizeof(CELL *));
    for (int i = 0; i < ROWS; i++) {
        current[i] = malloc(COLS * sizeof(CELL));
        future[i] = malloc(COLS * sizeof(CELL));
    }

   
    initialiseWorld(current, future, &numS, &numZ);

    FILE *fp_daySZRI = fopen("data/daySZRI.dat", "w");

   
    for (int day = 1; day <= TOTAL_DAYS; day++) {
       
        numS = numZ = numR = numI = 0;

       
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int zombieCount = countZombieNeighbours(i, j, current);
                int susceptibleCount = countSusceptibleNeighbours(i, j, current);

             
                switch (current[i][j].state) {
                    case 'S': 
		      decide_S_to_ZorR(i, j, zombieCount, current, future);
			numS++;
                        break;
		case 'I':
		  decide_S_to_ZorR(i, j, zombieCount, current, future);
		  numI++;
                        break;
                    case 'Z': 
                        decide_Z_to_R(i, j, susceptibleCount, current, future);
			numZ++;
                        break;
                    case 'R': 
                        decide_R_to_ZorE(i, j, current, future);
			numR++;
                        break;
                
	    case 'E':
	      decide_E_to_S(i, j, current, future);
	      break;
		}
            }
        }

	outputDaySZRI(fp_daySZRI, day, numS, numZ, numR, numI);

      
        
        outputWorld(day, current);

       
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                current[i][j] = future[i][j]; 
            }
        }
    }


    fclose(fp_daySZRI);

    
    fp_daySZRI = fopen("data/daySZRI.dat", "r");


    fclose(fp_daySZRI);


    for (int i = 0; i < ROWS; i++) {
        free(current[i]);
        free(future[i]);
    }
    free(current);
    free(future);

    return 0;
}


    


    

