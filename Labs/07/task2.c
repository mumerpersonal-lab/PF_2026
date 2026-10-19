#include <stdio.h>
int main() {
    int i = 0, j = 0, r = 0, c = 0, r2 = 0, c2 = 0;
    int square = 0, zero = 0, identity = 0, diagonal = 0;
    int scalar = 0, utri = 0, ltri = 0, skew = 0, symm = 0;
    int sing = 0, nsing = 0, null = 0, idem = 0, nilpo = 0;
    char n;

    printf("Do You want to compare two matrices?\nY/N ");
    scanf(" %c", &n);

    if (n == 'Y' || n == 'y') {
        printf("Enter number of rows of your first matrix (max 2): ");
        scanf("%d", &r);
        printf("Enter number of columns of your first matrix (max 2): ");
        scanf("%d", &c);
        printf("Enter number of rows of your second matrix (max 2): ");
        scanf("%d", &r2);
        printf("Enter number of columns of your second matrix (max 2): ");
        scanf("%d", &c2);

        int mat1[r][c], mat2[r2][c2];

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                printf("Enter mat1[%d][%d]: ", i, j);
                scanf("%d", &mat1[i][j]);
            }
        }
        for (i = 0; i < r2; i++) {
            for (j = 0; j < c2; j++) {
                printf("Enter mat2[%d][%d]: ", i, j);
                scanf("%d", &mat2[i][j]);
            }
        }

        if (r == r2 && c == c2) {
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (mat1[i][j] != mat2[i][j]) {
                        printf("Not Equal matrices.\n");
                        return 0;
                    }
                }
            }
            printf("Equal matrices.\n");
            return 0;
        } else {
            printf("Not equal Order.\n");
            return 0;
        }
    } else {
        printf("Enter number of rows of your matrix (max 2): ");
        scanf("%d", &r);
        printf("Enter number of columns of your matrix (max 2): ");
        scanf("%d", &c);

        int mat1[r][c];
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                printf("Enter mat1[%d][%d]: ", i, j);
                scanf("%d", &mat1[i][j]);
            }
        }

        if (r == 1) { row_mat: ; } // Placeholder or handled directly
        if (r == c) { square = 1; }

        zero = 1;
        null = 1;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (mat1[i][j] != 0) {
                    zero = 0;
                    null = 0;
                }
            }
        }

        if (square) {
            identity = 1;
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if ((i == j && mat1[i][j] != 1) || (i != j && mat1[i][j] != 0)) {
                        identity = 0;
                    }
                }
            }

            diagonal = 1;
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (i != j && mat1[i][j] != 0) {
                        diagonal = 0;
                    }
                }
            }

            scalar = diagonal;
            if (diagonal && r > 0) {
                int val = mat1[0][0];
                for (i = 0; i < r; i++) {
                    if (mat1[i][i] != val) scalar = 0;
                }
            }

            utri = 1;
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (i > j && mat1[i][j] != 0) utri = 0;
                }
            }

            ltri = 1;
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (i < j && mat1[i][j] != 0) ltri = 0;
                }
            }

            symm = 1;
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (mat1[i][j] != mat1[j][i]) symm = 0;
                }
            }

            skew = 1;
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    if (mat1[i][j] != -mat1[j][i]) skew = 0;
                }
            }

            int det = 0;
            if (r == 1) det = mat1[0][0];
            else if (r == 2) det = mat1[0][0] * mat1[1][1] - mat1[0][1] * mat1[1][0];

            if (det == 0) sing = 1;
            else nsing = 1;

            if (r == 2) {
                int m2[2][2] = {{0, 0}, {0, 0}};
                int k = 0;
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        for (k = 0; k < 2; k++) {
                            m2[i][j] += mat1[i][k] * mat1[k][j];
                        }
                    }
                }
                idem = 1;
                nilpo = 1;
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        if (m2[i][j] != mat1[i][j]) { idem = 0; }
                        if (m2[i][j] != 0) { nilpo = 0; }
                    }
                }
            }
        }
    }

    printf("\nInformation about your matrix:\n");
    if (r == 1) { printf("- ROW MATRIX\n"); }
    if (c == 1) { printf("- COLUMN MATRIX\n"); }
    if (square == 1) { printf("- SQUARE MATRIX\n"); }
    else { printf("- RECTANGLE MATRIX\n"); }
    if (null == 1) { printf("- NULL MATRIX\n"); }
    if (zero == 1) { printf("- ZERO MATRIX\n"); }
    if (square) {
        if (identity == 1) { printf("- IDENTITY MATRIX\n"); }
        if (diagonal == 1) { printf("- DIAGONAL MATRIX\n"); }
        if (scalar == 1) { printf("- SCALAR MATRIX\n"); }
        if (utri == 1) { printf("- UPPER TRIANGULAR MATRIX\n"); }
        if (ltri == 1) { printf("- LOWER TRIANGULAR MATRIX\n"); }
        if (symm == 1) { printf("- SYMMETRIC MATRIX\n"); }
        if (skew == 1) { printf("- SKEW SYMMETRIC MATRIX\n"); }
        if (sing == 1) { printf("- SINGULAR MATRIX\n"); }
        else { printf("- NON-SINGULAR MATRIX\n"); }
        if (idem == 1) { printf("- IDEMPOTENT MATRIX\n"); }
        if (nilpo == 1) { printf("- NILPOTENT MATRIX\n"); }
    }

    return 0;
}
