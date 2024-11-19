#include "vars_defs_functions.h" 
#include <stdlib.h>
#include <time.h>

void initialiseWorld(CELL **current, CELL **future,
                     unsigned long *ptr_to_numS, unsigned long *ptr_to_numZ){


    

     srand(time(NULL));

     int z_row = rand() % ROWS;
     int z_col = rand() % COLS;

     *ptr_to_numS = 0;
     *ptr_to_numZ = 0;


     for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
        
            current[i][j].state = 'S';     
            current[i][j].counter_I_to_Z = 0;
            current[i][j].counter_R_to_Z = 0;
            current[i][j].stateChange = ' ';

	    
	    future[i][j].state = 'S';      
            future[i][j].counter_I_to_Z = 0;
            future[i][j].counter_R_to_Z = 0;
            future[i][j].stateChange = ' ';

	                if (i == z_row && j == z_col) {
                current[i][j].state = 'Z';
                (*ptr_to_numZ)++;
            } else {
                (*ptr_to_numS)++;
            }
		
        }
	
    }
     //	printf("num Z = %d and num S = %d",(int)*ptr_to_numZ,(int)*ptr_to_numS);
}
     

