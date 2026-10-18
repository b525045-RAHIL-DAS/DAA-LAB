
#include <stdio.h>
#include <stdlib.h>

int *parent, *sz, *xr;

int find(int x) {
    if (parent[x] != x) {
        int p = parent[x];
        parent[x] = find(p);
        xr[x] ^= xr[p];
    }
    return parent[x];
}

int unite(int u, int v) {
    int ru = find(u), pu = xr[u];
    int rv = find(v), pv = xr[v];

    if (ru == rv)
        return (pu ^ pv) == 1;

    if (sz[ru] < sz[rv]) {
        int t = ru;
        ru = rv;
        rv = t;
    }

    parent[rv] = ru;
    xr[rv] = pu ^ pv ^ 1;
    sz[ru] += sz[rv];

    return 1;
}

int main(void) {
    int V, E, u, v;

    printf("Enter vertices and number of edges: ");
    scanf("%d%d", &V, &E);

    parent = malloc(V * sizeof(int));
    sz = malloc(V * sizeof(int));
    xr = calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    printf("Enter edges (0-based vertices):\n");

    for (int i = 0; i < E; i++) {
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge\n");
            continue;
        }

        if (unite(u, v))
            printf("Edge (%d,%d) accepted\n", u, v);
        else
            printf("Edge (%d,%d) rejected: graph is not bipartite\n", u, v);
    }

    free(parent);
    free(sz);
    free(xr);
    return 0;
}
