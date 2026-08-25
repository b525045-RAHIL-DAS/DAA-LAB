#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    char colour;
} Item;

void sortByColour(Item items[], int n) {
    Item *output = malloc(n * sizeof(Item));

    int r = 0, b = 0, y = 0;

    for (int i = 0; i < n; i++) {
        if (items[i].colour == 'R')
            r++;
        else if (items[i].colour == 'B')
            b++;
        else if (items[i].colour == 'Y')
            y++;
    }

    int p = 0;

    for (int i = 0; i < n; i++) {
        if (items[i].colour == 'R')
            output[p++] = items[i];
    }

    for (int i = 0; i < n; i++) {
        if (items[i].colour == 'B')
            output[p++] = items[i];
    }

    for (int i = 0; i < n; i++) {
        if (items[i].colour == 'Y')
            output[p++] = items[i];
    }

    for (int i = 0; i < n; i++)
        items[i] = output[i];

    free(output);
}

void printItems(Item items[], int n) {
    for (int i = 0; i < n; i++)
        printf("(%d, %c) ", items[i].number, items[i].colour);

    printf("\n");
}

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item *items = malloc(n * sizeof(Item));

    printf("Enter %d pairs (number colour):\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d %c", &items[i].number, &items[i].colour);

    printf("\nInput:\n");
    printItems(items, n);

    sortByColour(items, n);

    printf("\nOutput (R < B < Y):\n");
    printItems(items, n);

    free(items);

    return 0;
}
