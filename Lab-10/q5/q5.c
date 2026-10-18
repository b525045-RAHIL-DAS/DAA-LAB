
#include <stdio.h>
#include <stdlib.h>

int *parent, *sz;

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
}

int cmpInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, m, u, v;

    printf("Enter n and m: ");
    scanf("%d%d", &n, &m);

    int *A = malloc(n * sizeof(int));
    int *ans = malloc(n * sizeof(int));
    int *pos = malloc(n * sizeof(int));
    int *val = malloc(n * sizeof(int));
    int *count = calloc(n, sizeof(int));
    int *offset = calloc(n, sizeof(int));

    parent = malloc(n * sizeof(int));
    sz = malloc(n * sizeof(int));

    printf("Enter permutation:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    printf("Enter allowed swap edges (0-based vertices):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge\n");
            return 1;
        }

        unite(u, v);
    }

    for (int i = 0; i < n; i++)
        count[find(i)]++;

    int *indices = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        int root = find(i);
        indices[root]++;
        pos[i] = root;
    }

    for (int root = 0; root < n; root++) {
        if (count[root] == 0) continue;

        int k = 0, t = 0;

        for (int i = 0; i < n; i++) {
            if (pos[i] == root) {
                pos[k++] = i;
                val[t++] = A[i];
            }
        }

        qsort(pos, k, sizeof(int), cmpInt);
        qsort(val, k, sizeof(int), cmpInt);

        for (int i = 0; i < k; i++)
            ans[pos[i]] = val[i];
    }

    printf("Lexicographically smallest permutation:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");

    free(parent);
    free(sz);
    free(A);
    free(ans);
    free(pos);
    free(val);
    free(count);
    free(offset);
    free(indices);

    return 0;
}
