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

//CHANCES OF INFECTION
#define BASE_PROB_S_TO_Z 0.30
// 30% chance with 1 zombie
#define EXTRA_PROB_S_TO_Z_PER_ZOMBIE 0.10
// +10% for each additional zombie


#define MIN_NUM_S_TO_KILL_Z 3

#define BASE_PROB_Z_TO_R 0.50
// 50% chance with 3 susceptibles/infecteds
#define EXTRA_PROB_Z_TO_R_PER_EXTRA_S 0.10
// +10% for each extra susceptible/infected

// Natural Death
#define PROB_S_TO_R 0.067

#define DAILY_DEATHS_PER_1000 6.7

// Birth Rate
#define BASE_PROB_NEW_S 0.35
// Birth rate

#define INFECTED_TO_ZOMBIE_DAYS 2

// Time for dead cell to empty
#define TIME_R_TO_EMPTY 3

#define MAX_TIME_R_TO_Z 3

typedef struct cell {
    char state;              
    int counter_I_to_Z;     
    int counter_R_to_Z;      
    int age;            
    char stateChange;        
} CELL;


void initialiseWorld(CELL **current,
		     CELL **future,
		     unsigned long *ptr_to_numS,
		     unsigned long *ptr_to_numZ);

void outputWorld(int day,
		 CELL **current);

void outputDaySZRI(FILE *fp_daySZRI, int day,
		    unsigned long numS,
		    unsigned long numZ,
		    unsigned long numR,
		    unsigned long numI);

int countZombieNeighbours(int row,
			    int col,
			    CELL **current);

int countSusceptibleNeighbours(int row,
			       int col,
			       CELL **current);

void decide_S_to_ZorR(int row,
		      int col,
		      int num_Zombie_Neighbours,
		      CELL **current,
		      CELL **future
		      
		      );


void decide_S_to_R(int row,
		   int col,
		   int num_Zombie_Neighbours,
		   CELL **current,
		   CELL **future);


void decide_Z_to_R(int row,
		   int col,
		   int num_Susceptible_Neighbours,
		   CELL **current,
		   CELL **future);


void decide_R_to_Z(int row,
		   int col,
		   CELL **current,
		   CELL **future);


void decide_R_to_Empty(int row,
		       int col,
		       CELL **current,
		       CELL **future);

#endif
