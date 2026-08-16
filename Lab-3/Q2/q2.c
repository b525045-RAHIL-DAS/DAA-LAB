#include <stdio.h>

int findDefective(int coins[], int n, int genuine) {

    // No coin left
    if (n == 0)
        return -1;

    // One coin left
    if (n == 1) {
        if (coins[0] < genuine)
            return coins[0];
        else
            return -1;
    }

    int k = n / 2;

    int leftWeight = 0, rightWeight = 0;

    // Calculate weights of two equal groups
    for (int i = 0; i < k; i++) {
        leftWeight += coins[i];
        rightWeight += coins[k + i];
    }

    // Left group is lighter
    if (leftWeight < rightWeight) {
        return findDefective(coins, k, genuine);
    }

    // Right group is lighter
    else if (rightWeight < leftWeight) {
        return findDefective(coins + k, k, genuine);
    }

    // Both groups have equal weight
    else {
        // If n is even, every coin has been checked
        if (n % 2 == 0)
            return -1;

        // One coin remains unweighed
        int remaining = coins[2 * k];

        if (remaining < genuine)
            return remaining;
        else
            return -1;
    }
}

int main() {

    int coins[] = {10, 10, 10, 10, 9, 10, 10};
    int n = 7;

    // Required weight of a genuine coin
    int genuine = 10;

    int defective = findDefective(coins, n, genuine);

    if (defective == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin found with weight: %d\n", defective);

    return 0;
}