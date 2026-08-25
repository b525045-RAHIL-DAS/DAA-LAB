#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int *temp = malloc((high - low + 1) * sizeof(int));
    
    if (temp == NULL) {
        exit(1);
    }
    
    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    
    while (i <= mid) temp[k++] = a[i++];
    while (j <= high) temp[k++] = a[j++];
    
    for (i = low, k = 0; i <= high; i++, k++) 
        a[i] = temp[k];
        
    free(temp);
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *lefts = malloc(n * sizeof(int));
    int *rights = malloc(n * sizeof(int));

    if (lefts == NULL || rights == NULL) {
        return 1;
    }

    printf("Enter the intervals (li ri):\n");
    for (int k = 0; k < n; k++) {
        if (scanf("%d %d", &lefts[k], &rights[k]) != 2) {
            free(lefts);
            free(rights);
            return 1;
        }
    }

    mergeSort(lefts, 0, n - 1);
    mergeSort(rights, 0, n - 1);

    int current_overlap = 0;
    int max_overlap = 0;
    int best_point = 0;
    int i = 0;
    int j = 0;

    while (i < n && j < n) {
        if (lefts[i] <= rights[j]) {
            current_overlap++;
            if (current_overlap > max_overlap) {
                max_overlap = current_overlap;
                best_point = lefts[i];
            }
            i++;
        } else {
            current_overlap--;
            j++;
        }
    }

    printf("Point in the largest number of intervals: %d\n", best_point);
    printf("Number of overlapping intervals at this point: %d\n", max_overlap);

    free(lefts);
    free(rights);

    return 0;
}
