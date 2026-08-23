#include <stdio.h>

void selectionSort(int A[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main()
{
    int A[] = {64, 25, 12, 22, 11};
    int n = 5;
    int i;

    selectionSort(A, n);

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}