## Quick Sort

### Problem Statement
Implement Quick Sort to sort a list of $N$ numbers and analyze the time complexity of the algorithm. 

The given program implements Quick Sort using the last element as the pivot. It partitions the array around the pivot and recursively sorts the left and right subarrays.

### Algorithm
1. Start.
2. Read the number of elements $N$.
3. Generate $N$ random elements and store them in the array.
4. Select the last element of the current subarray as the pivot.
5. Partition the array:
    * Compare each element with the pivot.
    * Move elements smaller than the pivot to the left.
    * Place the pivot in its correct position.
6. Recursively apply Quick Sort to the left subarray.
7. Recursively apply Quick Sort to the right subarray.
8. Store the sorted elements in `output.txt`.
9. Display the completion messages.
10. Stop.

*(Note: The program generates random values using `rand() % 1000`, stores them in `input.txt`, sorts them using Quick Sort, and writes the sorted result to `output.txt`.)*

### Output

Enter the number of elements: 10

10 random elements generated and stored in input.txt.

Elements sorted using Quick Sort.

Sorted elements stored in output.txt.

### Detailed Time Complexity Analysis

**Partition Complexity**
During partitioning, every element in the current subarray is compared with the pivot. For $N$ elements, the loop executes approximately $N$ times.
$$T(N) = cN$$
Therefore:
$$T(N) = O(N)$$
The given implementation performs this partition using the loop from `low` to `high - 1`.

**Best Case**
The best case occurs when the pivot divides the array into two approximately equal parts. The recurrence is:
$$T(N) = 2T(N/2) + cN$$

Expanding this recurrence:
$$T(N) = 2[2T(N/4) + cN/2] + cN$$
$$T(N) = 4T(N/4) + 2cN$$

After repeatedly expanding to $k$ levels:
$$T(N) = 2^kT(N/2^k) + kcN$$

At the base case, $\frac{N}{2^k} = 1$, which means $k = \log_2 N$. Substituting $k$ back into the equation:
$$T(N) = N \cdot c \log_2 N$$

Therefore:
**Best Case = $$O(N \log N)$$**

**Average Case**
In the average case, the pivot generally divides the array into reasonably sized subarrays. The work performed at each level of recursion is approximately $O(N)$. The recursion tree has approximately $O(\log N)$ levels.

$$T(N) = O(N) \times O(\log N)$$

Therefore:
**Average Case = $$O(N \log N)$$**

**Worst Case**
The given program always selects the last element as the pivot (`int pivot = arr[high];`). The worst case occurs when the pivot is consistently the smallest or largest element. In this situation, the partition produces one subarray containing $N-1$ elements and another containing zero elements.

Therefore, the recurrence is:
$$T(N) = T(N-1) + cN$$

Expanding this:
$$T(N) = T(N-2) + c(N-1) + cN$$
$$T(N) = cN + c(N-1) + c(N-2) + \dots + c$$
$$T(N) = c(1 + 2 + 3 + \dots + N)$$

Using the sum of the first $N$ integers formula:
$$1 + 2 + 3 + \dots + N = \frac{N(N+1)}{2}$$

We get:
$$T(N) = \frac{cN(N+1)}{2}$$

Ignoring constants and lower-order terms:
$$T(N) = O(N^2)$$

Therefore:
**Worst Case = $$O(N^2)$$**

### Overall Time Complexity

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $O(N \log N)$ |
| **Average Case** | $O(N \log N)$ |
| **Worst Case** | $O(N^2)$ |

### Conclusion

The given program successfully sorts $N$ randomly generated elements using the Quick Sort algorithm. Quick Sort uses a divide-and-conquer approach by selecting a pivot, partitioning the array around the pivot, and recursively sorting the resulting subarrays. The algorithm has a best-case and average-case time complexity of $O(N \log N)$, while the worst-case time complexity is $O(N^2)$ when the pivot produces highly unbalanced partitions. In this implementation, the last element is always selected as the pivot, so the choice of input can significantly affect the running time.

### Pseudocode

```text
ALGORITHM SWAP(a, b)
    temp = a
    a = b
    b = temp
END ALGORITHM


ALGORITHM QUICKSORT(arr, low, high)
    IF low < high THEN
        pivot = arr[high]
        i = low - 1

        FOR j = low TO high - 1
            IF arr[j] < pivot THEN
                i = i + 1
                SWAP arr[i] and arr[j]
            END IF
        END FOR

        SWAP arr[i + 1] and arr[high]
        p = i + 1

        QUICKSORT(arr, low, p - 1)
        QUICKSORT(arr, p + 1, high)
    END IF
END ALGORITHM
