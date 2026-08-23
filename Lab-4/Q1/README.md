## Question 1: Application of sorting-I

### Problem Statement
The objective is to sort $n$ pairs of items, where each pair consists of a number and a color (red, blue, or yellow). The items must be sorted strictly by color in the order of all reds, then all blues, and finally all yellows. The sorting algorithm must maintain stability, ensuring that identical colors remain sorted by their original input numbers, and must execute with an $O(n)$ time complexity.

### Algorithm
To achieve stable $O(n)$ sorting, the algorithm utilizes a multi-pass filtering approach rather than a traditional comparison-based sort:
1. Dynamically allocate an auxiliary `output` array of size $n$ to temporarily store the sorted elements.
2. Perform an initial linear pass to count the frequencies of each color (Red, Blue, Yellow). 
3. Perform three separate, sequential linear passes over the original array to populate the auxiliary array. 
4. In the first pass, append any item with the color 'R' to the auxiliary array.
5. In the second pass, append any item with the color 'B' to the auxiliary array.
6. In the third pass, append any item with the color 'Y' to the auxiliary array.
7. Perform a final linear pass to copy the contents of the auxiliary `output` array back into the original `items` array.
8. Free the dynamically allocated memory.

Because the elements are appended in the exact order they are encountered during the left-to-right passes, their original relative order is preserved, ensuring stability.

### Output

Enter number of items: 6

Enter 6 pairs (number colour):

10 B

20 Y

30 R

40 B

50 R

60 Y

Input:

(10, B) (20, Y) (30, R) (40, B) (50, R) (60, Y) 

Output (R < B < Y):

(30, R) (50, R) (10, B) (40, B) (20, Y) (60, Y)

### Time Complexity Analysis

To determine the total time complexity, we analyze the cost of each step in the algorithm as a function of the input size $n$:

1.  **Initialization:** Allocating the `OUTPUT` array and setting the pointer `p = 0` takes constant time. 
    *   Cost: $O(1)$
2.  **First Pass (Red):** The first `for` loop iterates exactly $n$ times. The operations inside the loop (condition check, array assignment, and incrementing `p`) all take constant time $c_1$.
    *   Cost: $c_1 \cdot n$
3.  **Second Pass (Blue):** The second `for` loop also iterates exactly $n$ times, with constant time operations $c_2$ inside.
    *   Cost: $c_2 \cdot n$
4.  **Third Pass (Yellow):** The third `for` loop iterates exactly $n$ times, with constant time operations $c_3$ inside.
    *   Cost: $c_3 \cdot n$
5.  **Fourth Pass (Copying):** The final `for` loop iterates $n$ times to copy the sorted elements back into the original array $A$, taking constant time $c_4$ per iteration.
    *   Cost: $c_4 \cdot n$

**Total Time Equation, $T(n)$:**
$$T(n) = O(1) + (c_1 \cdot n) + (c_2 \cdot n) + (c_3 \cdot n) + (c_4 \cdot n)$$

Factoring out $n$, we get:
$$T(n) = (c_1 + c_2 + c_3 + c_4)n + O(1)$$

Since $(c_1 + c_2 + c_3 + c_4)$ results in a single constant value (let's call it $k$), the equation simplifies to:
$$T(n) = k \cdot n + O(1)$$

When calculating Big-O notation, we drop all constants and lower-order terms. Therefore, the worst-case, best-case, and average-case time complexity is strictly linear, satisfying the assignment's constraints.

**Final Time Complexity: $$O(n)$$**

### Conclusion

The implemented algorithm successfully solves the Application of Sorting-I problem by categorizing the items into Red, Blue, and Yellow strictly in $O(n)$ time. By utilizing a multi-pass linear scan approach and an auxiliary array, the solution avoids the $O(n \log n)$ overhead typical of comparison-based sorting algorithms like Merge Sort or Quick Sort. Furthermore, because elements of the same color are appended in the exact order they are encountered, the algorithm maintains strict stability, ensuring that identical colors remain sorted by their original numerical values. The C program successfully validates this logic against sample inputs.

### Pseudocode

```text
ALGORITHM SORT-BY-COLOUR(Items, n)
    Create output array
    Set p = 0

    FOR i = 0 TO n - 1
        IF Items[i].colour = 'R'
            output[p] = Items[i]
            Increment p
        END IF
    END FOR

    FOR i = 0 TO n - 1
        IF Items[i].colour = 'B'
            output[p] = Items[i]
            Increment p
        END IF
    END FOR

    FOR i = 0 TO n - 1
        IF Items[i].colour = 'Y'
            output[p] = Items[i]
            Increment p
        END IF
    END FOR

    FOR i = 0 TO n - 1
        Items[i] = output[i]
    END FOR
END SORT-BY-COLOUR
