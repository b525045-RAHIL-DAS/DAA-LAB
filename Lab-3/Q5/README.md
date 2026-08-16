## 5. Problem Statement: Special-Pattern Matrix Multiplication

Given two $n \times n$ matrices $A$ and $B$ (where $n$ is a perfect power of 2) that possess identical diagonal and off-diagonal blocks:

$$A = \begin{bmatrix} X & Y \\ Y & X \end{bmatrix}, B = \begin{bmatrix} U & V \\ V & U \end{bmatrix}$$

Develop an optimized Divide and Conquer algorithm to multiply them and produce matrix $C$. By utilizing algebraic properties, reduce the number of recursive multiplications to minimize the time complexity from the standard $O(n^3)$ to $O(n^2)$.


## Sample Output

Enter matrix size n x n: 2

Enter elements of Matrix A:

2 1

1 2

Enter elements of Matrix B:

3 2

2 3

Result Matrix C:

8 7 

7 8

## Time Complexity Analysis

Let $T(n)$ be the time required to multiply two $n \times n$ special-pattern matrices. 

By applying our algebraic trick, we reduced the standard 4 sub-matrix multiplications to exactly **2 recursive multiplications** ($M_1$ and $M_2$). Adding and subtracting the sub-matrices takes time proportional to the number of elements in those blocks, which is $O(n^2)$. Let the constant work for these matrix additions and assignments be $cn^2$.

**Step 1: Formulate the Recurrence Relation**

$$T(n) = 2T(n/2) + cn^2$$

**Step 2: Expand the Recurrence Relation (Substitution Method)**

First, substitute $T(n/2)$ into the equation:

$$T(n/2) = 2T(n/4) + c(n/2)^2 = 2T(n/4) + \frac{cn^2}{4}$$

Plug this back into the original equation:

$$T(n) = 2\left[2T(n/4) + \frac{cn^2}{4}\right] + cn^2 = 4T(n/4) + \frac{cn^2}{2} + cn^2$$

Now, substitute $T(n/4)$:

$$T(n) = 4\left[2T(n/8) + c(n/4)^2\right] + \frac{cn^2}{2} + cn^2 = 8T(n/8) + \frac{cn^2}{4} + \frac{cn^2}{2} + cn^2$$

**Step 3: Generalize for k Steps**

For $k$ iterations, the formula becomes:

$$T(n) = 2^k T(n/2^k) + cn^2 \sum_{i=0}^{k-1} \left(\frac{1}{2}\right)^i$$

**Step 4: Simplify and Solve**

The recursion hits the base case when $n/2^k = 1$, meaning $k = \log_2 n$.
The sum $\sum_{i=0}^{k-1} (1/2)^i$ is a geometric series that converges strictly to less than 2 as $k$ approaches infinity. 

Therefore, the equation simplifies to:
$$T(n) \approx n T(1) + 2cn^2$$

**Step 5: Final Result**

Since the $n^2$ term grows significantly faster than the linear $n$ term, it strictly bounds the worst-case running time.

$$T(n) = O(n^2)$$

## Conclusion

Standard matrix multiplication requires $O(n^3)$ time, and Strassen's algorithm optimizes this to $O(n^{2.81})$. However, by exploiting the specific symmetrical layout of these block matrices, we can isolate the independent variables into just two intermediate matrices ($M_1$ and $M_2$). This drops the required recursive multiplications from 4 down to 2. Consequently, the algorithmic bottleneck shifts entirely to the matrix addition phase, yielding a vastly superior overall time complexity of $O(n^2)$. Furthermore, adding the bitwise check `(n & (n - 1)) != 0` ensures robust memory safety by preventing infinite recursion on invalid inputs, resulting in a highly optimized and structurally sound Divide and Conquer solution.

## Algorithm: Special Matrix Multiplication

```text
MAIN()
1. Read n
2. If n < 1 OR (n AND (n - 1)) != 0
3.     Print "Matrix size must be a power of 2."
4.     Exit
5. Read elements of matrix A and matrix B
6. Call SPECIAL_MULTIPLY(n, A, B, C)
7. Print matrix C

SPECIAL_MULTIPLY(n, A, B, C)
1. If n == 1
2.     C[0][0] = A[0][0] * B[0][0]
3.     Return

4. half = n / 2

5. For i = 0 to half - 1
6.     For j = 0 to half - 1
7.         X_plus_Y[i][j] = A[i][j] + A[i][j + half]
8.         U_plus_V[i][j] = B[i][j] + B[i][j + half]
9.         X_minus_Y[i][j] = A[i][j] - A[i][j + half]
10.        U_minus_V[i][j] = B[i][j] - B[i][j + half]

11. SPECIAL_MULTIPLY(half, X_plus_Y, U_plus_V, M1)
12. SPECIAL_MULTIPLY(half, X_minus_Y, U_minus_V, M2)

13. For i = 0 to half - 1
14.     For j = 0 to half - 1
15.         P = (M1[i][j] + M2[i][j]) / 2
16.         Q = (M1[i][j] - M2[i][j]) / 2
17.         
18.         C[i][j] = P
19.         C[i][j + half] = Q
20.         C[i + half][j] = Q
21.         C[i + half][j + half] = P
