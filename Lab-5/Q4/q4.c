#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
   Heapify subtree rooted at index i
*/
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    /*
       Check left child
    */
    if (left < n && a[left] > a[largest])
        largest = left;

    /*
       Check right child
    */
    if (right < n && a[right] > a[largest])
        largest = right;

    /*
       If largest is not root
    */
    if (largest != i)
    {
        swap(&a[i], &a[largest]);

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i;

    /*
       Build Max Heap
    */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /*
       Extract elements one by one
    */
    for (i = n - 1; i > 0; i--)
    {
        /*
           Move largest element to end
        */
        swap(&a[0], &a[i]);

        /*
           Heapify remaining heap
        */
        heapify(a, i, 0);
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
       Store random numbers in file
    */
    fp = fopen("heap_numbers.txt", "w");

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
       Read numbers from file
    */
    fp = fopen("heap_numbers.txt", "r");

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
       Heap Sort
    */
    heapSort(a, n);

    printf("\n\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);

    return 0;
}