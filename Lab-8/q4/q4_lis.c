/* Q4: Longest (strictly) Increasing Subsequence.
 * Method 1 (DP):       dp[i] = 1 + max dp[j] (j<i, a[j]<a[i])   Time O(n^2), Space O(n)
 * Method 2 (tails[]):  tails[k] = smallest tail of an increasing subsequence
 *                      of length k+1; binary search per element Time O(n log n), Space O(n)
 * Both are run and cross-checked.   Build: gcc -Wall -O2 q4_lis.c -o q4 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lisQuadratic(const int a[], int n, int **seq)
{
    int *dp = malloc((size_t)n * sizeof(int)), *prev = malloc((size_t)n * sizeof(int));
    int best = 0, bi = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1; prev[i] = -1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) { dp[i] = dp[j] + 1; prev[i] = j; }
        if (dp[i] > best) { best = dp[i]; bi = i; }
    }
    if (seq) {
        *seq = malloc((size_t)best * sizeof(int));
        int k = best;
        for (int i = bi; i != -1; i = prev[i]) (*seq)[--k] = a[i];
    }
    free(dp); free(prev);
    return best;
}

int lisNlogN(const int a[], int n)
{
    int *tails = malloc((size_t)n * sizeof(int)), len = 0;
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = len;                    /* first tails[idx] >= a[i] */
        while (lo < hi) { int mid = (lo + hi) / 2; if (tails[mid] < a[i]) lo = mid + 1; else hi = mid; }
        tails[lo] = a[i];
        if (lo == len) len++;
    }
    free(tails);
    return len;
}

static int fails = 0;
static void runCase(const int a[], int n, int expected)
{
    int *seq = NULL;
    int r1 = lisQuadratic(a, n, &seq), r2 = lisNlogN(a, n);
    printf("A=[");
    for (int i = 0; i < n; i++) printf("%d%s", a[i], i < n - 1 ? "," : "");
    printf("] -> O(n^2)=%d  O(nlogn)=%d  LIS=[", r1, r2);
    for (int i = 0; i < r1; i++) printf("%d%s", seq[i], i < r1 - 1 ? "," : "");
    printf("]");
    if (expected >= 0) { int ok = (r1 == expected && r2 == expected); printf("  %s", ok ? "PASS" : "FAIL"); if (!ok) fails++; }
    printf("\n");
    free(seq);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        int a[] = {10, 9, 2, 5, 3, 7, 101, 18}; runCase(a, 8, 4);
        int b[] = {0, 1, 0, 3, 2, 3};           runCase(b, 6, 4);
        int c[] = {7, 7, 7, 7};                 runCase(c, 4, 1);
        int d[] = {1, 2, 3, 4, 5};              runCase(d, 5, 5);
        int e[] = {5, 4, 3, 2, 1};              runCase(e, 5, 1);
        int f[] = {42};                         runCase(f, 1, 1);
        return fails ? 1 : 0;
    }
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) { printf("Invalid n\n"); return 1; }
    int *a = malloc((size_t)n * sizeof(int));
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) if (scanf("%d", &a[i]) != 1) { printf("Invalid input\n"); free(a); return 1; }
    runCase(a, n, -1);
    free(a);
    return 0;
}
