/* Q3: Longest Common Subsequence with reconstruction.
 * L[i][j] = LCS length of X[0..i-1], Y[0..j-1]
 *   = L[i-1][j-1]+1                if X[i-1]==Y[j-1]
 *   = max(L[i-1][j], L[i][j-1])    otherwise
 * Reconstruction walks back from L[m][n].
 * Time O(m*n), Space O(m*n).   Build: gcc -Wall -O2 q3_lcs.c -o q3 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXS 1024

/* returns malloc'd LCS string; *len gets its length */
char *lcs(const char *X, const char *Y, int *len)
{
    int m = (int)strlen(X), n = (int)strlen(Y), W = n + 1;
    int *L = calloc((size_t)(m + 1) * W, sizeof(int));
    if (!L) return NULL;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) L[i * W + j] = L[(i - 1) * W + j - 1] + 1;
            else {
                int u = L[(i - 1) * W + j], l = L[i * W + j - 1];
                L[i * W + j] = u > l ? u : l;
            }
        }
    int k = L[m * W + n];
    char *s = malloc((size_t)k + 1);
    s[k] = '\0';
    int i = m, j = n, p = k;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) { s[--p] = X[i - 1]; i--; j--; }
        else if (L[(i - 1) * W + j] >= L[i * W + j - 1]) i--;
        else j--;
    }
    *len = k;
    free(L);
    return s;
}

static int fails = 0;
static void runCase(const char *X, const char *Y, int expectedLen)
{
    int len; char *s = lcs(X, Y, &len);
    printf("X=\"%s\" Y=\"%s\" -> length=%d LCS=\"%s\"", X, Y, len, s);
    if (expectedLen >= 0) { printf("  %s", len == expectedLen ? "PASS" : "FAIL"); if (len != expectedLen) fails++; }
    printf("\n");
    free(s);
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
        runCase("ABCBDAB", "BDCABA", 4);
        runCase("AGGTAB", "GXTXAYB", 4);
        runCase("ABC", "DEF", 0);
        runCase("", "ABC", 0);
        runCase("ABC", "ABC", 3);
        return fails ? 1 : 0;
    }
    char X[MAXS], Y[MAXS];
    readLine("Enter sequence X: ", X, MAXS);
    readLine("Enter sequence Y: ", Y, MAXS);
    runCase(X, Y, -1);
    return 0;
}
