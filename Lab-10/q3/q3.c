
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *parent, *sz;
long long *sum;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (sz[a] < sz[b]) {
        int t = a; a = b; b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
    sum[a] += sum[b];
}

int main(void) {
    int n, m, K, u, v;

    printf("Enter N, M and K: ");
    scanf("%d%d%d", &n, &m, &K);

    parent = malloc(n * sizeof(int));
    sz = malloc(n * sizeof(int));
    sum = malloc(n * sizeof(long long));

    printf("Enter vertex weights:\n");

    for (int i = 0; i < n; i++) {
        scanf("%lld", &sum[i]);
        parent[i] = i;
        sz[i] = 1;
    }

    printf("Enter edges (0-based vertices):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge\n");
            continue;
        }

        unite(u, v);

        long long best = LLONG_MIN;
        int found = 0;

        for (int j = 0; j < n; j++) {
            if (find(j) == j && sz[j] <= K) {
                if (!found || sum[j] > best)
                    best = sum[j];
                found = 1;
            }
        }

        if (found)
            printf("Maximum eligible component weight: %lld\n", best);
        else
            printf("No eligible component\n");
    }

    free(parent);
    free(sz);
    free(sum);
    return 0;
}
