#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int n, i;
    int *a;
    FILE *fp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    /*
       Generate random numbers
    */
    srand(time(NULL));

    /*
       Open file for writing
    */
    fp = fopen("numbers.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        free(a);
        return 1;
    }

    printf("Random elements:\n");

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        fprintf(fp, "%d ", a[i]);

        printf("%d ", a[i]);
    }

    fclose(fp);

    /*
       Read elements from file
    */
    fp = fopen("numbers.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        free(a);
        return 1;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    /*
       Apply Quick Sort
    */
    quickSort(a, 0, n - 1);

    printf("\n\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);

    return 0;
}