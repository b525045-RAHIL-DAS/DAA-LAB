## 3. Problem Statement

Using the divide and conquer approach, develop an algorithm to find the maximum and minimum elements in an array of size $n$ so that the number of comparisons will be bounded by $\frac{3n}{2}$. Implement your algorithm in C to validate the result.

---

## Approach: Max and Min (Divide and Conquer)

1. **Start**.
2. **Base Case 1:** If the array contains only 1 element, set both `min` and `max` to that element. (0 comparisons)
3. **Base Case 2:** If the array contains exactly 2 elements, compare them. Set the larger one as `max` and the smaller one as `min`. (1 comparison)
4. **Recursive Step:** If the array contains more than 2 elements, divide the array into two equal halves (`low` to `mid` and `mid + 1` to `high`).
5. Recursively call the function on the left half to get `min_left` and `max_left`.
6. Recursively call the function on the right half to get `min_right` and `max_right`.
7. **Combine:** 
   * Compare `min_left` and `min_right` to find the overall `min`. (1 comparison)
   * Compare `max_left` and `max_right` to find the overall `max`. (1 comparison)
8. Return the overall `min` and `max`.
9. **Stop**.

---

## Algorithm: Max and Min (Divide and Conquer)

MAX_MIN(A, low, high)

1. If low == high

       min = A[low]

       max = A[low]

       return

2. If high == low + 1

       Compare A[low] and A[high]

       Assign smaller value to min

       Assign larger value to max

       return

3. mid = (low + high) / 2

4. MAX_MIN(A, low, mid)

       Find min1 and max1

5. MAX_MIN(A, mid + 1, high)

       Find min2 and max2

6. Compare max1 and max2

       max = larger of max1 and max2

7. Compare min1 and min2

       min = smaller of min1 and min2

8. Return min and max

## Sample Output

Enter the size of the array: 8

Enter 8 elements:

12 4 45 9 8 1 10 33

Results

Minimum element: 1

Maximum element: 45

Validation

Actual Comparisons made: 10

Theoretical Upper Bound (3n/2): 12.0

Validation Successful: 10 <= 12.0. The comparisons are bounded by 3n/2.

## Time Complexity Analysis

**Step 1: Formulate the Recurrence Relation**

At each step, the array is divided into two equal halves, and a constant amount of work $c$ is done to merge the results (the comparisons to find the overall min and max).
$$T(n) = 2T(n/2) + c$$

**Step 2: Expand the Recurrence Relation**

We expand the equation to find the pattern.
First, substitute $T(n/2)$ into the equation:
$$T(n/2) = 2T(n/4) + c$$

Plug this back into the original equation:
$$T(n) = 2[2T(n/4) + c] + c$$
$$T(n) = 4T(n/4) + 2c + c$$

Now, substitute $T(n/4)$ which is $2T(n/8) + c$:
$$T(n) = 4[2T(n/8) + c] + 2c + c$$
$$T(n) = 8T(n/8) + 4c + 2c + c$$

**Step 3: Generalize for $k$ Steps**

If we continue this expansion for $k$ iterations, we get:
$$T(n) = 2^k T(n/2^k) + c(1 + 2 + 4 + \dots + 2^{k-1})$$
$$T(n) = 2^k T(n/2^k) + c \sum_{i=0}^{k-1} 2^i$$

**Step 4: Apply the Base Case**

The recursion hits the base case when the array size becomes 1.
$$\frac{n}{2^k} = 1$$
$$n = 2^k$$
$$k = \log_2 n$$

**Step 5: Simplify and Solve**

Substitute $n = 2^k$ into the equation. 
For the geometric series $\sum_{i=0}^{k-1} 2^i$, the sum is $2^k - 1$.
Since $2^k = n$, the sum evaluates to $n - 1$.

Now, substitute everything back into the generalized equation:
$$T(n) = n \cdot T(1) + c(n - 1)$$

**Step 6: Final Conclusion**

$T(1)$ is the constant time taken for the base case (0 comparisons, just assignments), and $c$ is the constant work for merging. Because both are constants, they are ignored in asymptotic notation. The dominant term is $n$.

Therefore, the overall time complexity is strictly linear. The algorithm must always visit every element to determine the minimum and maximum, meaning the time complexity remains the same across all cases.

$$\boxed{T(n) = \Theta(n)}$$

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $\Theta(n)$ |
| **Average Case** | $\Theta(n)$ |
| **Worst Case** | $\Theta(n)$ |

## Comparison Complexity Analysis

Let $T(n)$ be the total number of comparisons required to find the maximum and minimum of $n$ elements.

When $n$ is divided into two halves of size $n/2$, we make two recursive calls. After the recursive calls return, we make **2 additional comparisons** to combine the results (one to find the overall minimum, and one for the overall maximum).

**Step 1: Formulate the Recurrence Relation**

$$T(n) = 2T(n/2) + 2$$

**Step 2: Define the Base Cases**

If $n = 1$, no comparisons are made:
$$T(1) = 0$$

If $n = 2$, only one comparison is made:
$$T(2) = 1$$

**Step 3: Expand the Recurrence Relation**

Let's assume $n$ is a power of 2 (i.e., $n = 2^k$). We expand $T(n)$:
$$T(n) = 2T(n/2) + 2$$
$$T(n) = 4T(n/4) + 4 + 2$$
$$T(n) = 8T(n/8) + 8 + 4 + 2$$

**Step 4: Generalize the Equation**

For $k-1$ expansions (until we reach the base case of $n=2$):
$$T(n) = 2^{k-1} T(2) + \sum_{i=1}^{k-1} 2^i$$

**Step 5: Simplify and Solve**

Since $n = 2^k$, we know that $2^{k-1} = \frac{n}{2}$.
Also, the base case $T(2) = 1$.

Using the geometric sum formula for the summation, it evaluates to $n - 2$.
Substitute everything back into the generalized equation:
$$T(n) = \frac{n}{2}(1) + (n - 2)$$
$$T(n) = \frac{3n}{2} - 2$$

**Step 6: Final Conclusion**

Since $\frac{3n}{2} - 2 < \frac{3n}{2}$, the total number of comparisons is strictly less than $\frac{3n}{2}$.

Thus, the number of comparisons is successfully bounded by $\frac{3n}{2}$.

## Conclusion

By utilizing the Divide and Conquer strategy, the algorithm efficiently finds both the maximum and minimum elements in an array. While the asymptotic time complexity remains $\Theta(n)$—which is the same as a traditional linear scan—the theoretical advantage lies in the reduced number of direct element comparisons. A standard sequential scan requires $2n - 2$ comparisons in the worst case, whereas this Divide and Conquer method strictly limits the maximum number of comparisons to $\frac{3n}{2} - 2$. This successfully validates the requirement that the algorithm's comparisons are strictly bounded by $\frac{3n}{2}$.


