#include <stdio.h>

int binarySearch(int A[], int n, int x, int *count)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        (*count)++;
        int mid = low + (high - low) / 2;

        if (A[mid] == x)
            return mid;

        (*count)++;

        if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int ternarySearch(int A[], int n, int x, int *count)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        (*count)++;

        if (A[mid1] == x)
            return mid1;

        (*count)++;

        if (A[mid2] == x)
            return mid2;

        (*count)++;

        if (x < A[mid1])
            high = mid1 - 1;

        else if (x > A[mid2])
            low = mid2 + 1;

        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    int A[100], n, x, i;
    int bCount = 0, tCount = 0;
    int bResult, tResult;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    bResult = binarySearch(A, n, x, &bCount);
    tResult = ternarySearch(A, n, x, &tCount);

    if (bResult != -1)
        printf("\nBinary Search: Element found at index %d", bResult);
    else
        printf("\nBinary Search: Element not found");

    if (tResult != -1)
        printf("\nTernary Search: Element found at index %d", tResult);
    else
        printf("\nTernary Search: Element not found");

    printf("\n\nBinary Search comparisons: %d", bCount);
    printf("\nTernary Search comparisons: %d", tCount);

    if (bCount < tCount)
        printf("\nBinary Search is better.");
    else if (tCount < bCount)
        printf("\nTernary Search is better.");
    else
        printf("\nBoth used the same number of comparisons.");

    return 0;
}