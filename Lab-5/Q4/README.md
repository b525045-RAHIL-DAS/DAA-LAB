## Heap Sort

### Problem Statement
Implement Heap Sort to sort a list of $N$ numbers and analyze the time complexity of the algorithm. 

The given program implements Heap Sort using a max heap. It first builds a max heap from the array and then repeatedly moves the largest element to the end of the array and restores the heap property.

### Algorithm
1. Start.
2. Read the number of elements $N$.
3. Generate $N$ random elements and store them in the array.
4. Build a max heap from the array.
5. For each element from the last position towards the beginning:
    * Swap the root of the heap with the last element.
    * Reduce the heap size by one.
    * Apply `heapify()` to restore the max-heap property.
6. Store the sorted elements in `output.txt`.
7. Display the completion messages.
8. Stop.

*(Note: The `heapSort()` function first builds the heap and then repeatedly extracts the maximum element.)*

### Output

Enter number of elements: 9

9 random elements generated and stored in input.txt.

Elements sorted successfully using Heap Sort.

Sorted elements stored in output.txt.

### Detailed Time Complexity Analysis

**Complexity of Heapify**
The `heapify()` function compares a node with its children and may recursively move down the heap. The height of a binary heap containing $N$ elements is $O(\log N)$. In the worst case, the element may move from the root to the bottom of the heap.
Therefore:
**Heapify = $$O(\log N)$$**
*(The recursive call in the given implementation is responsible for moving the element down the heap.)*

**Building the Max Heap**
The program builds the max heap using a loop from $N/2 - 1$ down to $0$. Although `heapify()` can take $O(\log N)$ for an individual node, building a heap by applying `heapify()` from the last non-leaf node to the root takes $O(N)$. This is because most nodes are located near the bottom of the heap and require very little heapification.
Therefore:
**Building Max Heap = $$O(N)$$**

**Best Case**
After building the heap, Heap Sort repeatedly removes the maximum element and restores the heap. Each extraction requires a `heapify()` operation. The heap contains progressively smaller numbers of elements, but each `heapify()` operation takes logarithmic time in the worst case. 
The sorting phase takes $O(N \log N)$.
The heap construction takes $O(N)$.
$$T(N) = O(N) + O(N \log N)$$
Since $O(N \log N)$ dominates $O(N)$:
$$T(N) = O(N \log N)$$
**Best Case = $$O(N \log N)$$**

**Average Case**
Heap Sort performs the same basic heap construction and repeated extraction operations regardless of the initial arrangement of the elements. The heap construction takes $O(N)$. There are approximately $N$ extraction operations, and each requires heapification taking $O(\log N)$.
$$T(N) = O(N) + N \cdot O(\log N)$$
$$T(N) = O(N) + O(N \log N)$$
Therefore:
**Average Case = $$O(N \log N)$$**

**Worst Case**
In the worst case, each heapify operation can travel from the root to the bottom of the heap. Therefore, each heapify operation takes $O(\log N)$. There are approximately $N$ extraction operations.
$$T(N) = N \cdot O(\log N)$$
$$T(N) = O(N \log N)$$
The heap construction requires $O(N)$, so the total is:
$$T(N) = O(N) + O(N \log N)$$
Therefore:
**Worst Case = $$O(N \log N)$$**

### Overall Time Complexity

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $O(N \log N)$ |
| **Average Case** | $O(N \log N)$ |
| **Worst Case** | $O(N \log N)$ |

*An important advantage of Heap Sort is that its asymptotic time complexity remains $O(N \log N)$ in all cases.*

### Conclusion

The given program successfully sorts $N$ randomly generated elements using the Heap Sort algorithm. It first constructs a max heap and then repeatedly extracts the maximum element by swapping it with the last element and restoring the heap property. The best-case, average-case, and worst-case time complexity of Heap Sort is $O(N \log N)$. Therefore, Heap Sort provides a consistent and efficient sorting algorithm whose running time does not degrade to $O(N^2)$ based on the initial arrangement of the elements.

### Pseudocode

```text
ALGORITHM HEAPIFY(arr, n, i)
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    IF left < n AND arr[left] > arr[largest] THEN
        largest = left
    END IF

    IF right < n AND arr[right] > arr[largest] THEN
        largest = right
    END IF

    IF largest != i THEN
        SWAP arr[i] and arr[largest]
        HEAPIFY(arr, n, largest)
    END IF
END ALGORITHM


ALGORITHM HEAPSORT(arr, n)
    FOR i = n / 2 - 1 DOWN TO 0
        HEAPIFY(arr, n, i)
    END FOR

    FOR i = n - 1 DOWN TO 1
        SWAP arr[0] and arr[i]
        HEAPIFY(arr, i, 0)
    END FOR
END ALGORITHM
