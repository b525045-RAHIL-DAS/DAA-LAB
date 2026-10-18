
# Q2 — Dynamic Connected Components in a Grid

## Problem Statement
Given an R × C grid initially completely filled with water, land cells are added one by one at positions `(r1, c1), (r2, c2), ..., (rk, ck)`. After each operation, output the current number of 4-directionally connected land components (islands).

This problem, commonly known as Number of Islands II, can be solved using a Disjoint Set Union (DSU / Union-Find) data structure with coordinate flattening.

## Aim
To find the number of connected islands after each land-addition operation using DSU.

## Theory
Initially, all cells contain water. When a cell becomes land, it forms a new island. If any of its four adjacent cells (up, down, left, right) are already land, their components are merged.

The number of islands increases by one when a new land cell is added. Every successful union with an adjacent land component decreases the island count by one.

To represent a cell `(r, c)` as a single array index, use:

`id = r * C + c`

## Algorithm
1. Initialize every grid cell as water.
2. Initialize the DSU parent and size arrays.
3. Read each land-addition coordinate `(r, c)`.
4. If the cell is already land, print the current island count.
5. Otherwise, mark it as land and increase the island count by one.
6. Check its four neighboring cells.
7. For every neighboring land cell, merge the two components. Decrease the island count after each successful union.
8. Print the island count after every operation.

## Input Representation
The grid is represented using a one-dimensional array of size `R × C`. The DSU uses `parent` and `size` arrays, while a separate `land` array indicates whether a cell has been activated.

## C Program
The complete C implementation is provided separately in `main.c`.

## Compilation and Execution
```bash
gcc main.c -o q2
./q2
```

## Sample Input
```text
3 3 5
0 0
0 1
1 2
2 1
1 1
```

## Sample Output
```text
1
1
2
3
1
```

## Complexity Analysis
Let `R` be the number of rows, `C` the number of columns, and `k` the number of land-addition operations.

- Initialization: `O(R × C)` time.
- Each operation checks at most four neighbors and performs a constant number of DSU operations, each taking amortized `O(α(R × C))` time.
- Total time: **`O(R × C + k α(R × C))`**.
- Auxiliary space: **`O(R × C)`**.

Here, `α(n)` is the inverse Ackermann function, which is effectively constant for practical input sizes.

## Conclusion
DSU efficiently maintains connected land components as cells are added dynamically. Coordinate flattening allows each grid cell to be represented by a single array index.

