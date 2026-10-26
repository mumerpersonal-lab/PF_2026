#include <stdio.h>

float averageSteps(int *steps, int n)
{
    int i;
    float sum = 0;

    for (i = 0; i < n; i++)
        sum = sum + *(steps + i);

    return sum / n;
}

int countGoalDays(int *steps, int n, int goal)
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        if (*(steps + i) >= goal)
            count++;
    }

    return count;
}

int main()
{
    int steps[7];
    int i;

    for (i = 0; i < 7; i++)
    {
        printf("Enter steps for day %d: ", i + 1);
        scanf("%d", &steps[i]);
    }

    printf("Average steps: %.2f\n", averageSteps(steps, 7));

    printf("Days goal reached (8000 or more): %d\n",
           countGoalDays(steps, 7, 8000));

    return 0;
}