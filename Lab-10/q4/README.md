
# Q4 — Reverse Time-Step DSU Application

## Problem Statement
Given a vertex-weighted undirected graph, vertices are sequentially deleted one by one in an order `P = [p1, p2, ..., pV]`. After each vertex deletion, compute the maximum sum of vertex values among all remaining connected components.

Deleting a vertex also removes all edges incident to it. Choose a suitable input representation, write a C program to validate the algorithm, and derive its complexity analysis.

## Aim
To find the maximum total vertex weight among the remaining connected components after each vertex deletion using a reverse-time DSU approach.

## Theory
A Disjoint Set Union (DSU) supports merging components efficiently but does not support splitting components when vertices are deleted.

To overcome this limitation, process the operations in reverse order:
- Initially, consider all vertices inactive.
- Activate vertices in reverse deletion order.
- When a vertex is activated, connect it to all its active neighbors.
- Maintain the total weight of each connected component.
- Calculate the maximum component weight for each required state.

This converts vertex deletion operations into vertex addition operations, which DSU can handle efficiently.

## Algorithm
1. Read the number of vertices `N` and edges `M`.
2. Read the weight of every vertex.
3. Store the graph using adjacency lists.
4. Read all edges and the vertex deletion order.
5. Initially mark all vertices as inactive.
6. Process the deletion order in reverse.
7. Activate the current vertex and initialize its component weight.
8. Check all its neighbors. If a neighbor is active, merge their components.
9. Find the maximum component weight among the active components.
10. Store the answer for each required deletion state.
11. Print the answers in the original deletion order.

## Input Representation
The graph is stored using adjacency lists, which efficiently represent the neighbors of each vertex.

The DSU maintains:
- `parent`: representative of each component.
- `size`: number of vertices in each component.
- `sum`: total vertex weight of each component.
- `active`: indicates whether a vertex is currently present in the graph.

## C Program
The complete C implementation is provided separately in `main.c`.

## Compilation and Execution
```bash
gcc main.c -o q4
./q4
```

## Sample Input
```text
4 3
1 2 3 4
0 1
1 2
2 3
1 2 3 0
```

## Sample Output
```text
7
4
1
0
```

## Complexity Analysis
Let `N` be the number of vertices and `M` the number of edges.

- Building the adjacency lists: `O(N + M)` time.
- Each vertex is activated once.
- Each edge is considered a constant number of times.
- DSU operations take amortized `O(α(N))` time.
- The straightforward implementation scans all vertices to calculate the maximum component weight after each activation, taking `O(N²)` time overall.
- Total time: **`O(N + M + (N + M)α(N) + N²)`**.
- Auxiliary space: **`O(N + M)`**.

Here, `α(N)` is the inverse Ackermann function, which is effectively constant for practical input sizes.

## Conclusion
Reverse-time processing converts vertex deletions into additions. By combining reverse processing with DSU and adjacency lists, the maximum connected-component weight can be calculated after every deletion.

