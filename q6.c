#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    printf("Enter the number of random elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));
    printf("\nGenerated Numbers:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    int duplicate = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate = 1;
                printf("\n\nDuplicate found: %d", arr[i]);
                break;
            }
        }

        if (duplicate)
            break;
    }

    if (!duplicate)
        printf("\n\nAll elements are unique.");

    return 0;
}