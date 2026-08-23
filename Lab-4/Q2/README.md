## Question 2: Application of sorting-II

### Problem Statement
The objective is to determine whether there exists a pair of elements, one from set $S_1$ and one from set $S_2$ (each of size $n$), that add up to a given target number $x$. The algorithm must be validated using a C program and run in $O(n \cdot \log n)$ time complexity.

### Algorithm
To achieve the $O(n \cdot \log n)$ time complexity constraint, the provided C program utilizes Merge Sort and Binary Search to efficiently find the pairs:
1. Dynamically allocate memory for arrays $S_1$ and $S_2$ of size $n$.
2. Sort the second set, $S_2$, in ascending order using the recursive Merge Sort algorithm.
3. Iterate through each element in the first set, $S_1$.
4. For each element $S_1[i]$, calculate the required complement to reach the target $x$: `required = x - S1[i]`.
5. Use an iterative Binary Search algorithm to efficiently search for this `required` value within the sorted set $S_2$.
6. If the Binary Search returns `1` (true), a valid pair is found and printed to the console. 
7. If the loop exhausts all elements in $S_1$ without finding any matches, the program outputs that no such pair exists.

### Output

Enter size of each set: 5

Enter elements of S1:

8 2 5 3 10

Enter elements of S2:

9 4 1 7 12

Enter x: 15

Pairs whose sum is 15:

8 + 7 = 15

3 + 12 = 15

### Time Complexity Analysis

To determine the total time complexity, we analyze the cost of each distinct phase in the algorithm as a function of the input size $n$:

1.  **Sorting Phase (Merge Sort):** 
    The `mergeSort` function recursively divides the array $S_2$ into two halves and then merges them in linear time. The recurrence relation for this divide-and-conquer approach is:
    $$T_{sort}(n) = 2 \cdot T_{sort}\left(\frac{n}{2}\right) + O(n)$$
    By analyzing the recursion tree, we can see that the tree has a depth of $\log n$ levels. At each level, the cost of merging the subarrays is bounded by $O(n)$. Multiplying the depth by the work done at each level gives the total time for this phase.
    *   Cost: $O(n \log n)$

2.  **Search Phase (Binary Search Loop):**
    The `binarySearch` function halves the search space at each step, resulting in a time complexity of $O(\log n)$.
    In the main function, a `for` loop iterates over the elements of $S_1$ exactly $n$ times. Inside this loop, a constant time subtraction `required = x - S1[i]` is performed, followed by a call to the `binarySearch` function. 
    *   Cost: $n \cdot O(\log n) = O(n \log n)$

**Total Time Equation, $T(n)$:**
The total time is the sum of the time taken to sort the array and the time taken to search for the complement pairs:
$$T(n) = T_{sort}(n) + T_{search\_phase}(n)$$
$$T(n) = O(n \log n) + O(n \log n)$$
$$T(n) = 2 \cdot O(n \log n)$$

In Big-O notation, we drop constant multipliers (like the factor of 2) because we are only concerned with the upper bound growth rate of the function as $n$ becomes arbitrarily large. Therefore, the overall worst-case time complexity perfectly meets the assignment's constraint.

**Final Time Complexity: $$O(n \log n)$$**

### Conclusion

By sorting the second array ($S_2$) first, we avoid having to check every possible pair one by one. For each number in the first array ($S_1$), we calculate exactly what number is needed to reach the target sum, and then use Binary Search to quickly look for it in the sorted $S_2$. 

This combination of Merge Sort and Binary Search speeds up the program from a slow $O(n^2)$ approach down to the required $O(n \log n)$ time complexity.

### Pseudocode

```text
ALGORITHM FIND-PAIR(S1, S2, n, x)
    MERGESORT(S2, 0, n - 1)
    
    FOR i = 0 TO n - 1
        required = x - S1[i]
        
        IF BINARYSEARCH(S2, n, required) = 1
            PRINT S1[i], required
            RETURN
        END IF
    END FOR
    
    PRINT "No such pair exists"
END FIND-PAIR


ALGORITHM MERGESORT(A, low, high)
    IF low < high
        mid = (low + high) / 2
        
        MERGESORT(A, low, mid)
        MERGESORT(A, mid + 1, high)
        
        MERGE(A, low, mid, high)
    END IF
END MERGESORT


ALGORITHM BINARYSEARCH(A, n, key)
    low = 0
    high = n - 1
    
    WHILE low <= high
        mid = (low + high) / 2
        
        IF A[mid] = key
            RETURN 1
        ELSE IF A[mid] < key
            low = mid + 1
        ELSE
            high = mid - 1
        END IF
    END WHILE
    
    RETURN 0
END BINARYSEARCH
