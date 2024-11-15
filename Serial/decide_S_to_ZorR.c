#include "vars_defs_functions.h"
#include <stdlib.h>

void decide_S_to_ZorR(int row, int col, int num_Zombie_Neighbours, unsigned long *ptr_to_numS,
                       unsigned long *ptr_to_numZ, unsigned long *ptr_to_numR,
                       CELL **current, CELL **future) {
    
    if (current[row][col].state == 'I') {  // Infected
        current[row][col].counter_I_to_Z++;  // Increment the infection counter

        future[row][col].counter_I_to_Z = current[row][col].counter_I_to_Z;  // Ensure future is also updated
      
        // Transition to Zombie if the counter exceeds the threshold
        if (current[row][col].counter_I_to_Z >= INFECTED_TO_ZOMBIE_DAYS) {
        
            future[row][col].state = 'Z'; 
            (*ptr_to_numZ)++;              
            (*ptr_to_numS)--;               
         
            future[row][col].counter_I_to_Z = 0;  
        }
    } 
    else if (current[row][col].state == 'S') {  
        if (num_Zombie_Neighbours > 0) {
       
            double prob_of_infection = BASE_PROB_S_TO_Z + (num_Zombie_Neighbours * EXTRA_PROB_S_TO_Z_PER_ZOMBIE);
       
            if ((rand() / (double)RAND_MAX) < prob_of_infection) {
                future[row][col].state = 'I';  
                future[row][col].counter_I_to_Z = 0;  
                (*ptr_to_numS)--;             
            }
        }
    }
}
