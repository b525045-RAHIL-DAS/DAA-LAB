/* Q5: Maximum Sum Increasing Subsequence.
 * S[i] = a[i] + max(0, max S[j] for j<i with a[j]<a[i]);  answer = max S[i].
 * Time O(n^2), Space O(n).   Build: gcc -Wall -O2 q5_msis.c -o q5 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;

ll msis(const int a[], int n, int **seq, int *len)
{
    ll *S = malloc((size_t)n * sizeof(ll));
    int *prev = malloc((size_t)n * sizeof(int));
    ll best = 0; int bi = -1;
    for (int i = 0; i < n; i++) {
        S[i] = a[i]; prev[i] = -1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && S[j] + a[i] > S[i]) { S[i] = S[j] + a[i]; prev[i] = j; }
        if (S[i] > best) { best = S[i]; bi = i; }
    }
    int cnt = 0;
    for (int i = bi; i != -1; i = prev[i]) cnt++;
    *seq = malloc((size_t)cnt * sizeof(int));
    *len = cnt;
    int k = cnt;
    for (int i = bi; i != -1; i = prev[i]) (*seq)[--k] = a[i];
    free(S); free(prev);
    return best;
}

static int fails = 0;
static void runCase(const int a[], int n, ll expected)
{
    int *seq, len;
    ll r = msis(a, n, &seq, &len);
    printf("A=[");
    for (int i = 0; i < n; i++) printf("%d%s", a[i], i < n - 1 ? "," : "");
    printf("] -> max sum=%lld  subsequence=[", r);
    for (int i = 0; i < len; i++) printf("%d%s", seq[i], i < len - 1 ? "," : "");
    printf("]");
    if (expected >= 0) { printf("  %s", r == expected ? "PASS" : "FAIL"); if (r != expected) fails++; }
    printf("\n");
    free(seq);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        int a[] = {1, 101, 2, 3, 100, 4, 5}; runCase(a, 7, 106);
        int b[] = {3, 4, 5, 10};             runCase(b, 4, 22);
        int c[] = {10, 5, 4, 3};             runCase(c, 4, 10);
        int d[] = {1, 2, 3};                 runCase(d, 3, 6);
        int e[] = {5, 5, 5};                 runCase(e, 3, 5);
        return fails ? 1 : 0;
    }
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) { printf("Invalid n\n"); return 1; }
    int *a = malloc((size_t)n * sizeof(int));
    printf("Enter %d positive integers: ", n);
    for (int i = 0; i < n; i++) if (scanf("%d", &a[i]) != 1 || a[i] <= 0) { printf("Invalid input\n"); free(a); return 1; }
    runCase(a, n, -1);
    free(a);
    return 0;
}
