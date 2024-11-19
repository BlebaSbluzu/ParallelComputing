#include "vars_defs_functions.h"
#include <stdlib.h>

void decide_S_to_ZorR(int row, int col, int num_Zombie_Neighbours,
                       CELL **current, CELL **future) {
    
    if (current[row][col].state == 'I') {  
        current[row][col].counter_I_to_Z++; 

        future[row][col].counter_I_to_Z = current[row][col].counter_I_to_Z; 
      
       
        if (current[row][col].counter_I_to_Z >= INFECTED_TO_ZOMBIE_DAYS) {
        
            future[row][col].state = 'Z'; 
                     
         
            future[row][col].counter_I_to_Z = 0;  
        }
    } 
    else if (current[row][col].state == 'S') {  
        if (num_Zombie_Neighbours > 0) {
       
            double prob_of_infection = BASE_PROB_S_TO_Z + (num_Zombie_Neighbours * EXTRA_PROB_S_TO_Z_PER_ZOMBIE);
       
            if ((rand() / (double)RAND_MAX) < prob_of_infection) {
                future[row][col].state = 'I';  
                future[row][col].counter_I_to_Z = 0;  
                  
            }
	    if  ((rand() / (double)RAND_MAX) < PROB_S_TO_D) {
                future[row][col].state = 'R';  
              
                  
            }

	    
        }
    }
}
