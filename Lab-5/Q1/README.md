## Median Without Sorting

### Problem Statement
Find the median of a list of $N$ numbers without sorting the list. Do the complexity analysis of your algorithm. 

The given program uses the Quickselect algorithm to find the median without completely sorting the array. Quickselect uses the partitioning technique of Quick Sort and searches only the portion of the array that contains the required element.

### Algorithm
1. Start.
2. Read the number of elements $N$.
3. Read the $N$ elements into the array.
4. For each partition operation, select the last element of the current subarray as the pivot.
5. Partition the array around the pivot.
6. Use Quickselect to find the required middle element(s).
7. If necessary, calculate the median using the middle element(s).
8. Display the median.
9. Stop.

*(Note: The `partition()` function rearranges the elements around the pivot, while `quickselect()` recursively searches the required portion of the array.)*

### Output

Enter the number of elements: 7

Enter the elements: 12 5 8 20 3 15 10

Median: 10.0

### Detailed Time Complexity Analysis

The main operation of the algorithm is partitioning.

**Partition Complexity**
The partition function scans the elements of the current subarray once. For $N$ elements:
$$T(N) = cN$$
Therefore:
$$T(N) = O(N)$$
The given implementation performs this scan using the loop from `low` to `high - 1`.

**Best Case**
In the best case, the selected pivot is close to the required position, so the size of the problem is reduced significantly after each partition. The work performed at each level is proportional to the current number of elements.
Thus:
$$T(N) = O(N)$$
Therefore:
**Best Case = $$O(N)$$**

**Average Case**
On average, Quickselect reduces the problem size substantially after partitioning and recursively works on only one part of the array. A simplified recurrence is:
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
In the worst case, the pivot produces a highly unbalanced partition every time. The given implementation always chooses the last element as the pivot (`int pivot = arr[high];`). 

In the worst case, the problem size decreases by only one element at every recursive call:
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

The median of $N$ numbers was successfully found without sorting the complete list using the Quickselect algorithm. Quickselect uses partitioning and recursively searches only the relevant portion of the array. The algorithm has a linear $O(N)$ best-case and average-case time complexity, while its worst-case time complexity is $O(N^2)$ due to highly unbalanced partitions. Thus, Quickselect is an efficient approach for finding the median without completely sorting the input list.

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


ALGORITHM QUICKSELECT(arr, low, high, k)
    IF k > 0 AND k <= high - low + 1 THEN
        pos = PARTITION(arr, low, high)

        IF pos - low = k - 1 THEN
            RETURN arr[pos]
        ELSE IF pos - low > k - 1 THEN
            RETURN QUICKSELECT(arr, low, pos - 1, k)
        ELSE
            RETURN QUICKSELECT(arr, pos + 1, high, k - pos + low - 1)
        END IF
    END IF
    
    RETURN -1
END ALGORITHM


ALGORITHM FIND_MEDIAN(arr, N)
    Determine the middle position(s) of the array
    Use QUICKSELECT to find the required middle element(s)

    IF there is one middle element THEN
        median = middle element
    ELSE
        median = average of the two middle elements
    END IF

    RETURN median
END ALGORITHM
