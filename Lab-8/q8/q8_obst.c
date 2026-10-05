/* Q8: Optimal Binary Search Tree (CLRS formulation).
 * Keys k1..kn with probs p[1..n]; dummy keys d0..dn with probs q[0..n].
 *   w[i][j] = w[i][j-1] + p[j] + q[j]
 *   e[i][j] = min over r=i..j of ( e[i][r-1] + e[r+1][j] + w[i][j] ),  e[i][i-1] = q[i-1]
 * root[i][j] stores the optimal root for keys ki..kj.
 * Time O(n^3), Space O(n^2).   Build: gcc -Wall -O2 q8_obst.c -o q8 -lm */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

static int N, S;                       /* S = N+2 : row stride */
#define AT(M, i, j) (M)[(size_t)(i) * S + (j)]

static void printTree(int *root, int i, int j, int parent, const char *side)
{
    if (i > j) { printf("    d%d is the %s child of k%d\n", j, side, parent); return; }
    int r = AT(root, i, j);
    if (parent == 0) printf("    k%d is the root\n", r);
    else             printf("    k%d is the %s child of k%d\n", r, side, parent);
    printTree(root, i, r - 1, r, "left");
    printTree(root, r + 1, j, r, "right");
}

double obst(const double p[], const double q[], int n, int verbose)
{
    N = n; S = n + 2;
    double *e = calloc((size_t)S * S, sizeof(double)), *w = calloc((size_t)S * S, sizeof(double));
    int *root = calloc((size_t)S * S, sizeof(int));
    for (int i = 1; i <= n + 1; i++) { AT(e, i, i - 1) = q[i - 1]; AT(w, i, i - 1) = q[i - 1]; }
    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            AT(e, i, j) = DBL_MAX;
            AT(w, i, j) = AT(w, i, j - 1) + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                double t = AT(e, i, r - 1) + AT(e, r + 1, j) + AT(w, i, j);
                if (t < AT(e, i, j)) { AT(e, i, j) = t; AT(root, i, j) = r; }
            }
        }
    double res = AT(e, 1, n);
    if (verbose) { printf("  Optimal tree structure:\n"); printTree(root, 1, n, 0, ""); }
    free(e); free(w); free(root);
    return res;
}

static int fails = 0;
static void runCase(const double p[], const double q[], int n, double expected)
{
    double c = obst(p, q, n, 1);
    printf("  n=%d -> minimum expected search cost = %.4f", n, c);
    if (expected >= 0) { int ok = fabs(c - expected) < 1e-6; printf("  %s", ok ? "PASS" : "FAIL"); if (!ok) fails++; }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        double p1[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
        double q1[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
        runCase(p1, q1, 5, 2.75);
        double p2[] = {0, 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14};
        double q2[] = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};
        runCase(p2, q2, 7, 3.12);
        double p3[] = {0, 0.5};
        double q3[] = {0.25, 0.25};
        runCase(p3, q3, 1, 1.5);
        return fails ? 1 : 0;
    }
    int n;
    printf("Enter number of keys n: ");
    if (scanf("%d", &n) != 1 || n <= 0) { printf("Invalid n\n"); return 1; }
    double *p = calloc((size_t)n + 1, sizeof(double)), *q = calloc((size_t)n + 1, sizeof(double));
    printf("Enter p1..p%d: ", n);
    for (int i = 1; i <= n; i++) if (scanf("%lf", &p[i]) != 1) { printf("Invalid\n"); return 1; }
    printf("Enter q0..q%d: ", n);
    for (int i = 0; i <= n; i++) if (scanf("%lf", &q[i]) != 1) { printf("Invalid\n"); return 1; }
    runCase(p, q, n, -1);
    free(p); free(q);
    return 0;
}
