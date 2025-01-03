//
// Global Variables and Definitions
// All times are in days
// Probabilities must be between 0.0 and 1.0 inclusive
//

#ifndef VARS_AND_DEFS
#define VARS_AND_DEFS

#define DEBUG_LEVEL 1

#define ROWS 10
#define COLS 10
#define TOTAL_DAYS 20

#define WORLD_OUTPUT_INTERVAL 1

//Susceptible to Zombie Parameters for Basic Model
#define PROB_S_TO_Z_1 0.90
#define PROB_S_TO_Z_2 0.91
#define PROB_S_TO_Z_3 0.92
#define PROB_S_TO_Z_4 0.93
#define PROB_S_TO_Z_5 0.94
#define PROB_S_TO_Z_6 0.95
#define PROB_S_TO_Z_7 0.96
#define PROB_S_TO_Z_8 0.97

//Susceptible to Removed (Dead) Parameters: Probability of death by
//natural causes: S -> D
#define PROB_S_TO_D 0.01

//Death: Time for dead cell to become empty
#define TIME_D_TO_EMPTY 3

//Minimum number of Susceptibles needed to defeat a Zombie and
//probability of that happening if we have that minimum number of S
#define NUM_S_TO_DEFEAT_Z 6
#define PROB_Z_TO_D 0.1

//Birth
#define PROB_NEW_S 0.01

//Removed (Undead) to Zombie Parameters (after S is savaged by Zombies)
#define MIN_NUM_ZOMBIE_TO_SAVAGE_S 6
#define MIN_TIME_R_TO_Z 1
#define MAX_TIME_R_TO_Z 3



// ****** FOR THE LATENT INFECTION MODEL ****** //

//Infected to Zombie Parameters: Each cell will have an initial time (as random
//number between Min and Max) before: I->Z 
#define MIN_TIME_I_TO_Z 1
#define MAX_TIME_I_TO_Z 5

//Infected to Removed (Dead) Parameters: Probability of death by natural causes: I -> R(D)
#define PROB_I_TO_R 0.01


//Cell Type-definition
typedef struct cell {
  char state;
  int counter_I_to_Z;
  int counter_R_to_Z;
  int counter_R_to_Empty;
  int age;
  char stateChange;
} CELL;


//Function Prototypes

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
