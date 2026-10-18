
# Q5 — Lexicographically Smallest Connected Component Permutation

## Problem Statement
Given a permutation `A` of numbers `1, 2, ..., n` and a list of allowable pairwise swaps `(u, v)` forming edges in an undirected graph, find the lexicographically smallest permutation achievable through any number of valid swaps.

Choose a suitable input representation, write a C program to validate the algorithm, and derive its complexity analysis.

## Aim
To find the lexicographically smallest permutation obtainable by swapping elements only between vertices connected through the given graph.

## Theory
A Disjoint Set Union (DSU) data structure identifies the connected components of the graph.

Any two vertices in the same connected component can exchange their values through a sequence of allowed swaps. Therefore, the values within each connected component can be rearranged arbitrarily.

To obtain the lexicographically smallest permutation:
- Identify all connected components using DSU.
- Collect the indices belonging to each component.
- Collect the values at those indices.
- Sort the indices in ascending order.
- Sort the corresponding values in ascending order.
- Assign the smallest value to the smallest index within each component.

This produces the lexicographically smallest achievable permutation.

## Algorithm
1. Read the number of elements `n` and the number of allowed swaps `m`.
2. Read the permutation `A`.
3. Initialize each vertex as a separate DSU component.
4. Read each allowed swap edge `(u, v)` and merge their components.
5. Identify all connected components.
6. For each component, collect its indices and corresponding permutation values.
7. Sort the indices and values independently in ascending order.
8. Assign the sorted values to the sorted indices.
9. Print the resulting permutation.

## Input Representation
The graph is represented using DSU arrays:
- `parent`: representative of each component.
- `size`: number of vertices in each component.

Arrays are used to store the original permutation, the resulting permutation, and the indices and values of each component.

## C Program
The complete C implementation is provided separately in `main.c`.

## Compilation and Execution
```bash
gcc main.c -o q5
./q5
```

## Sample Input
```text
5 2
5 4 3 2 1
0 1
3 4
```

## Sample Output
```text
4 5 3 1 2
```

## Complexity Analysis
Let `n` be the number of vertices and `m` the number of allowed swap edges.

- DSU initialization: `O(n)` time.
- Processing all edges: `O(m α(n))` amortized time.
- Identifying components by scanning vertices: `O(n²)` time in the straightforward implementation.
- Sorting component indices and values: at most `O(n log n)` total time across all components.
- Total time: **`O(n² + m α(n) + n log n)`**.
- Auxiliary space: **`O(n)`**.

Here, `α(n)` is the inverse Ackermann function, which is effectively constant for practical input sizes.

## Conclusion
DSU efficiently identifies the connected components that determine which elements can be swapped. Sorting the indices and values within each component produces the lexicographically smallest achievable permutation.

