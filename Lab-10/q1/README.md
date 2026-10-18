
# Q1 — Online Graph Bipartiteness Testing

## Problem Statement
A graph is bipartite if and only if it contains no odd-length cycles. Given an undirected graph with `V` vertices, edges arrive online one by one. Maintain whether the graph remains bipartite. If adding an edge `(u, v)` does not introduce an odd cycle, add it; otherwise, report that it violates bipartiteness and skip it. Choose a suitable input representation, write a C program to validate the algorithm, and derive its complexity.

## Aim
Process incoming edges and accept an edge only when the graph remains bipartite.

## Theory
A bipartite graph can be colored using two colors such that every edge connects vertices of different colors. The DSU stores the parity (XOR) between a vertex and its parent. For an edge `(u,v)`, their parities must differ. If both vertices are already in the same component and their parities are equal, the edge would create an odd cycle and is rejected.

## Algorithm
1. Create one DSU set for every vertex; initialize each vertex's parity to zero.
2. Read edges one at a time.
3. Find each endpoint's root and parity using path compression.
4. If both endpoints have the same root, accept the edge only if their parities differ.
5. Otherwise, merge the two sets while enforcing opposite parity.
6. Print whether the edge was accepted or rejected.

## Input Representation
DSU arrays (`parent`, `size`, and `xorParity`) are used instead of an adjacency matrix. This is suitable because edges are processed online and the entire graph does not need to be stored.

## C Program
The complete C implementation is provided separately in `main.c`.

## Compilation and Execution
```bash
gcc main.c -o q1
./q1
```

## Sample Input
```text
4 5
0 1
1 2
2 3
3 0
0 2
```

## Sample Output
```text
Edge (0,1) accepted
Edge (1,2) accepted
Edge (2,3) accepted
Edge (3,0) accepted
Edge (0,2) rejected: graph would not be bipartite
```

## Complexity Analysis
Let `V` be the number of vertices and `E` the number of incoming edges.

- Initialization: `O(V)` time.
- Each edge: amortized `O(α(V))` time using path compression and union by size.
- Total time: **`O(V + E α(V))`**.
- Auxiliary space: **`O(V)`** for the three DSU arrays.

`α(V)` is the inverse Ackermann function and is effectively constant for practical input sizes.

## Conclusion
Parity-based DSU checks each incoming edge efficiently and rejects an edge precisely when it conflicts with the two-coloring constraints.

