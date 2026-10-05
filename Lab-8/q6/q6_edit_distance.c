/* Q6: Edit Distance (Levenshtein) with traceback.
 * D[i][j] = min( D[i-1][j]+1            (delete A[i-1]),
 *                D[i][j-1]+1            (insert B[j-1]),
 *                D[i-1][j-1]+(A[i-1]!=B[j-1])  (match / substitute) )
 * D[i][0]=i, D[0][j]=j.  Traceback from D[m][n] recovers the operations.
 * Time O(m*n), Space O(m*n).   Build: gcc -Wall -O2 q6_edit_distance.c -o q6 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXS 1024

typedef struct { char op; char a, b; } Step;   /* op: M match, S subst, D delete, I insert */

static int min3(int a, int b, int c) { int m = a < b ? a : b; return m < c ? m : c; }

int editDistance(const char *A, const char *B, int verbose)
{
    int m = (int)strlen(A), n = (int)strlen(B), W = n + 1;
    if (m < 0 || n < 0 || m > 100000 || n > 100000) return -1;   /* sanity bound */
    int *D = malloc((size_t)(m + 1) * (size_t)W * sizeof(int));
    if (!D) return -1;
    for (int i = 0; i <= m; i++) D[i * W] = i;
    for (int j = 0; j <= n; j++) D[j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            D[i * W + j] = min3(D[(i - 1) * W + j] + 1, D[i * W + j - 1] + 1,
                                D[(i - 1) * W + j - 1] + (A[i - 1] != B[j - 1]));
    int dist = D[m * W + n];
    if (verbose) {
        Step *st = malloc(((size_t)m + (size_t)n + 1) * sizeof(Step));
        int cnt = 0, i = m, j = n;
        while (i > 0 || j > 0) {
            int cur = D[i * W + j];
            if (i > 0 && j > 0 && A[i - 1] == B[j - 1] && cur == D[(i - 1) * W + j - 1]) { st[cnt++] = (Step){'M', A[i-1], B[j-1]}; i--; j--; }
            else if (i > 0 && j > 0 && cur == D[(i - 1) * W + j - 1] + 1)                { st[cnt++] = (Step){'S', A[i-1], B[j-1]}; i--; j--; }
            else if (i > 0 && cur == D[(i - 1) * W + j] + 1)                              { st[cnt++] = (Step){'D', A[i-1], 0};      i--; }
            else                                                                          { st[cnt++] = (Step){'I', 0, B[j-1]};      j--; }
        }
        printf("  Traceback (A -> B):\n");
        for (int k = cnt - 1; k >= 0; k--) {
            switch (st[k].op) {
                case 'M': printf("    match      '%c'\n", st[k].a); break;
                case 'S': printf("    substitute '%c' -> '%c'\n", st[k].a, st[k].b); break;
                case 'D': printf("    delete     '%c'\n", st[k].a); break;
                case 'I': printf("    insert     '%c'\n", st[k].b); break;
            }
        }
        free(st);
    }
    free(D);
    return dist;
}

static int fails = 0;
static void runCase(const char *A, const char *B, int expected)
{
    printf("A=\"%s\" B=\"%s\"\n", A, B);
    int d = editDistance(A, B, 1);
    printf("  Edit distance = %d", d);
    if (expected >= 0) { printf("  %s", d == expected ? "PASS" : "FAIL"); if (d != expected) fails++; }
    printf("\n");
}

static void readLine(const char *prompt, char *buf, int sz)
{
    printf("%s", prompt);
    if (!fgets(buf, sz, stdin)) { buf[0] = 0; return; }
    buf[strcspn(buf, "\r\n")] = 0;
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        runCase("kitten", "sitting", 3);
        runCase("sunday", "saturday", 3);
        runCase("intention", "execution", 5);
        runCase("", "abc", 3);
        runCase("abc", "", 3);
        runCase("same", "same", 0);
        return fails ? 1 : 0;
    }
    char A[MAXS], B[MAXS];
    readLine("Enter string A: ", A, MAXS);
    readLine("Enter string B: ", B, MAXS);
    runCase(A, B, -1);
    return 0;
}
