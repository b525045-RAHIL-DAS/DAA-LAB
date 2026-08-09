#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long optimized(int arr[], int n)
{
    long comparisons = 0;
    int swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    return comparisons;
}

long normal(int arr[], int n)
{
    long comparisons = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

int main()
{
    srand(time(NULL));

    int sizes[] = {10, 20, 30, 40, 50};
    int numSizes = 5;

    printf("%-6s %-12s %-12s\n", "n", "Optimized", "Normal");

    for (int k = 0; k < numSizes; k++)
    {
        int n = sizes[k];
        int a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            int r = rand() % 1000;
            a[i] = r;
            b[i] = r;
        }

        long opt = optimized(a, n);
        long norm = normal(b, n);

        printf("%-6d %-12ld %-12ld\n", n, opt, norm);

        printf("  optimized | ");
        for (int i = 0; i < opt / 25; i++)
            printf("*");
        printf(" (%ld)\n", opt);

        printf("  normal    | ");
        for (int i = 0; i < norm / 25; i++)
            printf("#");
        printf(" (%ld)\n\n", norm);
    }

    return 0;
}
