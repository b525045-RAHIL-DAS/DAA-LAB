# Design and Analysis of Algorithms (DAA) Lab

## Overview

This repository contains C programs implemented as part of the **Design and Analysis of Algorithms (DAA) Laboratory**. Each program demonstrates a fundamental algorithm along with its time and space complexity.

---

# Program 1: Order of Growth of Functions

## Objective
Evaluate different mathematical functions for a fixed value of **n = 1024** and arrange them in increasing order of growth.

## Algorithm
1. Initialize `n = 1024`.
2. Compute the values of different mathematical functions.
3. Store the function names and values in arrays.
4. Sort the functions using **Bubble Sort**.
5. Display the sorted order.

## Time Complexity
- Function evaluation: **O(1)**
- Bubble Sort (12 elements): **O(k²)**, where `k = 12`
- Overall: **O(1)**

## Space Complexity
- **O(1)**

---

# Program 2: Fair Coin and Biased Coin Simulation

## Objective
Simulate fair and biased coin tosses using random number generation and estimate the probability of obtaining heads.

## Algorithm
1. Read the number of coin tosses `n`.
2. Simulate a fair coin using `rand()%2`.
3. Count heads and tails.
4. Simulate a biased coin using `rand()%10 < 7`.
5. Count heads and tails.
6. Display the estimated probability of heads.

## Time Complexity
- Fair coin simulation: **O(n)**
- Biased coin simulation: **O(n)**
- Overall: **O(n)**

## Space Complexity
- **O(1)**

---

# Program 3: Comparison of Normal and Optimized Bubble Sort

## Objective
Compare the number of comparisons performed by normal Bubble Sort and optimized Bubble Sort.

## Algorithm

### Normal Bubble Sort
1. Compare adjacent elements.
2. Swap if required.
3. Repeat for `n-1` passes.

### Optimized Bubble Sort
1. Perform Bubble Sort.
2. Maintain a `swapped` flag.
3. If no swap occurs during a pass, terminate early.
4. Count comparisons.
5. Display the comparison graph.

## Time Complexity

### Normal Bubble Sort
- Best Case: **O(n²)**
- Average Case: **O(n²)**
- Worst Case: **O(n²)**

### Optimized Bubble Sort
- Best Case: **O(n)**
- Average Case: **O(n²)**
- Worst Case: **O(n²)**

## Space Complexity
- **O(1)**

---

# Program 4: Tower of Hanoi

## Objective
Solve the Tower of Hanoi problem recursively and count the number of moves.

## Algorithm
1. If only one disk remains, move it.
2. Move `n-1` disks from source to auxiliary.
3. Move the largest disk to destination.
4. Move `n-1` disks from auxiliary to destination.
5. Count the total number of moves.
6. Plot the graph of steps versus disks.

## Recurrence Relation

```
T(n) = 2T(n-1) + 1
```

Solution:

```
T(n) = 2^n - 1
```

## Time Complexity
- **O(2ⁿ)**

## Space Complexity
- **O(n)**
  
## Tower of Hanoi Graph

![Tower of Hanoi Graph](images/tower_of_hanoi_graph.png)
---

# Program 5: Find Partition Point in a Binary Array

## Objective
Find the partition point between 0's and 1's using Binary Search.

## Algorithm
1. Read the binary array.
2. Apply Binary Search.
3. If middle element is `1`, search left half.
4. Otherwise search right half.
5. The first occurrence of `1` is the partition point.

## Time Complexity
- **O(log n)**

## Space Complexity
- **O(1)**

---

# Program 6: Duplicate Detection in Random Numbers

## Objective
Generate random numbers and determine whether duplicate values exist.

## Algorithm
1. Read the number of elements `n`.
2. Generate `n` random numbers.
3. Compare every pair of elements.
4. If duplicates are found, display them.
5. Otherwise report that all elements are unique.

## Time Complexity
- Random number generation: **O(n)**
- Duplicate detection: **O(n²)**
- Overall: **O(n²)**

## Space Complexity
- **O(n)**

---

# Complexity Summary

| Program | Algorithm | Time Complexity | Space Complexity |
|----------|-----------|-----------------|------------------|
| 1 | Bubble Sort (sorting function values) | O(1) *(O(k²), k=12)* | O(1) |
| 2 | Random Coin Toss Simulation | O(n) | O(1) |
| 3 | Normal & Optimized Bubble Sort | Best: O(n), Average/Worst: O(n²) | O(1) |
| 4 | Tower of Hanoi (Recursion) | O(2ⁿ) | O(n) |
| 5 | Binary Search | O(log n) | O(1) |
| 6 | Brute Force Duplicate Detection | O(n²) | O(n) |

---

## Technologies Used

- C Programming Language
- GCC Compiler
- Bubble Sort
- Binary Search
- Recursion
- Randomized Algorithms
- Brute Force Method
- Time Complexity Analysis
- Space Complexity Analysis

---

## Author

**Name:**  Rahil Das

**Course:** Design and Analysis of Algorithms Laboratory
