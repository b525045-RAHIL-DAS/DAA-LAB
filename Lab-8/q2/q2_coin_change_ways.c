/* Q2: Coin Change - number of distinct combinations (order ignored).
 * dp[v] = number of ways to make v using coins processed so far.
 * Outer loop over COINS, inner over amounts => each combination counted once
 * (swapping the loops would count permutations instead).
 * Time O(n*V), Space O(V).   Build: gcc -Wall -O2 q2_coin_change_ways.c -o q2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ull;

ull countWays(const int c[], int n, int V)
{
    if (n <= 0 || V < 0) return 0;
    ull *dp = calloc((size_t)V + 1, sizeof(ull));
    if (!dp) return 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (c[i] <= 0) continue;
        for (int v = c[i]; v <= V; v++) dp[v] += dp[v - c[i]];
    }
    ull r = dp[V];
    free(dp);
    return r;
}

static int fails = 0;
static void runCase(const int c[], int n, int V, long long expected)
{
    ull r = countWays(c, n, V);
    printf("coins={");
    for (int i = 0; i < n; i++) printf("%d%s", c[i], i < n - 1 ? "," : "");
    printf("} V=%d -> %llu", V, r);
    if (expected >= 0) { printf("  %s", (ull)expected == r ? "PASS" : "FAIL"); if ((ull)expected != r) fails++; }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        int a[] = {1, 2, 5};  runCase(a, 3, 5, 4);
        int b[] = {2};        runCase(b, 1, 3, 0);
        int c[] = {1, 2, 3};  runCase(c, 3, 4, 4);
        int d[] = {10};       runCase(d, 1, 10, 1);
        int e[] = {2, 5, 3, 6}; runCase(e, 4, 10, 5);
        int f[] = {1, 2, 5};  runCase(f, 3, 0, 1);
        return fails ? 1 : 0;
    }
    int n, V;
    printf("Enter number of denominations n: ");
    if (scanf("%d", &n) != 1 || n <= 0) { printf("Invalid n\n"); return 1; }
    int *c = malloc((size_t)n * sizeof(int));
    printf("Enter %d distinct positive coin values: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &c[i]) != 1 || c[i] <= 0) { printf("Invalid coin\n"); free(c); return 1; }
    printf("Enter target amount V: ");
    if (scanf("%d", &V) != 1 || V < 0) { printf("Invalid V\n"); free(c); return 1; }
    runCase(c, n, V, -1);
    free(c);
    return 0;
}
