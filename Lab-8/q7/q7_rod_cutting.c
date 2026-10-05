/* Q7: Rod Cutting with reconstruction.
 * r[j] = max over i=1..j of ( p[i] + r[j-i] ),  r[0]=0;  s[j] = best first cut.
 * Prices are 1-indexed: p[i] = price of a piece of length i.
 * Time O(n^2), Space O(n).   Build: gcc -Wall -O2 q7_rod_cutting.c -o q7 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* p has n+1 entries (p[0] unused). Returns max revenue; pieces written to out (count in *cnt). */
long long rodCut(const int p[], int n, int **out, int *cnt)
{
    long long *r = calloc((size_t)n + 1, sizeof(long long));
    int *s = calloc((size_t)n + 1, sizeof(int));
    for (int j = 1; j <= n; j++) {
        long long q = -1;
        for (int i = 1; i <= j; i++)
            if (p[i] + r[j - i] > q) { q = p[i] + r[j - i]; s[j] = i; }
        r[j] = q;
    }
    int c = 0;
    for (int j = n; j > 0; j -= s[j]) c++;
    *out = malloc((size_t)(c ? c : 1) * sizeof(int));
    *cnt = c;
    int k = 0;
    for (int j = n; j > 0; j -= s[j]) (*out)[k++] = s[j];
    long long best = r[n];
    free(r); free(s);
    return best;
}

static int fails = 0;
static void runCase(const int p[], int n, long long expected)
{
    int *pieces, cnt;
    long long rev = rodCut(p, n, &pieces, &cnt);
    printf("n=%d -> max revenue=%lld  pieces=[", n, rev);
    for (int i = 0; i < cnt; i++) printf("%d%s", pieces[i], i < cnt - 1 ? "+" : "");
    printf("]");
    if (expected >= 0) { printf("  %s", rev == expected ? "PASS" : "FAIL"); if (rev != expected) fails++; }
    printf("\n");
    free(pieces);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};   /* CLRS price table */
        runCase(p, 1, 1);
        runCase(p, 4, 10);
        runCase(p, 7, 18);
        runCase(p, 8, 22);
        runCase(p, 10, 30);
        int q[] = {0, 3, 5, 8, 9, 10, 17, 17, 20};
        runCase(q, 8, 24);                                    /* eight 1-inch pieces */
        return fails ? 1 : 0;
    }
    int n;
    printf("Enter rod length n: ");
    if (scanf("%d", &n) != 1 || n <= 0) { printf("Invalid n\n"); return 1; }
    int *p = calloc((size_t)n + 1, sizeof(int));
    printf("Enter prices p1..p%d: ", n);
    for (int i = 1; i <= n; i++) if (scanf("%d", &p[i]) != 1) { printf("Invalid input\n"); free(p); return 1; }
    runCase(p, n, -1);
    free(p);
    return 0;
}
