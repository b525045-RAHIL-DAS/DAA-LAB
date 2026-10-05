/* Q1: Minimum Coin Change - bottom-up DP.
 * dp[v] = min coins for amount v;  dp[v] = min(dp[v-c]+1) over coins c<=v.
 * Time O(n*V), Space O(V).   Build: gcc -Wall -O2 q1_min_coin_change.c -o q1 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF INT_MAX

int minCoins(const int coins[], int n, int V, int **out, int *outLen)
{
    if (out) *out = NULL;
    if (outLen) *outLen = 0;
    if (n <= 0 || V < 0) return -1;
    if (V == 0) return 0;
    int *dp = malloc((size_t)(V + 1) * sizeof(int));
    int *used = malloc((size_t)(V + 1) * sizeof(int));
    if (!dp || !used) { free(dp); free(used); return -1; }
    dp[0] = 0; used[0] = 0;
    for (int v = 1; v <= V; v++) { dp[v] = INF; used[v] = 0; }
    for (int v = 1; v <= V; v++)
        for (int i = 0; i < n; i++) {
            int c = coins[i];
            if (c > 0 && c <= v && dp[v - c] != INF && dp[v - c] + 1 < dp[v]) {
                dp[v] = dp[v - c] + 1; used[v] = c;
            }
        }
    int res = (dp[V] == INF) ? -1 : dp[V];
    if (res > 0 && out && outLen) {
        int *list = malloc((size_t)res * sizeof(int));
        if (list) {
            int v = V, k = 0;
            while (v > 0) { list[k++] = used[v]; v -= used[v]; }
            *out = list; *outLen = k;
        }
    }
    free(dp); free(used);
    return res;
}

static int fails = 0;
static void runCase(const int coins[], int n, int V, int expected)
{
    int *sol = NULL, len = 0;
    int r = minCoins(coins, n, V, &sol, &len);
    printf("coins={");
    for (int i = 0; i < n; i++) printf("%d%s", coins[i], i < n - 1 ? "," : "");
    printf("} V=%d -> %d", V, r);
    if (r > 0) { printf("  ["); for (int i = 0; i < len; i++) printf("%d%s", sol[i], i < len - 1 ? "+" : ""); printf("]"); }
    if (expected != -2) { printf("  %s", r == expected ? "PASS" : "FAIL"); if (r != expected) fails++; }
    printf("\n");
    free(sol);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        int a[] = {1, 2, 5};  runCase(a, 3, 11, 3);
        int b[] = {2};        runCase(b, 1, 3, -1);
        int c[] = {1, 3, 4};  runCase(c, 3, 6, 2);
        int d[] = {5, 10};    runCase(d, 2, 0, 0);
        int e[] = {186, 419, 83, 408}; runCase(e, 4, 6249, 20);
        int g[] = {3, 7};     runCase(g, 2, 5, -1);
        return fails ? 1 : 0;
    }
    int n, V;
    printf("Enter number of denominations n: ");
    if (scanf("%d", &n) != 1 || n <= 0) { printf("Invalid n\n"); return 1; }
    int *coins = malloc((size_t)n * sizeof(int));
    printf("Enter %d coin values: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &coins[i]) != 1 || coins[i] <= 0) { printf("Invalid coin\n"); free(coins); return 1; }
    printf("Enter target amount V: ");
    if (scanf("%d", &V) != 1 || V < 0) { printf("Invalid V\n"); free(coins); return 1; }
    runCase(coins, n, V, -2);
    free(coins);
    return 0;
}
