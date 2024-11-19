#include "vars_defs_functions.h"

int countZombieNeighbours(int row, int col, CELL **current) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) 
                continue;
            
            int neighborRow = (row + i + ROWS) % ROWS;
            int neighborCol = (col + j + COLS) % COLS;

            if (current[neighborRow][neighborCol].state == 'Z') {
                count++;
            }
        }
    }
    return count;
}
