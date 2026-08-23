## Question 4: Application of sorting-IV

### Problem Statement
A camera at the door tracks the entry time $a_i$ and exit time $b_i$ (where $b_i > a_i$) for $n$ distinct people attending a party. Assuming all entry and exit times are distinct, the objective is to determine the exact time when the most people were simultaneously present. The algorithm must be validated in C and run in an $O(n \log n)$ time complexity.

### Algorithm
To meet the $O(n \log n)$ time complexity requirement, the provided C program utilizes a sweep-line algorithm paired with sorting:
1.  **Separate and Sort:** The input times are split into two independent arrays: one for `entries` and one for `exits`. Both arrays are then sorted in ascending order using Merge Sort.
2.  **Two-Pointer Sweep:** The algorithm uses two pointers, `i` and `j`, to traverse the `entries` and `exits` arrays respectively, simulating the chronological flow of time.
3.  **Process Entries:** If the current entry time is less than the current exit time (`entries[i] < exits[j]`), it indicates a person has arrived. The `current_guests` count is incremented, and the pointer `i` moves forward.
4.  **Track the Peak:** If the newly incremented `current_guests` exceeds the known `max_guests`, both the `max_guests` and the `time_of_max` are updated.
5.  **Process Exits:** If the current exit time is earlier (or equal), it indicates a person has left. The `current_guests` count is decremented, and the pointer `j` moves forward.

### Output

Enter number of persons: 4

Enter entry and exit times for each person:

1 4

2 5

7 11

3 8

Time when most people were simultaneously present: 3

Maximum people present: 3

### Time Complexity Analysis

To determine the total time complexity, we analyze the main steps of the algorithm:

1.  **Sorting Phase:** The algorithm uses Merge Sort to independently sort the `entries` array and the `exits` array. Sorting an array of size $n$ takes $O(n \log n)$ time.
    *   Cost: $2 \cdot O(n \log n) = O(n \log n)$
2.  **Sweep-Line Phase:** The `WHILE` loop traverses through the sorted arrays using two pointers, `i` and `j`. In the worst-case scenario, it processes all $n$ entries and $n$ exits exactly once, leading to at most $2n$ operations.
    *   Cost: $O(n)$

**Total Time Equation:**
$$T(n) = O(n \log n) + O(n)$$

As the input size $n$ grows, the $O(n \log n)$ sorting phase strictly dominates the $O(n)$ linear sweep. By dropping the lower-order term, we arrive at the final time complexity, which perfectly meets the required constraints.

**Final Time Complexity: $$O(n \log n)$$**

### Conclusion

Instead of using a naive approach that compares every time interval against all others (which would result in an inefficient $O(n^2)$ time complexity), this sweep-line algorithm treats the entries and exits as independent chronological events. By sorting these events first, the program only needs to perform a single linear scan across the timeline to keep a running tally of the guests. This structural optimization successfully reduces the overall worst-case performance to $O(n \log n)$.

### Pseudocode

```text
ALGORITHM FIND-MAX-PRESENCE(entries, exits, n)
    Sort entries using MERGESORT
    Sort exits using MERGESORT

    Set current_guests = 0
    Set max_guests = 0
    Set time_of_max = 0
    Set i = 0
    Set j = 0

    WHILE i < n AND j < n
        IF entries[i] < exits[j]
            Increment current_guests

            IF current_guests > max_guests
                max_guests = current_guests
                time_of_max = entries[i]
            END IF

            Increment i
        ELSE
            Decrement current_guests
            Increment j
        END IF
    END WHILE

    Print time_of_max
    Print max_guests
END ALGORITHM


ALGORITHM MERGESORT(A, low, high)
    IF low < high
        mid = (low + high) / 2

        MERGESORT(A, low, mid)
        MERGESORT(A, mid + 1, high)
        MERGE(A, low, mid, high)
    END IF
END ALGORITHM
