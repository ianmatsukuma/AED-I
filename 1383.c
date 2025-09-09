#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int is_valid_row(int grid[SIZE][SIZE], int row) {
    int seen[SIZE + 1] = {0};
    for (int i = 0; i < SIZE; i++) {
        int val = grid[row][i];
        if (val < 1 || val > 9 || seen[val]) return 0;
        seen[val] = 1;
    }
    return 1;
}

int is_valid_col(int grid[SIZE][SIZE], int col) {
    int seen[SIZE + 1] = {0};
    for (int i = 0; i < SIZE; i++) {
        int val = grid[i][col];
        if (val < 1 || val > 9 || seen[val]) return 0;
        seen[val] = 1;
    }
    return 1;
}

int is_valid_box(int grid[SIZE][SIZE], int start_row, int start_col) {
    int seen[SIZE + 1] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = grid[start_row + i][start_col + j];
            if (val < 1 || val > 9 || seen[val]) return 0;
            seen[val] = 1;
        }
    }
    return 1;
}

int is_valid_sudoku(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!is_valid_row(grid, i) || !is_valid_col(grid, i)) return 0;
    }
    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            if (!is_valid_box(grid, i, j)) return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int inst = 1; inst <= n; inst++) {
        int grid[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        printf("Instancia %d\n", inst);
        if (is_valid_sudoku(grid)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
