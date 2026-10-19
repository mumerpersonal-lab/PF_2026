#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    
    printf("Enter rows and columns for Matrix A (max 3): ");
    scanf("%d %d", &r1, &c1);
    
    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3) {
        printf("Error: Invalid dimensions for Matrix A. Must be between 1 and 3.\n");
        return 0;
    }
    
    printf("Enter rows and columns for Matrix B (max 3): ");
    scanf("%d %d", &r2, &c2);
    
    if (r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3) {
        printf("Error: Invalid dimensions for Matrix B. Must be between 1 and 3.\n");
        return 0;
    }
    
    if (c1 != r2) {
        printf("\n[Validation Error] Multiplication not possible!\n");
        printf("Columns of Matrix A (%d) must match Rows of Matrix B (%d).\n", c1, r2);
        return 0;
    }
    
    int A[3][3], B[3][3], C[3][3] = {0};
    
    printf("\nEnter elements of Matrix A (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("  A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\nEnter elements of Matrix B (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("  B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    
    for (int i = 0; i < r1; i++) {       
        for (int j = 0; j < c2; j++) {     
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {  
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("             RESULTS SUMMARY             \n");
    printf("Matrix A (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%6d ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix B (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%6d ", B[i][j]);
        }
        printf("\n");
    }
    
    printf("\nResultant Matrix C (A x B) (%dx%d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%6d ", C[i][j]);
        }
        printf("\n");
    }    
    return 0;
}
