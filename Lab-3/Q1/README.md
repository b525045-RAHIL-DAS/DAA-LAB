## 1. Problem Statement

In **Binary Search**, a sorted array of `n` elements is divided into two nearly equal halves. In **Ternary Search**, the sorted array is divided into three nearly equal parts. 

The objective of this project is to implement both Binary Search and Ternary Search algorithms, and to justify and validate that Binary Search is better than Ternary Search.

## Algorithm

### Binary Search
1. Start.
2. Set `low = 0` and `high = n-1`.
3. Repeat while `low <= high`.
4. Calculate the middle index.
5. Compare the middle element with `x`.
6. If equal, return the index.
7. If `x` is smaller, search the left half.
8. Otherwise, search the right half.
9. If `low` becomes greater than `high`, the element does not exist.
10.Stop.

---

### Ternary Search
1. Start.
2. Set `low = 0` and `high = n-1`.
3. Divide the current range into three parts.
4. Calculate `mid1` and `mid2`.
5. Compare `x` with `A[mid1]`.
6. Compare `x` with `A[mid2]`.
7. Select the appropriate third.
8. Repeat until the element is found or the range becomes empty.
9. If the range becomes empty, report not found.
10.Stop.

## Sample Output

Enter size of sorted array: 10

Enter 10 sorted elements:

10 20 30 40 50 60 70 80 90 100

Enter element to search: 80

Binary Search:

Element found at index 7

Comparisons = 3

Ternary Search:

Element found at index 7

Comparisons = 4

## Binary Search Time Complexity

Let the total number of elements in the array be $n$.

At each step, the search space is divided exactly in half. The size of the array progresses as follows:
*   Initially: 
    $$n$$
*   After the first iteration: 
    $$\frac{n}{2}$$
*   After the second iteration: 
    $$\frac{n}{2^2}$$
*   After the third iteration: 
    $$\frac{n}{2^3}$$

Based on this continuous halving, the time taken to search $n$ elements equals the time to search $n/2$ elements, plus a constant amount of work $c$ (for calculating the mid-point and making comparisons). 
$$T_B(n) = T_B(n/2) + c$$

We expand the recurrence relation to find a pattern:
*   First expansion:
    $$T_B(n) = T_B(n/2) + c$$
*   Substitute $T_B(n/2)$ with $[T_B(n/4) + c]$:
    $$T_B(n) = T_B(n/4) + c + c$$
    $$T_B(n) = T_B(n/4) + 2c$$
*   Substitute $T_B(n/4)$ with $[T_B(n/8) + c]$:
    $$T_B(n) = T_B(n/8) + c + 2c$$
    $$T_B(n) = T_B(n/8) + 3c$$

If we continue this process for $k$ levels, the generalized equation becomes:
$$T_B(n) = T_B(n/2^k) + kc$$

The search terminates when only 1 element remains in our search space.
$$\frac{n}{2^k} = 1$$

Multiply both sides by $2^k$:
$$n = 2^k$$

Take the logarithm (base 2) on both sides to isolate $k$:
$$k = \log_2 n$$

Now, substitute $k = \log_2 n$ back into the generalized equation:
$$T_B(n) = T_B(1) + c\log_2 n$$

Because $T_B(1)$ (the time it takes to check a single element) and $c$ (the work done per step) are both constants, they are ignored in asymptotic notation. 
$$\boxed{T_B(n) = \Theta(\log_2 n)}$$

Thus, the worst-case time complexity of Binary Search is:
$$\boxed{\Theta(\log n)}$$

## Ternary Search Time Complexity

Let the total number of elements in the array be $n$.

At each step, the search space is divided exactly into three parts. The size of the active array progresses as follows:
*   Initially: 
    $$n$$
*   After the first iteration: 
    $$\frac{n}{3}$$
*   After the second iteration: 
    $$\frac{n}{3^2}$$
*   After the third iteration: 
    $$\frac{n}{3^3}$$

Based on this continuous division by three, the time taken to search $n$ elements equals the time to search $n/3$ elements, plus a constant amount of work $c$ (for calculating the two mid-points and making comparisons). 
$$T_T(n) = T_T(n/3) + c$$

We expand the recurrence relation to find a pattern:
*   First expansion:
    $$T_T(n) = T_T(n/3) + c$$
*   Substitute $T_T(n/3)$ with $[T_T(n/9) + c]$:
    $$T_T(n) = T_T(n/9) + c + c$$
    $$T_T(n) = T_T(n/9) + 2c$$
*   Substitute $T_T(n/9)$ with $[T_T(n/27) + c]$:
    $$T_T(n) = T_T(n/27) + c + 2c$$
    $$T_T(n) = T_T(n/27) + 3c$$

If we continue this process for $k$ levels, the generalized equation becomes:
$$T_T(n) = T_T(n/3^k) + kc$$

The search terminates when only 1 element remains in our search space.
$$\frac{n}{3^k} = 1$$

Multiply both sides by $3^k$:
$$n = 3^k$$

Take the logarithm (base 3) on both sides to isolate $k$:
$$k = \log_3 n$$

Now, substitute $k = \log_3 n$ back into the generalized equation:
$$T_T(n) = T_T(1) + c\log_3 n$$

Because $T_T(1)$ (the time it takes to check a single element) and $c$ (the work done per step) are both constants, they are ignored in asymptotic notation. 
$$\boxed{T_T(n) = \Theta(\log_3 n)}$$

Thus, ignoring the logarithm base (as all logarithms are related by a constant factor), the worst-case time complexity of Ternary Search is:
$$\boxed{\Theta(\log n)}$$

## Binary Search Time Complexity: Best, Average, and Worst Case

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $\Theta(1)$ |
| **Average Case** | $\Theta(\log n)$ |
| **Worst Case** | $\Theta(\log n)$ |

## Ternary Search Time Complexity: Best, Average, and Worst Case

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $\Theta(1)$ |
| **Average Case** | $\Theta(\log n)$ |
| **Worst Case** | $\Theta(\log n)$ |

## Detailed Comparison: Why Binary Search is Better than Ternary Search

Although Ternary Search reduces the search space faster (by a factor of 3) compared to Binary Search (by a factor of 2), Binary Search is practically faster. To prove this, we must compare the **total number of comparisons** required in the worst case.

### Step 1: Maximum Number of Iterations
From our previous time complexity derivations, we know the maximum number of iterations required for an array of size $n$:
*   **Binary Search:** $\log_2 n$
*   **Ternary Search:** $\log_3 n$

### Step 2: Number of Comparisons per Iteration
In each iteration, we compare the target element $x$ with the middle elements.

**For Binary Search:**
We have one middle element (`mid`). In the worst case, we make **2 comparisons**:
1.  Check if $x == A[\text{mid}]$
2.  Check if $x < A[\text{mid}]$ (if false, it implicitly means $x > A[\text{mid}]$)

**For Ternary Search:**
We have two middle elements (`mid1` and `mid2`). In the worst case, we make **4 comparisons**:
1.  Check if $x == A[\text{mid1}]$
2.  Check if $x == A[\text{mid2}]$
3.  Check if $x < A[\text{mid1}]$
4.  Check if $x > A[\text{mid2}]$ (if false, it implicitly means $x$ is between `mid1` and `mid2`)

### Step 3: Total Number of Comparisons in the Worst Case
Multiplying the iterations by the comparisons per iteration, we get the total worst-case comparisons ($C$):
*   **Total comparisons in Binary Search ($C_B$):** 
    $$C_B = 2 \log_2 n$$
*   **Total comparisons in Ternary Search ($C_T$):** 
    $$C_T = 4 \log_3 n$$

### Step 4: Mathematical Evaluation
To accurately compare $C_B$ and $C_T$, we need to convert them to the same logarithmic base. We will use the change of base formula to convert $C_T$ to base 2:
$$\log_3 n = \frac{\log_2 n}{\log_2 3}$$

Substitute this back into the Ternary Search equation:
$$C_T = 4 \left( \frac{\log_2 n}{\log_2 3} \right)$$

We know the constant value of $\log_2 3 \approx 1.585$. Substituting this value:
$$C_T = \frac{4}{1.585} \log_2 n$$
$$C_T \approx 2.52 \log_2 n$$

### Step 5: Final Conclusion
Now we compare the final equations:
*   $C_B = 2 \log_2 n$
*   $C_T \approx 2.52 \log_2 n$

Since **$2.52 \log_2 n > 2 \log_2 n$**, Ternary Search performs significantly more comparisons in the worst case than Binary Search. 

Therefore, even though Ternary Search takes fewer steps (iterations), the overhead of extra comparisons per step makes **Binary Search fundamentally more efficient and faster in practical implementations.**
