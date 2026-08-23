## Question 5: Application of sorting-V

### Problem Statement
Given a list $I$ of $n$ intervals, specified as $(x_i, y_i)$ pairs, the objective is to return a list where the overlapping intervals are merged. For example, given the input $I = \{(1, 3), (2, 6), (8, 10), (7, 18)\}$, the algorithm must output $\{(1, 6), (7, 18)\}$. The algorithm must be validated in C and strictly execute with a worst-case time complexity of $O(n \cdot \log n)$.

### Algorithm
To achieve the $O(n \cdot \log n)$ time complexity requirement, the provided C program utilizes a combination of sorting and a single-pass linear merge:
1.  **Data Structure:** The intervals are parsed into an array of `Interval` structures, each holding a `start` and `end` integer.
2.  **Sort:** The array of intervals is sorted based on their `start` values using Merge Sort. If two intervals share the exact same `start` value, they are sorted by their `end` values.
3.  **Initialize Merge:** A `merged` array is created, and the first interval from the sorted list is added as the starting point.
4.  **Linear Scan:** The algorithm iterates through the remaining sorted intervals one by one.
5.  **Evaluate Overlap:** For each interval, it checks if it overlaps with the most recently added interval in the `merged` array (i.e., if `intervals[i].start <= merged[count - 1].end`).
6.  **Merge or Append:** 
    *   If they overlap, the `end` time of the merged interval is updated to the maximum `end` time between the two overlapping intervals.
    *   If they do not overlap, the current interval is appended as a brand new, distinct interval in the `merged` array.

### Output

Enter number of intervals: 4

Enter the intervals (xi yi):

1 3

2 6

8 10

7 18

Merged intervals:

{(1, 6), (7, 18)}

## Time Complexity Analysis

The total time complexity is calculated by summing the time taken by each sequential phase of the program:

*   **Input Processing:** Reading $n$ intervals from the user requires a single loop over the input, taking $O(n)$ time.
*   **Sorting Phase (Merge Sort):** The recursive `mergeSort` function divides the array into halves, and the `merge` function processes them in linear time. This gives the recurrence relation $T(n) = 2T(n/2) + O(n)$, which evaluates to $O(n \log n)$.
*   **Merging Phase:** Iterating through the sorted array to combine overlapping intervals requires exactly one pass, taking $O(n)$ time.
*   **Output Generation:** Printing the final merged array of size $k$ (where $k \le n$) takes $O(n)$ time.

**Total Calculation:**
$$Total Time = O(n) + O(n \log n) + O(n) + O(n)$$

Because $O(n \log n)$ grows significantly faster than $O(n)$ as $n$ increases, the lower-order linear terms are dropped. Therefore, the final time complexity evaluates to **$O(n \log n)$**.

## Conclusion

The provided C program efficiently merges overlapping intervals by first sorting them using Merge Sort and then combining them in a single linear pass. Because the sorting step dictates the overall execution time, the algorithm operates with a worst-case time complexity of $O(n \log n)$ and requires $O(n)$ auxiliary space to manage the sorted and merged arrays.

## Pseudocode

```text
START

Define Interval with start and end

MERGE(a, low, mid, high)
    Compare intervals from both halves by start, then end
    Store smaller interval in temporary array
    Copy remaining intervals
    Copy temporary array back to a
END MERGE

MERGESORT(a, low, high)
    IF low < high
        mid ← (low + high) / 2
        MERGESORT(a, low, mid)
        MERGESORT(a, mid + 1, high)
        MERGE(a, low, mid, high)
    END IF
END MERGESORT

INPUT n
INPUT n intervals

MERGESORT(intervals, 0, n - 1)

merged[0] ← intervals[0]
count ← 1

FOR i ← 1 TO n - 1
    IF intervals[i].start ≤ merged[count - 1].end
        IF intervals[i].end > merged[count - 1].end
            merged[count - 1].end ← intervals[i].end
        END IF
    ELSE
        merged[count] ← intervals[i]
        count ← count + 1
    END IF
END FOR

PRINT merged intervals

END
