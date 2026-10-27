

# Shortest Path on Parity-Constrained Graphs via 0-1 BFS

## Problem Statement

You are given a directed graph `G = (V, E)`, a source vertex `S`, and an extra penalty cost `C >= 0`.

Every directed edge `(u, v)` has a weight `w(u, v)` belonging to `{0, 1}`.

For any path `P` from `S` to a vertex `v`:

- `W(P)` is the sum of all edge weights along the path.
- `k1(P)` is the number of weight-1 edges traversed.
- `C` is an additional penalty applied when the number of weight-1 edges is odd.

The effective cost of a path is defined as:

- If `k1(P)` is even: `Cost(P) = W(P)`
- If `k1(P)` is odd: `Cost(P) = W(P) + C`

The objective is to find the minimum effective cost from source `S` to every vertex. If a vertex cannot be reached, report it as unreachable.

## Approach

We use **0-1 BFS with two parity states per vertex**.

For every vertex `v`, maintain two distances:

- `dist[v][0]`: Minimum total edge weight to reach `v` with an even number of weight-1 edges.
- `dist[v][1]`: Minimum total edge weight to reach `v` with an odd number of weight-1 edges.

Initially, all distances are infinity except:

`dist[S][0] = 0`

The parity changes according to:

`newParity = currentParity XOR edgeWeight`

For each edge:

1. Calculate the new distance by adding the edge weight.
2. If the edge weight is `0`, insert the next state at the front of the deque.
3. If the edge weight is `1`, insert the next state at the back of the deque.
4. Update the corresponding parity state if a shorter distance is found.

After the algorithm finishes, calculate the answer for each vertex:

`answer[v] = min(dist[v][0], dist[v][1] + C)`

If both parity states are unreachable, report the vertex as unreachable.

## Algorithm

1. Represent the directed graph using an adjacency list.
2. Initialize both parity distances of every vertex to infinity.
3. Set the even-parity distance of source `S` to zero.
4. Insert the source state into a deque.
5. Process states using 0-1 BFS.
6. Update distances and parity states for each outgoing edge.
7. Calculate the minimum effective cost for every vertex.
8. Report unreachable vertices.

## Input Format

- First line: `n m`, the number of vertices and edges.
- Second line: `S C`, the source vertex and penalty cost.
- Next `m` lines: `u v w`, representing a directed edge from `u` to `v` with weight `w`.

Vertices are numbered from `1` to `n`, and every edge weight must be either `0` or `1`.

## Example Input

```text
4 4
1 5
1 2 1
1 3 0
2 4 0
3 4 1
```

## Example Output

```text
Minimum effective costs:
Vertex 1: 0
Vertex 2: 6
Vertex 3: 0
Vertex 4: 6
```

## Explanation

The source vertex is `1`, and the penalty is `C = 5`.

- Vertex `1`: The source has a cost of `0`.
- Vertex `2`: The path uses one weight-1 edge. Cost = `1 + 5 = 6`.
- Vertex `3`: The path uses one weight-0 edge. Cost = `0`.
- Vertex `4`: Both possible paths have one weight-1 edge. Their effective cost is `1 + 5 = 6`.

Therefore, the minimum effective costs are `0, 6, 0, 6`.

## Data Structures Used

- **Adjacency List:** Stores the directed graph efficiently.
- **Deque:** Supports insertion at both ends for 0-1 BFS.
- **Distance Array:** Stores minimum distances for both parity states.

## Complexity Analysis

Let:

- `V` be the number of vertices.
- `E` be the number of directed edges.

### Time Complexity

The expanded graph contains `2V` states and `2E` transitions.

0-1 BFS processes these states and transitions in linear time.

**Overall Time Complexity: O(V + E)**

### Space Complexity

The adjacency list requires `O(V + E)` space. The distance array and deque require at most `O(V + E)` space.

**Overall Space Complexity: O(V + E)**

## Conclusion

The algorithm efficiently finds the minimum effective cost from a source vertex to every other vertex in a directed graph with edge weights `0` and `1`. By maintaining separate even- and odd-parity states and using 0-1 BFS, it correctly handles the additional penalty condition.
