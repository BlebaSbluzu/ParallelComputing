
void initialiseWorld(CELL **current, CELL **future,
                     unsigned long *ptr_to_numS, unsigned long *ptr_to_numZ){


     int rows = 10, cols = 10;

     srand(time(NULL));

     int z_row = rand() % rows;
     int z_col = rand() % cols;

     *ptr_to_numS = 0;
     *ptr_to_numZ = 0;


     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Initialize the current array
            current[i][j].state = 'S';     
            current[i][j].counter_I_to_Z = 0;
            current[i][j].counter_R_to_Z = 0;
            current[i][j].counter_D_to_Empty = 0;
            current[i][j].age = 0;
            current[i][j].stateChange = ' ';


	    
     
}
