#include <stdio.h>
int main() {
    int mat[3][3] = {{4, 23, 3}, {4, 7, 6}, {7, 11, 9}};
    int transpose[3][3];
    int co_factors[3][3];
    int ADJ[3][3];
    float INV[3][3];
    int i = 0, j = 0, k = 0, l = 0;
    float det = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            transpose[i][j] = mat[j][i];
        }
    }
    printf("TRANSPOSE\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < 3; i++) {
        float m_d = 1, a_d = 1;
        for (j = 0; j < 3; j++) {
            m_d *= mat[j][(i + j) % 3];
            a_d *= mat[j][(i - j + 3) % 3];
        }
        det += m_d - a_d;
    }
    printf("DETERMINANT\n%.2f\n", det);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int M[2][2];
            int sr = 0;
            for (k = 0; k < 3; k++) {
                if (k == i) continue;
                int sc = 0;
                for (l = 0; l < 3; l++) {
                    if (l == j) continue;
                    M[sr][sc] = mat[k][l];
                    sc++;
                }
                sr++;
            }
            int det2 = M[0][0] * M[1][1] - M[0][1] * M[1][0];
            if ((i + j) % 2 != 0) {
                det2 = det2 * (-1);
            }
            co_factors[i][j] = det2;
        }
    }
    printf("CO-FACTORS\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", co_factors[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            ADJ[j][i] = co_factors[i][j];
        }
    }
    printf("ADJOINT\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", ADJ[i][j]);
        }
        printf("\n");
    }
    if (det == 0) {
        printf("INVERSE IS NOT POSSIBLE :/\n");
    } else {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                INV[i][j] = (float)(ADJ[i][j]) / det;
            }
        }
        
        printf("INVERSE\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%.2f ", INV[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
