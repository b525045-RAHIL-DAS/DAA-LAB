
# Q3 — Maximum Weight Component with Size Constraints

## Problem Statement
Given a graph where each vertex `v` has weight `w[v]`, edges are added sequentially. At any point, compute the maximum total vertex weight of any connected component whose size does not exceed a threshold `K`.

Choose a suitable input representation, write a C program to validate the algorithm, and derive its complexity analysis.

## Aim
To find the maximum total vertex weight among all connected components whose sizes do not exceed `K`, after each edge addition.

## Theory
A Disjoint Set Union (DSU) data structure maintains the connected components of a graph as edges are added.

Each component stores:
- `parent`: representative of the component.
- `size`: number of vertices in the component.
- `sum`: total weight of the vertices in the component.

When an edge connects two different components, they are merged. Their sizes and total vertex weights are added.

After every edge addition, all component representatives are checked. Only components with size less than or equal to `K` are considered when finding the maximum weight.

## Algorithm
1. Read the number of vertices `N`, edges `M`, and size threshold `K`.
2. Read the weight of every vertex.
3. Initialize each vertex as a separate DSU component.
4. Read the edges one by one.
5. Find the representatives of the two endpoints.
6. If their representatives differ, merge the components using union by size and update their total weight.
7. Scan all DSU representatives.
8. Consider only components whose size is at most `K`.
9. Print the maximum total vertex weight among the eligible components. If none exists, print that no eligible component is available.

## Input Representation
The graph is represented using DSU arrays rather than an adjacency matrix. The arrays `parent`, `size`, and `sum` store the representative, component size, and total vertex weight respectively.

The graph is processed online, so the entire adjacency structure is not required.

## C Program
The complete C implementation is provided separately in `main.c`.

## Compilation and Execution
```bash
gcc main.c -o q3
./q3
```

## Sample Input
```text
4 3 2
5 2 8 3
0 1
1 2
2 3
```

## Sample Output
```text
Maximum eligible component weight: 8
Maximum eligible component weight: 3
No eligible component
```

## Complexity Analysis
Let `N` be the number of vertices, `M` the number of edges, and `K` the maximum permitted component size.

- Initialization: `O(N)` time.
- Each union operation: amortized `O(α(N))` time.
- Scanning all vertices after each edge: `O(N)` time per edge.
- Total time: **`O(N + M α(N) + MN)`**.
- Auxiliary space: **`O(N)`**.

Here, `α(N)` is the inverse Ackermann function, which is effectively constant for practical input sizes.

## Conclusion
DSU efficiently maintains component sizes and total vertex weights as edges are added. By checking the size constraint after each addition, the maximum weight of an eligible connected component can be determined.

