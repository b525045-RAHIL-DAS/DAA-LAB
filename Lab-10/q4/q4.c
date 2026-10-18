
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *parent, *sz, *active;
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

long long getMax(int n) {
    long long best = LLONG_MIN;
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (active[i] && find(i) == i) {
            if (!found || sum[i] > best)
                best = sum[i];
            found = 1;
        }
    }

    return found ? best : 0;
}

int main(void) {
    int n, m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    parent = malloc(n * sizeof(int));
    sz = malloc(n * sizeof(int));
    active = calloc(n, sizeof(int));
    sum = calloc(n, sizeof(long long));

    long long *weight = malloc(n * sizeof(long long));
    int *head = malloc(n * sizeof(int));
    int *to = malloc(2 * m * sizeof(int));
    int *next = malloc(2 * m * sizeof(int));

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
        head[i] = -1;
    }

    printf("Enter vertex weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%lld", &weight[i]);

    int e = 0;
    printf("Enter edges (0-based vertices):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge\n");
            return 1;
        }

        to[e] = v;
        next[e] = head[u];
        head[u] = e++;

        to[e] = u;
        next[e] = head[v];
        head[v] = e++;
    }

    int *p = malloc(n * sizeof(int));
    long long *ans = malloc(n * sizeof(long long));

    printf("Enter deletion order (0-based vertices):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (int i = 0; i < n; i++) {
        if (p[i] < 0 || p[i] >= n) {
            printf("Invalid deletion order\n");
            return 1;
        }
        for (int j = 0; j < i; j++) {
            if (p[j] == p[i]) {
                printf("Deletion order must be a permutation\n");
                return 1;
            }
        }
    }

    ans[n - 1] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int x = p[i];

        active[x] = 1;
        sum[x] = weight[x];

        for (int j = head[x]; j != -1; j = next[j]) {
            int y = to[j];
            if (active[y])
                unite(x, y);
        }

        if (i > 0)
            ans[i - 1] = getMax(n);
    }

    printf("Maximum component weight after each deletion:\n");
    for (int i = 0; i < n; i++)
        printf("%lld\n", ans[i]);

    free(parent);
    free(sz);
    free(active);
    free(sum);
    free(weight);
    free(head);
    free(to);
    free(next);
    free(p);
    free(ans);

    return 0;
}
