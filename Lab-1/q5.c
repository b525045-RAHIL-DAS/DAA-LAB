#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array (0's followed by 1's):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int low = 0, high = n - 1;
    int partition = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == 1)
        {
            partition = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (partition == -1)
        printf("Array contains only 0's.\n");
    else if (partition == 0)
        printf("Array contains only 1's.\n");
    else
        printf("Partition point is at index %d.\n", partition);

    return 0;
}
