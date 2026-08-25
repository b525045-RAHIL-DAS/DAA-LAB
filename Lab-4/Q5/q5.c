#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

void merge(Interval a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    
    Interval *temp = malloc((high - low + 1) * sizeof(Interval));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed in merge function.\n");
        exit(1);
    }

    while (i <= mid && j <= high) {
        if (a[i].start < a[j].start || (a[i].start == a[j].start && a[i].end <= a[j].end)) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }
    
    while (j <= high) {
        temp[k++] = a[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = temp[k];
    }
    
    free(temp);
}

void mergeSort(Interval a[], int low, int high) {
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
        fprintf(stderr, "Invalid number of intervals.\n");
        return 1;
    }

    Interval *intervals = malloc(n * sizeof(Interval));
    if (intervals == NULL) {
        fprintf(stderr, "Memory allocation failed for intervals array.\n");
        return 1;
    }

    printf("Enter the intervals (xi yi):\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &intervals[i].start, &intervals[i].end) != 2) {
            fprintf(stderr, "Invalid input format.\n");
            free(intervals);
            return 1;
        }
    }

    mergeSort(intervals, 0, n - 1);

    Interval *merged = malloc(n * sizeof(Interval));
    if (merged == NULL) {
        fprintf(stderr, "Memory allocation failed for merged array.\n");
        free(intervals);
        return 1;
    }

    merged[0] = intervals[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= merged[count - 1].end) {
            if (intervals[i].end > merged[count - 1].end) {
                merged[count - 1].end = intervals[i].end;
            }
        } else {
            merged[count] = intervals[i];
            count++;
        }
    }

    printf("Merged intervals:\n{");
    for (int i = 0; i < count; i++) {
        printf("(%d, %d)", merged[i].start, merged[i].end);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    free(intervals);
    free(merged);

    return 0;
}
