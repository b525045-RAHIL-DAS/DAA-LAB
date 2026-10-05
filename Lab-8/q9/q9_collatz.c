/* Q9: Collatz (3n+1) trajectory analysis - modular C program.
 *   T(n) = n/2 if n even, 3n+1 if n odd.
 * Modules: collatzNext (with overflow detection), trajectory (dynamic array),
 *          analyzeInterval (statistics over [a,b]).
 * Overflow handling: before computing 3n+1 we check n <= (ULLONG_MAX-1)/3.
 * Time per start value n = O(L(n)) where L = number of steps (unproven bound);
 * interval [a,b] = O(sum of L(n)).   Space: O(L) for a stored trajectory, O(1) for the interval scan.
 * Build: gcc -Wall -O2 q9_collatz.c -o q9 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef unsigned long long ull;

/* returns 0 on success, 1 on overflow */
int collatzNext(ull n, ull *next)
{
    if (n % 2 == 0) { *next = n / 2; return 0; }
    if (n > (ULLONG_MAX - 1) / 3) return 1;
    *next = 3 * n + 1;
    return 0;
}

typedef struct { ull *seq; size_t len; ull peak; int overflow; } Trajectory;

Trajectory trajectory(ull n)
{
    Trajectory t = {0};
    size_t cap = 64;
    t.seq = malloc(cap * sizeof(ull));
    ull x = n; t.peak = n;
    t.seq[t.len++] = x;
    while (x != 1) {
        ull nx;
        if (collatzNext(x, &nx)) { t.overflow = 1; break; }
        x = nx;
        if (x > t.peak) t.peak = x;
        if (t.len == cap) { cap *= 2; t.seq = realloc(t.seq, cap * sizeof(ull)); }
        t.seq[t.len++] = x;
    }
    return t;
}

/* steps only (no storage); returns -1 on overflow; *peak gets the max value */
long stepsOnly(ull n, ull *peak)
{
    long s = 0; ull x = n; *peak = n;
    while (x != 1) {
        ull nx;
        if (collatzNext(x, &nx)) return -1;
        x = nx; s++;
        if (x > *peak) *peak = x;
    }
    return s;
}

void analyzeInterval(ull a, ull b)
{
    long bestSteps = -1; ull bestN = a, highPeak = 0, highN = a;
    double total = 0; ull cnt = 0, overflows = 0;
    for (ull n = a; n <= b; n++) {
        ull pk;
        long s = stepsOnly(n, &pk);
        if (s < 0) { overflows++; continue; }
        if (s > bestSteps) { bestSteps = s; bestN = n; }
        if (pk > highPeak) { highPeak = pk; highN = n; }
        total += (double)s; cnt++;
    }
    printf("Interval [%llu, %llu]\n", a, b);
    printf("  Longest trajectory : n=%llu with %ld steps\n", bestN, bestSteps);
    printf("  Highest peak       : n=%llu reaches %llu\n", highN, highPeak);
    printf("  Average steps      : %.3f over %llu values\n", cnt ? total / cnt : 0.0, cnt);
    printf("  Overflow cases     : %llu\n", overflows);
}

static int fails = 0;
static void check(const char *name, int ok) { printf("  %-34s %s\n", name, ok ? "PASS" : "FAIL"); if (!ok) fails++; }

static void runTests(void)
{
    ull pk;
    check("steps(1) == 0", stepsOnly(1, &pk) == 0);
    check("steps(6) == 8", stepsOnly(6, &pk) == 8);
    check("steps(27) == 111", stepsOnly(27, &pk) == 111);
    check("peak(27) == 9232", (stepsOnly(27, &pk), pk == 9232));
    check("steps(97) == 118", stepsOnly(97, &pk) == 118);
    Trajectory t = trajectory(6);
    check("trajectory(6) = 6 3 10 5 16 8 4 2 1", t.len == 9 && t.seq[1] == 3 && t.seq[8] == 1);
    free(t.seq);
    check("overflow detected near ULLONG_MAX", stepsOnly(ULLONG_MAX, &pk) == -1);
    printf("\n"); analyzeInterval(1, 100);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) { runTests(); return fails ? 1 : 0; }
    int choice;
    printf("1) Trajectory of a single n\n2) Analyse interval [a,b]\nChoice: ");
    if (scanf("%d", &choice) != 1) return 1;
    if (choice == 1) {
        ull n;
        printf("Enter n >= 1: ");
        if (scanf("%llu", &n) != 1 || n < 1) { printf("Invalid n\n"); return 1; }
        Trajectory t = trajectory(n);
        for (size_t i = 0; i < t.len; i++) printf("%llu%s", t.seq[i], i + 1 < t.len ? " -> " : "\n");
        printf("Steps: %zu   Peak: %llu%s\n", t.len - 1, t.peak, t.overflow ? "   (STOPPED: overflow)" : "");
        free(t.seq);
    } else if (choice == 2) {
        ull a, b;
        printf("Enter a b (1 <= a <= b): ");
        if (scanf("%llu %llu", &a, &b) != 2 || a < 1 || a > b) { printf("Invalid interval\n"); return 1; }
        analyzeInterval(a, b);
    } else printf("Invalid choice\n");
    return 0;
}
