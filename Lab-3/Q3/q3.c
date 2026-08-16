#include <stdio.h>

int comparisons = 0;

void findMaxMin(int A[], int low, int high, int *max, int *min)
{
    int max1, min1, max2, min2, mid;

    // Only one element
    if (low == high)
    {
        *max = A[low];
        *min = A[low];
        return;
    }

    // Two elements
    if (high == low + 1)
    {
        comparisons++;

        if (A[low] > A[high])
        {
            *max = A[low];
            *min = A[high];
        }
        else
        {
            *max = A[high];
            *min = A[low];
        }

        return;
    }

    // Divide
    mid = (low + high) / 2;

    // Conquer
    findMaxMin(A, low, mid, &max1, &min1);
    findMaxMin(A, mid + 1, high, &max2, &min2);

    // Combine - find maximum
    comparisons++;
    if (max1 > max2)
        *max = max1;
    else
        *max = max2;

    // Combine - find minimum
    comparisons++;
    if (min1 < min2)
        *min = min1;
    else
        *min = min2;
}

int main()
{
    int n, max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    findMaxMin(A, 0, n - 1, &max, &min);

    printf("\nMaximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}