#define DEBUG_LEVEL 1
#define ROWS 10
#define COLS 10
#define TOTAL_DAYS 20
#define WORLD_OUTPUT_INTERVAL 1

typedef struct cell {
char state;
int counter_I_to_Z;
int counter_R_to_Z;
int counter_D_to_Empty;
int age;
char stateChange;
} CELL;

#define PROB_S_TO_Z = 0.3+(#Z-1)*.1

#define PROB_S_TO_D 0.067

//Dead -> Empty cell: Time for dead cell to become empty
#define TIME_D_TO_EMPTY 2

//Minimum number of Susceptibles needed to defeat a Zombie and
//probability of that happening if we have that minimum number of S


//Case 3 susceptimedbles present: 
#define PROB_Z_TO_D .5+(#S-3)*.1

//Birth: possible addition to program, but don’t use it right now.
#define PROB_NEW_S #S*.35

//Removed (Undead) -> Zombie Parameters (after S is savaged by Zombies)
// Minimum number of Z needed to savage S to make S -> R

#define MIN_NUM_ZOMBIE_TO_SAVAGE_S 6

// Minimum and maximum time for R to resurrect as a Z

#define MIN_TIME_R_TO_Z 1
#define MAX_TIME_R_TO_Z 2

// ****** FOR THE LATENT INFECTION MODEL ****** //
//Infected -> Zombie Parameters: Each cell will have an “incubation”
//time (as random number between a minimum and maximum)
//before it goes: I->Z

#define MIN_TIME_I_TO_Z 1
#define MAX_TIME_I_TO_Z 2

//Infected -> Dead Parameters: Probability of death
//by natural causes: I -> D

#define PROB_I_TO_R 0.01 //same as S -> D
