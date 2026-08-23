## Question 3: Application of sorting-III

### Problem Statement
Given a set $S$ of $n$ integers and a target integer $T$, the objective is to determine whether there exists a subset of $k$ integers within $S$ that add up to $T$. The algorithm must be implemented in C and strictly execute within an $O(n^{k-1} \cdot \log n)$ worst-case time complexity.

### Algorithm
To meet the $O(n^{k-1} \cdot \log n)$ time complexity requirement, the provided C program utilizes a combination of sorting, recursion, and binary search:
1.  **Sort:** The array $S$ is first sorted in ascending order using the Merge Sort algorithm. 
2.  **Recursive Selection:** A recursive function (`findSum`) systematically selects combinations of $k-1$ elements from the sorted array. It maintains a running sum of the selected elements.
3.  **Find Complement:** Once a combination of exactly $k-1$ elements is formed, the algorithm calculates the remaining value required to reach the target $T$: `req = target - sum`.
4.  **Binary Search:** It then performs a Binary Search for this `req` value within the remaining, unselected portion of the sorted array.
5.  **Output Validation:** If the Binary Search finds the required element, the successful group is printed to the console. The program prints "No such group exists" if no valid $k$ elements are found.

### Output

Enter number of elements: 6

Enter the elements:

10 5 20 15 2 8

Enter k: 3

Enter T: 25

Groups of 3 elements whose sum is 25:

 2 + 8 + 15 = 25

 5 + 10 + 10 = 25

### Time Complexity Analysis

To find the total time complexity, we break down the main steps:

1.  **Sorting:** The Merge Sort function sorts the initial array, which takes $O(n \log n)$ time.
2.  **Finding Combinations:** The recursive function picks $k-1$ elements from the $n$ available elements, which runs approximately $O(n^{k-1})$ times in the worst-case scenario.
3.  **Binary Search:** For every combination found, the program uses Binary Search to find the final missing number. A single Binary Search takes $O(\log n)$ time.
    *   Combined Cost: $O(n^{k-1}) \cdot O(\log n) = O(n^{k-1} \log n)$

**Total Time Equation:**
$$T(n) = O(n \log n) + O(n^{k-1} \log n)$$

Because $k \ge 2$, the $O(n^{k-1} \log n)$ portion is much larger as $n$ grows. We drop the smaller $O(n \log n)$ sorting time, which leaves us perfectly at the required time complexity.

**Final Time Complexity: $$O(n^{k-1} \log n)$$**

### Conclusion

Instead of using $k$ slow, nested loops that would take $O(n^k)$ time to check every single combination, this algorithm uses a smarter approach. It uses recursion to fix the first $k-1$ numbers and then uses a fast Binary Search to find the last required number to reach the target sum. This effectively turns the final $O(n)$ search step into a quick $O(\log n)$ step, hitting the exact $O(n^{k-1} \cdot \log n)$ time limit required for the assignment.

### Pseudocode

```text
ALGORITHM FIND-K-SUM(S, n, k, T)
    Sort S using MERGESORT
    Create array selected
    Set found = false

    FIND-SUM(S, n, k, T, 0, 0, 0, selected, found)

    IF found = false
        Print "No such group exists"
    END IF
END ALGORITHM


ALGORITHM FIND-SUM(S, n, k, T, start, count, sum, selected, found)
    IF count = k - 1
        required = T - sum

        IF BINARYSEARCH(S, start, n - 1, required) = 1
            Print the selected elements and required
            Set found = true
        END IF

        RETURN
    END IF

    FOR i = start TO n - 1
        selected[count] = S[i]
        
        FIND-SUM(S, n, k, T, i + 1, count + 1, sum + S[i], selected, found)
    END FOR
END ALGORITHM


ALGORITHM BINARYSEARCH(S, low, high, key)
    WHILE low <= high
        mid = low + (high - low) / 2

        IF S[mid] = key
            RETURN 1
        ELSE IF S[mid] < key
            low = mid + 1
        ELSE
            high = mid - 1
        END IF
    END WHILE

    RETURN 0
END ALGORITHM


ALGORITHM MERGESORT(S, low, high)
    IF low < high
        mid = (low + high) / 2

        MERGESORT(S, low, mid)
        MERGESORT(S, mid + 1, high)
        MERGE(S, low, mid, high)
    END IF
END ALGORITHM
