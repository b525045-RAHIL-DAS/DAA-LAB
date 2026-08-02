#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int fairHeads = 0, fairTails = 0;
    int biasedHeads = 0, biasedTails = 0;

    printf("Enter number of coin tosses: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        if (rand() % 2 == 0)
            fairHeads++;
        else
            fairTails++;
    }
    for (int i = 0; i < n; i++)
    {
        if (rand() % 10 < 7)   
            biasedHeads++;
        else                   
            biasedTails++;
    }
    printf("Heads = %d\n", fairHeads);
    printf("Tails = %d\n", fairTails);
    printf("Estimated P(Head) = %.5f\n", (double)fairHeads / n);
    printf("Heads = %d\n", biasedHeads);
    printf("Tails = %d\n", biasedTails);
    printf("Estimated P(Head) = %.5f\n", (double)biasedHeads / n);

    return 0;
}