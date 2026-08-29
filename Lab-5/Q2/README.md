## K-th Smallest Element Without Sorting

### Problem Statement
Find the $K$-th smallest element in a given list of $N$ numbers without sorting the list. Do the complexity analysis of your algorithm. 

The given program uses the Quickselect algorithm to find the $K$-th smallest element without completely sorting the array. It uses partitioning to determine the position of the pivot and recursively searches only the required portion of the array.

### Algorithm
1. Start.
2. Read the number of elements $N$.
3. Read the $N$ elements into the array.
4. Read the value of $K$.
5. For each partition operation, select the last element of the current subarray as the pivot.
6. Partition the array around the pivot.
7. Determine the position of the pivot after partitioning.
8. If the pivot is the $K$-th smallest element, return the pivot.
9. If the $K$-th smallest element lies on the left side, recursively search the left portion.
10. Otherwise, recursively search the right portion.
11. Display the $K$-th smallest element.
12. Stop.

### Output

Enter the number of elements: 7

Enter the elements: 12 5 8 20 3 15 10

Enter the value of k: 3

The 3'th smallest element is 8

### Detailed Time Complexity Analysis

**Partition Complexity**
The `partition()` function examines every element of the current subarray once. For $N$ elements, the loop runs approximately $N$ times. 
$$T(N) = cN$$
Therefore:
$$T(N) = O(N)$$
The supplied code performs the partition using the loop from `low` to `high - 1`.

**Best Case**
In the best case, the pivot is positioned such that the required $K$-th smallest element is found immediately or the search space is reduced substantially. The partition operation itself requires $O(N)$.
Therefore:
**Best Case = $$O(N)$$**

**Average Case**
In the average case, the pivot divides the array reasonably well. Quickselect recursively searches only one side of the partition rather than both sides. A simplified recurrence is:
$$T(N) = T(aN) + cN$$
where $0 < a < 1$.

Expanding this recurrence:
$$T(N) = cN + caN + ca^2N + \dots$$
$$T(N) = cN(1 + a + a^2 + \dots)$$

Since the geometric series is bounded by a constant:
$$T(N) = O(N)$$
Therefore:
**Average Case = $$O(N)$$**

**Worst Case**
The given implementation always chooses the last element as the pivot (`int pivot = arr[high];`). The worst case occurs when the pivot is consistently the smallest or largest element. The size of the problem then decreases by only one element at each recursive call:
$$N, N-1, N-2, N-3, \dots, 1$$

Therefore, the recurrence relation is:
$$T(N) = T(N-1) + cN$$

Expanding this:
$$T(N) = cN + c(N-1) + c(N-2) + \dots + c$$
$$T(N) = c(1 + 2 + 3 + \dots + N)$$

Using the formula for the sum of the first $N$ integers:
$$1 + 2 + \dots + N = \frac{N(N+1)}{2}$$

We get:
$$T(N) = \frac{cN(N+1)}{2}$$

Ignoring constants and lower-order terms:
$$T(N) = O(N^2)$$
Therefore:
**Worst Case = $$O(N^2)$$**

### Overall Time Complexity

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $O(N)$ |
| **Average Case** | $O(N)$ |
| **Worst Case** | $O(N^2)$ |

### Conclusion

The $K$-th smallest element was successfully found without sorting the complete list using the Quickselect algorithm. The algorithm uses partitioning to place the pivot in its appropriate position and recursively searches only the portion containing the required $K$-th smallest element. The algorithm has a best-case and average-case time complexity of $O(N)$, while the worst-case time complexity is $O(N^2)$ due to highly unbalanced partitions. Therefore, Quickselect is an efficient method for finding a specific order statistic without completely sorting the input list.

### Pseudocode

```text
ALGORITHM PARTITION(arr, low, high)
    pivot = arr[high]
    i = low - 1

    FOR j = low TO high - 1
        IF arr[j] < pivot THEN
            i = i + 1
            SWAP arr[i] and arr[j]
        END IF
    END FOR

    SWAP arr[i + 1] and arr[high]
    
    RETURN i + 1
END ALGORITHM


ALGORITHM KTH_SMALLEST(arr, low, high, k)
    IF k > 0 AND k <= high - low + 1 THEN
        index = PARTITION(arr, low, high)

        IF index - low = k - 1 THEN
            RETURN arr[index]
        ELSE IF index - low > k - 1 THEN
            RETURN KTH_SMALLEST(arr, low, index - 1, k)
        ELSE
            RETURN KTH_SMALLEST(arr, index + 1, high, k - index + low - 1)
        END IF
    END IF
    
    RETURN -1
END ALGORITHM


