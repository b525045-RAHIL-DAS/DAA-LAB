#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0, temp[high - low + 1];
    
    while (i <= mid && j <= high)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
        
    while (i <= mid) temp[k++] = a[i++];
    while (j <= high) temp[k++] = a[j++];
    
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

int main() {
    int n;

    printf("Enter number of persons: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *entries = malloc(n * sizeof(int));
    int *exits = malloc(n * sizeof(int));

    if (!entries || !exits) {
        free(entries);
        free(exits);
        return 1;
    }

    printf("Enter entry and exit times for each person:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &entries[i], &exits[i]);
    }

    mergeSort(entries, 0, n - 1);
    mergeSort(exits, 0, n - 1);

    int current_guests = 0;
    int max_guests = 0;
    int time_of_max = 0;
    int i = 0;
    int j = 0;

    while (i < n && j < n) {
        if (entries[i] < exits[j]) {
            current_guests++;
            if (current_guests > max_guests) {
                max_guests = current_guests;
                time_of_max = entries[i];
            }
            i++;
        } else {
            current_guests--;
            j++;
        }
    }

    printf("Time when most people were simultaneously present: %d\n", time_of_max);
    printf("Maximum people present: %d\n", max_guests);

    free(entries);
    free(exits);

    return 0;
}
