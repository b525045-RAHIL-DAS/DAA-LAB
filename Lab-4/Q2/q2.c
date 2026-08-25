#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return 1;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main() {
    int n, x, found = 0;

    printf("Enter size of each set: ");
    scanf("%d", &n);

    int *S1 = malloc(n * sizeof(int));
    int *S2 = malloc(n * sizeof(int));

    if (S1 == NULL || S2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter elements of S1:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S1[i]);

    printf("Enter elements of S2:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S2[i]);

    printf("Enter x: ");
    scanf("%d", &x);

    mergeSort(S2, 0, n - 1);

    printf("\nPairs whose sum is %d:\n", x);

    for (int i = 0; i < n; i++) {
        int required = x - S1[i];

        if (binarySearch(S2, n, required)) {
            printf("%d + %d = %d\n", S1[i], required, x);
            found = 1;
        }
    }

    if (!found)
        printf("No such pair exists.\n");

    free(S1);
    free(S2);

    return 0;
}
