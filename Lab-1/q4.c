#include <stdio.h>

int steps = 0;
int hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        steps++;
        
        return steps;
    }

    hanoi(n - 1, A, C, B);

    steps++;
    

    hanoi(n - 1, B, A, C);

    return steps;
}

void plotGraph(int maxDisks)
{
    printf("\nSteps vs Disks Graph\n\n");

    for (int n = 1; n <= maxDisks; n++)
    {
        steps = 0; 
        int s = hanoi(n, 'A', 'B', 'C'); 

        printf("%d disks | ", n);
        for (int i = 0; i < s; i++)
            printf("*");
        printf(" (%d)\n", s);
    }
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    steps = 0;
    hanoi(n, 'A', 'B', 'C'); 
    printf("\nTotal Steps = %d\n", steps);

    plotGraph(n);

    return 0;
}
