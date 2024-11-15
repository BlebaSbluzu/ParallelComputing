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
        
            future[row][col].state = 'Z';  // Transition to Zombie
            (*ptr_to_numZ)++;               // Increase Zombie count
            (*ptr_to_numS)--;               // Decrease Susceptible count
         
            future[row][col].counter_I_to_Z = 0;  // Reset the counter after transition
        }
    } 
    else if (current[row][col].state == 'S') {  // Susceptible
        // Transition based on surrounding zombies (no randomness)
        if (num_Zombie_Neighbours > 0) {
            // Calculate the probability of infection based on the number of zombie neighbors
            double prob_of_infection = BASE_PROB_S_TO_Z + (num_Zombie_Neighbours * EXTRA_PROB_S_TO_Z_PER_ZOMBIE);
            
            // If the probability is high enough, this susceptible cell becomes infected
            if ((rand() / (double)RAND_MAX) < prob_of_infection) {
                future[row][col].state = 'I';  // Mark this cell as infected in the future world
                future[row][col].counter_I_to_Z = 0;  // Start the counter for infection to zombie transition
                (*ptr_to_numS)--;              // Decrease Susceptible count
            }
        }
    }
}
