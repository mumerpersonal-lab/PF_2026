#include <stdio.h>
int main() {
    int arr[3][3][3] = {
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        },
        {
            { 9, 8, 7 },
            { 6, 5, 4 },
            { 3, 2, 1 }
        },
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        }
    };
    printf("       3x3x3 MATRIX SET LAYER SIMILARITY ANALYSIS \n");
    for (int l = 0; l < 3; l++) {
        printf("--- Layer %d Matrix ---\n", l);
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                printf("%5d ", arr[l][r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("          PAIRWISE LAYER SIMILARITY REPORT        \n");
    int pairs[3][2] = {
        {0, 1},
        {0, 2},
        {1, 2}
    };
    for (int p = 0; p < 3; p++) {
        int l1 = pairs[p][0];
        int l2 = pairs[p][1];
        int is_identical = 1; 
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (arr[l1][r][c] != arr[l2][r][c]) {
                    is_identical = 0;
                    break; 
                }
            }
            if (!is_identical) break; 
        }
        printf("Comparison: Layer %d vs Layer %d  =  ", l1, l2);
        if (is_identical) {
            printf("[IDENTICAL]\n");
        } else {
            printf("[DISTINCT]\n");
        }
    }

    return 0;
}
