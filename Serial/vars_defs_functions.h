//
// Global Variables and Definitions
// All times are in days
// Probabilities must be between 0.0 and 1.0 inclusive
//

#include <stdio.h>

#ifndef VARS_AND_DEFS
#define VARS_AND_DEFS

#define DEBUG_LEVEL 1

#define ROWS 10
#define COLS 10
#define TOTAL_DAYS 20

#define WORLD_OUTPUT_INTERVAL 1

// Susceptible to Zombie Parameters
#define BASE_PROB_S_TO_Z 0.30  // 30% chance with 1 zombie
#define EXTRA_PROB_S_TO_Z_PER_ZOMBIE 0.10 // +10% for each additional zombie

// Zombie to Dead (Killed by Susceptible/Infected)
#define MIN_NUM_S_TO_KILL_Z 3
#define BASE_PROB_Z_TO_D 0.50 // 50% chance with 3 susceptibles/infecteds
#define EXTRA_PROB_Z_TO_D_PER_EXTRA_S 0.10 // +10% for each extra susceptible/infected

// Natural Deaths (Susceptibles/Infecteds/Removed)
#define DAILY_DEATHS_PER_1000 6.7

// Birth Rate
#define BASE_PROB_NEW_S 0.35 // Birth rate multiplier based on current population

// Infected to Zombie Transition
#define INFECTED_TO_ZOMBIE_DAYS 2

// Death: Time for dead cell to become empty
#define TIME_D_TO_EMPTY 3

// Removed to Zombie Parameters (Min and Max Days)
#define MIN_TIME_R_TO_Z 1
#define MAX_TIME_R_TO_Z 3

// Cell Type-definition
typedef struct cell {
    char state;              // Current state ('S', 'Z', 'I', 'R', 'D', etc.)
    int counter_I_to_Z;      // Days as infected to become a zombie
    int counter_R_to_Z;      // Days as removed before turning zombie
    int counter_D_to_Empty;  // Days as dead before becoming empty
    int age;                 // Age of the cell (for potential extensions)
    char stateChange;        // Indicator of the last state transition
} CELL;

// Function Prototypes
void initialiseWorld(CELL **current,
		     CELL **future,
		     unsigned long *ptr_to_numS,
		     unsigned long *ptr_to_numZ);

void outputWorld(int day,
		 CELL **current);

void outputDaySZRD(FILE *fp_daySZRD, int day,
		    unsigned long numS,
		    unsigned long numZ,
		    unsigned long numR,
		    unsigned long numD);

int countZombieNeighbours(int row,
			    int col,
			    CELL **current);

int countSusceptibleNeighbours(int row,
			       int col,
			       CELL **current);

void decide_S_to_ZorR(int row,
		      int col,
		      int num_Zombie_Neighbours,
		      unsigned long *ptr_to_numS,
		      unsigned long *ptr_to_numZ,
		      unsigned long *ptr_to_numR,
		      CELL **current,
		      CELL **future);


void decide_S_to_D(int row,
		   int col,
		   int num_Zombie_Neighbours,
		   unsigned long *ptr_to_numS,
		   unsigned long *ptr_to_numD,
		   CELL **current,
		   CELL **future);


void decide_Z_to_D(int row,
		   int col,
		   int num_Susceptible_Neighbours,
		   unsigned long *ptr_to_numZ,
		   unsigned long *ptr_to_numD,
		   CELL **current,
		   CELL **future);


void decide_R_to_Z(int row,
		   int col,
		   unsigned long *ptr_to_numR,
		   unsigned long *ptr_to_numZ,
		   CELL **current,
		   CELL **future);


void decide_D_to_Empty(int row,
		       int col,
		       unsigned long *ptr_to_numD,
		       CELL **current,
		       CELL **future);

#endif
