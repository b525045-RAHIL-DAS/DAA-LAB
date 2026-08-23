## Question 6: Application of sorting-VI

## Problem Statement
You are given a set of $n$ intervals on a line, with the $i^{th}$ interval described by its left and right endpoints $(l_i, r_i)$. The objective is to identify a point $p$ on the line that is present in the largest number of intervals using an algorithm with a worst-case time complexity of $O(n \log n)$. An endpoint counts as being included in its interval.

## Algorithm

To find the point where the maximum number of intervals overlap, the provided C program uses Merge Sort followed by a two-pointer linear scan:

*   **Data Structure:** The intervals are stored using two separate arrays: one for the left endpoints and one for the right endpoints.
*   **Sort:** The left endpoint array and right endpoint array are sorted separately using Merge Sort.
*   **Initialize Pointers:** Two pointers, `i` and `j`, are initialized to the beginning of the sorted left and right endpoint arrays. The current overlap, maximum overlap, and best point are initialized to zero.
*   **Linear Scan:** The algorithm scans both sorted arrays using the two pointers until either array is completely traversed.
*   **Evaluate Overlap:** If the current left endpoint is less than or equal to the current right endpoint, the current overlap is increased by one. Otherwise, the current overlap is decreased by one.
*   **Update Maximum:** Whenever the current overlap becomes greater than the maximum overlap found so far, the maximum overlap and the corresponding point are updated.
*   **Display Result:** Finally, the algorithm displays the point having the largest number of overlapping intervals and the number of intervals overlapping at that point.
*   **Time Complexity:** The sorting takes $O(n \log n)$ time, while the final two-pointer scan takes $O(n)$ time. Therefore, the overall time complexity is $O(n \log n)$.

## Output

Enter number of intervals: 5

Enter the intervals (li ri):

1 5

2 6

4 8

7 9

3 7

Point in the largest number of intervals: 4

Number of overlapping intervals at this point: 4

## Time Complexity Analysis

The total time complexity is calculated by summing the time required for each distinct phase of the program:

*   **Input Processing:** Reading the $n$ intervals into the two separate `lefts` and `rights` arrays requires a single loop with $n$ iterations. This takes **$O(n)$** time.
*   **Sorting Phase:** The program calls the `mergeSort` function twice (once for the `lefts` array and once for the `rights` array). 
    *   The `mergeSort` algorithm divides the array recursively in $O(\log n)$ steps and merges them in $O(n)$ time, yielding $O(n \log n)$ for each array. 
    *   Sorting both arrays takes $O(n \log n) + O(n \log n)$, which simplifies to **$O(n \log n)$**.
*   **Sweep-Line Phase:** The program uses a `while` loop with two pointers (`i` and `j`) to iterate through the sorted arrays and find the maximum overlap. Since both pointers only move forward and at most traverse their respective arrays of size $n$, this sweep operation takes **$O(n)$** time.

**Total Calculation:**
$$Total Time = O(n) + O(n \log n) + O(n)$$

Because the $O(n \log n)$ term grows significantly faster than the linear $O(n)$ terms as the number of intervals ($n$) increases, the lower-order terms are ignored. Therefore, the final time complexity evaluates to **$O(n \log n)$**.

## Conclusion

The provided C program successfully solves the maximum overlap intervals problem by utilizing a combination of Merge Sort and a linear sweep-line technique. By separating and sorting the left and right endpoints independently before scanning them with two pointers, the algorithm strictly adheres to the required worst-case $O(n \log n)$ time complexity. It correctly identifies the optimal point and the maximum number of overlapping intervals while utilizing $O(n)$ auxiliary space, providing a highly efficient and fully compliant solution.

## Pseudocode
```text
ALGORITHM Maximum_Overlap_Intervals

Read n

Create arrays lefts[0...n-1] and rights[0...n-1]

For i ← 0 to n-1
    Read lefts[i], rights[i]
End For

MergeSort(lefts, 0, n-1)
MergeSort(rights, 0, n-1)

i ← 0
j ← 0
current_overlap ← 0
max_overlap ← 0
best_point ← 0

While i < n AND j < n
    If lefts[i] ≤ rights[j]
        current_overlap ← current_overlap + 1

        If current_overlap > max_overlap
            max_overlap ← current_overlap
            best_point ← lefts[i]
        End If

        i ← i + 1
    Else
        current_overlap ← current_overlap - 1
        j ← j + 1
    End If
End While

Display best_point
Display max_overlap


MergeSort(A, low, high)

If low < high
    mid ← low + (high - low) / 2
    MergeSort(A, low, mid)
    MergeSort(A, mid + 1, high)
    Merge(A, low, mid, high)
End If


Merge(A, low, mid, high)

i ← low
j ← mid + 1
k ← 0

Create temporary array temp

While i ≤ mid AND j ≤ high
    If A[i] < A[j]
        temp[k] ← A[i]
        i ← i + 1
    Else
        temp[k] ← A[j]
        j ← j + 1
    End If
    k ← k + 1
End While

While i ≤ mid
    temp[k] ← A[i]
    i ← i + 1
    k ← k + 1
End While

While j ≤ high
    temp[k] ← A[j]
    j ← j + 1
    k ← k + 1
End While

Copy temp into A[low...high]
