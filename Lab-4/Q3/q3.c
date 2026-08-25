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

int binarySearch(int a[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            return 1;
        }
        if (a[mid] < key) low = mid + 1; else high = mid - 1;
    }
    return 0;
}

void findSum(int a[], int n, int k, int target, int start, int count, int sum, int selected[], int *found) {
    if (count == k - 1) {
        int req = target - sum;
        if (binarySearch(a, start, n - 1, req)) {
            printf(" ");
            for (int i = 0; i < k - 1; i++) printf("%d + ", selected[i]);
            printf("%d = %d\n", req, target);
            *found = 1;
        }
        return;
    }

    for (int i = start; i < n; i++) {
        selected[count] = a[i];
        findSum(a, n, k, target, i + 1, count + 1, sum + a[i], selected, found);
    }
}

int main() {
    int n, k, T, found = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *S = malloc(n * sizeof(int));
    if (!S) {
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    printf("Enter k: "); 
    scanf("%d", &k);
    
    printf("Enter T: "); 
    scanf("%d", &T);

    if (k <= 0 || k > n) { 
        free(S); 
        return 1; 
    }

    int *selected = malloc(k * sizeof(int));
    if (!selected) { 
        free(S); 
        return 1; 
    }

    mergeSort(S, 0, n - 1);

    printf("\nGroups of %d elements whose sum is %d:\n", k, T);
    findSum(S, n, k, T, 0, 0, 0, selected, &found);

    if (!found) printf("No such group exists.\n");

    free(S);
    free(selected);

    return 0;
}
