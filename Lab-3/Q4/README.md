## 4. Problem Statement

Write a C program to multiply two square matrices of size $n \times n$ using Strassen's method. This involves applying the Divide and Conquer approach to reduce the number of recursive multiplications compared to traditional matrix multiplication.

---

## Algorithm: Strassen's Matrix Multiplication

1. **Start**.
2. Check the base case: If the matrix size $n$ is 1, return the simple product of the two elements.
3. If $n > 1$, divide matrices $A$ and $B$ into four $n/2 \times n/2$ sub-matrices:
   * Matrix $A$: $A_{11}, A_{12}, A_{21}, A_{22}$
   * Matrix $B$: $B_{11}, B_{12}, B_{21}, B_{22}$
4. Recursively calculate the 7 Strassen's products ($P_1$ to $P_7$):
   
   $$P_1 = A_{11} \cdot (B_{12} - B_{22})$$
   
   $$P_2 = (A_{11} + A_{12}) \cdot B_{22}$$
   
   $$P_3 = (A_{21} + A_{22}) \cdot B_{11}$$
   
   $$P_4 = A_{22} \cdot (B_{21} - B_{11})$$
   
   $$P_5 = (A_{11} + A_{22}) \cdot (B_{11} + B_{22})$$
   
   $$P_6 = (A_{12} - A_{22}) \cdot (B_{21} + B_{22})$$
   
   $$P_7 = (A_{11} - A_{21}) \cdot (B_{11} + B_{12})$$
   
6. Combine these products to find the four quadrants of the resulting matrix $C$:
   
   $$C_{11} = P_5 + P_4 - P_2 + P_6$$
   
   $$C_{12} = P_1 + P_2$$
   
   $$C_{21} = P_3 + P_4$$
   
   $$C_{22} = P_5 + P_1 - P_3 - P_7$$
   
8. Combine $C_{11}, C_{12}, C_{21}, C_{22}$ into a single $n \times n$ matrix $C$.
9. **Stop**.

---

## Sample Output

Enter the size of the square matrix(power of 2): 2

Enter Matrix A:

1 2

3 4

Enter Matrix B:

5 6

7 8

Result Matrix:

19 22 

43 50

## Strassen's Time Complexity Analysis

Let $n$ be the dimension of the square matrices.

In standard matrix multiplication using the Divide and Conquer approach, the matrices are divided into 4 sub-matrices, requiring 8 recursive multiplications. Strassen's algorithm optimizes this by only making **7 recursive calls**.

**Step 1: Formulate the Recurrence Relation**

The recurrence relation for Strassen's algorithm is:
$$T(n) = 7T(n/2) + O(n^2)$$

Where:
*   **$7T(n/2)$**: The time taken for the 7 recursive matrix multiplications of size $n/2$.
*   **$O(n^2)$**: The time taken to perform the matrix additions and subtractions to form $P_1 \dots P_7$ and the final matrix $C$.

Adding or subtracting matrices of size $n/2 \times n/2$ takes time proportional to the number of elements, which is $(n/2)^2 = n^2/4$.

Thus, the total time for additions/subtractions at each step is $O(n^2)$. Let's represent this work as a constant $c$ multiplied by $n^2$.

**Step 2: Expand the Recurrence Relation**

We expand the equation to find the pattern.
First, substitute $T(n/2)$ into the equation:
$$T(n/2) = 7T(n/4) + c(n/2)^2 = 7T(n/4) + \frac{cn^2}{4}$$

Plug this back into the original equation:
$$T(n) = 7\left[7T(n/4) + \frac{cn^2}{4}\right] + cn^2$$
$$T(n) = 7^2 T(n/4) + \frac{7}{4}cn^2 + cn^2$$
$$T(n) = 7^2 T(n/4) + cn^2\left(1 + \frac{7}{4}\right)$$

Now, substitute $T(n/4)$ which is $7T(n/8) + c(n/4)^2$:

$$T(n) = 7^2\left[7T(n/8) + \frac{cn^2}{16}\right] + cn^2\left(1 + \frac{7}{4}\right)$$

$$T(n) = 7^3 T(n/8) + \frac{49}{16}cn^2 + cn^2\left(1 + \frac{7}{4}\right)$$

$$T(n) = 7^3 T(n/2^3) + cn^2\left(1 + \frac{7}{4} + \left(\frac{7}{4}\right)^2\right)$$

**Step 3: Generalize for $k$ Steps**

If we continue this expansion for $k$ iterations, we get:
$$T(n) = 7^k T(n/2^k) + cn^2 \sum_{i=0}^{k-1} \left(\frac{7}{4}\right)^i$$

**Step 4: Apply the Base Case**

The recursion hits the base case when the matrix size becomes 1. 

$$\frac{n}{2^k} = 1$$

$$n = 2^k$$

$$k = \log_2 n$$

**Step 5: Simplify the Equation**

First, let's evaluate the term $7^k$. Using logarithm properties:
$$7^k = 7^{\log_2 n} = n^{\log_2 7}$$

Next, we evaluate the geometric series: $1 + \frac{7}{4} + \left(\frac{7}{4}\right)^2 + \dots$ 
The sum of a geometric series is $S = \frac{a(r^k - 1)}{r - 1}$. Here, $a=1$ and $r = \frac{7}{4}$:
$$\sum_{i=0}^{k-1} \left(\frac{7}{4}\right)^i = \frac{\left(\frac{7}{4}\right)^k - 1}{\frac{7}{4} - 1} = \frac{\left(\frac{7}{4}\right)^k - 1}{\frac{3}{4}} = \frac{4}{3} \left( \left(\frac{7}{4}\right)^k - 1 \right)$$

Substitute $k = \log_2 n$ into the geometric ratio:
$$\left(\frac{7}{4}\right)^k = \frac{7^k}{4^k} = \frac{n^{\log_2 7}}{n^{\log_2 4}} = \frac{n^{\log_2 7}}{n^2}$$

Now, plug this back into the total work equation:

$$Total \ Work = cn^2 \cdot \frac{4}{3} \left( \frac{n^{\log_2 7}}{n^2} - 1 \right) = \frac{4c}{3} (n^{\log_2 7} - n^2)$$

**Step 6: Final Time Complexity**

Substituting everything back into our generalized equation from Step 3:
$$T(n) = n^{\log_2 7} T(1) + \frac{4c}{3} n^{\log_2 7} - \frac{4c}{3} n^2$$

Since $T(1)$ and $\frac{4c}{3}$ are constants, we ignore them in Big-O notation. The term $n^{\log_2 7}$ (which is approximately $n^{2.81}$) dominates the $n^2$ term. Therefore, the worst-case time complexity is:
$$\boxed{T(n) = \Theta(n^{\log_2 7}) \approx \Theta(n^{2.81})}$$

### Best, Average, and Worst Case

Because Strassen's algorithm blindly performs the 7 multiplications and matrix additions regardless of the input values (e.g., even if the matrices contain many zeros), the time complexity remains constant across all cases.

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $\Theta(n^{\log_2 7})$ |
| **Average Case** | $\Theta(n^{\log_2 7})$ |
| **Worst Case** | $\Theta(n^{\log_2 7})$ |

---

## Detailed Comparison: Traditional vs. Strassen's Multiplication

*   **Traditional D&C Multiplication:** Requires 8 recursive multiplications, leading to a recurrence of $T(n) = 8T(n/2) + O(n^2)$.Resulting in a time complexity of **$O(n^3)$**.
*   **Strassen's Multiplication:** Requires 7 recursive multiplications, leading to **$O(n^{2.81})$**. 

**Conclusion:** For large values of $n$, $n^{2.81}$ grows significantly slower than $n^3$. Therefore, Strassen's algorithm is asymptotically faster than traditional matrix multiplication, though the $O(n^2)$ overhead of additions makes it less efficient for very small matrices.

---


