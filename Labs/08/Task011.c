#include <stdio.h>

int square(int x)
{
    return x * x;
}

int negate(int x)
{
    return -x;
}

int isEven(int x)
{
    return x % 2 == 0;
}

int isPositive(int x)
{
    return x > 0;
}

void applyToArray(int *arr, int n, int (*fn)(int))
{
    int i;

    for (i = 0; i < n; i++)
        *(arr + i) = fn(*(arr + i));
}

int countIf(const int *arr, int n, int (*pred)(int))
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        if (pred(*(arr + i)))
            count++;
    }

    return count;
}

void printGeneric(void *data, char type, int n)
{
    int i;

    if (type == 'i')
    {
        int *arr = (int *)data;

        for (i = 0; i < n; i++)
            printf("%d ", *(arr + i));
    }
    else if (type == 'f')
    {
        float *arr = (float *)data;

        for (i = 0; i < n; i++)
            printf("%.2f ", *(arr + i));
    }
    else if (type == 'c')
    {
        char *arr = (char *)data;

        for (i = 0; i < n; i++)
            printf("%c ", *(arr + i));
    }
    else
    {
        printf("Invalid type '%c' for printGeneric", type);
        return;
    }

    printf("\n");
}

int main()
{
    int arr[50] = {3, -2, 8, -5, 6};
    float values[] = {1.50, 2.25};
    int n, i;

    do
    {
        printf("Enter n (1-50): ");
        scanf("%d", &n);

        if (n < 1 || n > 50)
            printf("Invalid number\n");

    } while (n < 1 || n > 50);

    printf("Original: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    applyToArray(arr, n, negate);

    printf("After negate: ");

    printGeneric(arr, 'i', n);

    printf("Positive values after negate: %d\n",
           countIf(arr, n, isPositive));

    printf("Even values after negate: %d\n",
           countIf(arr, n, isEven));

    printf("Float print (type f): ");
    printGeneric(values, 'f', 2);

    printGeneric(arr, 'x', n);

    return 0;
}