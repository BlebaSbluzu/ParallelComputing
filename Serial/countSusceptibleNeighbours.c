
int countSusceptibleNeighbours(int row, int col, CELL **current) {
    int count = 0;

    // Check all 8 neighbors with wrap-around boundaries
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) 
                continue; // Skip the cell itself
            
            // Calculate wrapped neighbor positions
            int neighborRow = (row + i + ROWS) % ROWS;
            int neighborCol = (col + j + COLS) % COLS;

            // Check if the neighbor is Susceptible ('@')
            if (current[neighborRow][neighborCol].state == '@') {
                count++;
            }
        }
    }
    return count;
}
