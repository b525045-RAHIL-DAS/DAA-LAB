
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF (LLONG_MAX / 4)

typedef struct Edge {
    int to, weight;
    struct Edge *next;
} Edge;

typedef struct Node {
    int state;
    long long dist;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Deque;

void addEdge(Edge **graph, int u, int v, int w) {
    Edge *e = malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = graph[u];
    graph[u] = e;
}

void pushFront(Deque *dq, int state, long long dist) {
    Node *n = malloc(sizeof(Node));
    n->state = state;
    n->dist = dist;
    n->next = dq->front;
    dq->front = n;

    if (dq->rear == NULL)
        dq->rear = n;
}

void pushBack(Deque *dq, int state, long long dist) {
    Node *n = malloc(sizeof(Node));
    n->state = state;
    n->dist = dist;
    n->next = NULL;

    if (dq->rear == NULL) {
        dq->front = dq->rear = n;
    } else {
        dq->rear->next = n;
        dq->rear = n;
    }
}

int popFront(Deque *dq, int *state, long long *d) {
    if (dq->front == NULL)
        return 0;

    Node *temp = dq->front;
    *state = temp->state;
    *d = temp->dist;

    dq->front = dq->front->next;

    if (dq->front == NULL)
        dq->rear = NULL;

    free(temp);
    return 1;
}

void zeroOneBFS(Edge **graph, int n, int source,
                long long dist[][2]) {
    Deque dq = {NULL, NULL};

    for (int i = 1; i <= n; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[source][0] = 0;

    // State = 2 * vertex + parity (using 0-based vertex).
    pushFront(&dq, 2 * (source - 1), 0);

    int state;
    long long d;

    while (popFront(&dq, &state, &d)) {
        if (state < 0 || state >= 2 * n)
            continue;

        // Ignore outdated deque entries.
        int u = state / 2 + 1;
        int parity = state % 2;

        if (d != dist[u][parity])
            continue;

        for (Edge *e = graph[u]; e != NULL; e = e->next) {
            int v = e->to;
            int w = e->weight;
            int newParity = parity ^ w;
            long long newDist = d + w;

            if (newDist < dist[v][newParity]) {
                dist[v][newParity] = newDist;
                int newState = 2 * (v - 1) + newParity;

                if (w == 0)
                    pushFront(&dq, newState, newDist);
                else
                    pushBack(&dq, newState, newDist);
            }
        }
    }
}

int main(void) {
    int n, m, S;
    long long C;

    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2 ||
        n <= 0 || m < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter source vertex and penalty C: ");
    if (scanf("%d %lld", &S, &C) != 2 ||
        S < 1 || S > n || C < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Edge **graph = calloc(n + 1, sizeof(Edge *));
    if (graph == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter edges (u v w), where w is 0 or 1:\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;

        if (scanf("%d %d %d", &u, &v, &w) != 3 ||
            u < 1 || u > n || v < 1 || v > n ||
            (w != 0 && w != 1)) {
            printf("Invalid edge input.\n");
            return 1;
        }

        addEdge(graph, u, v, w);
    }

    long long (*dist)[2] =
        malloc((n + 1) * sizeof(*dist));

    if (dist == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    zeroOneBFS(graph, n, S, dist);

    printf("\nMinimum effective costs:\n");

    for (int v = 1; v <= n; v++) {
        if (dist[v][0] == INF && dist[v][1] == INF) {
            printf("Vertex %d: Unreachable\n", v);
        } else {
            long long evenCost = dist[v][0];
            long long oddCost =
                (dist[v][1] == INF) ? INF : dist[v][1] + C;

            long long answer =
                (evenCost < oddCost) ? evenCost : oddCost;

            printf("Vertex %d: %lld\n", v, answer);
        }
    }

    for (int i = 1; i <= n; i++) {
        Edge *e = graph[i];

        while (e != NULL) {
            Edge *temp = e;
            e = e->next;
            free(temp);
        }
    }

    free(graph);
    free(dist);

    return 0;
}
