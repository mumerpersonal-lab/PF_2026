#include <stdio.h>
int main() {
    int arr[3][3][3] = {
        {
            { 2,  5,  8 },
            { 1,  4,  7 },
            { 3,  6,  9 }
        },
        {
            {12, 15, 18 },
            {11, 14, 17 },
            {13, 16, 19 }
        },
        {
            {22, 25, 28 },
            {21, 24, 27 },
            {23, 26, 29 }
        }
    };

    int total_elements = 3 * 3 * 3;
    long long grand_total = 0;
    int global_min = arr[0][0][0];
    int global_max = arr[0][0][0];
    printf("       3x3x3 3D ARRAY ANALYTICS REPORT   \n");
    for (int i = 0; i < 3; i++) {
        long long layer_sum = 0;
        int layer_min = arr[i][0][0];
        int layer_max = arr[i][0][0];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int current_val = arr[i][j][k];
                layer_sum += current_val;
                if (current_val < layer_min) layer_min = current_val;
                if (current_val > layer_max) layer_max = current_val;
                grand_total += current_val;
                if (current_val < global_min) global_min = current_val;
                if (current_val > global_max) global_max = current_val;
            }
        }
        double layer_avg = (double)layer_sum / 9.0;
        printf("--- Layer %d (Depth Index %d) ---\n", i + 1, i);
        printf("  * Layer Total Sum : %lld\n", layer_sum);
        printf("  * Layer Average   : %.2f\n", layer_avg);
        printf("  * Layer Minimum   : %d\n", layer_min);
        printf("  * Layer Maximum   : %d\n", layer_max);
        printf("\n");
    }
    double grand_avg = (double)grand_total / (double)total_elements;
    printf("         OVERALL DATA INSIGHTS           \n");
    printf("  * Total Elements Processed : %d\n", total_elements);
    printf("  * Grand Total Sum          : %lld\n", grand_total);
    printf("  * Overall Average          : %.2f\n", grand_avg);
    printf("  * Global Minimum           : %d\n", global_min);
    printf("  * Global Maximum           : %d\n", global_max);

    return 0;
}
