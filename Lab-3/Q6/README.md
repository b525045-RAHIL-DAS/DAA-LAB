## 6. Problem Statement: Loop Invariants in Sorting

Develop an algorithm to sort an array of $n$ elements by repeatedly finding the minimum element from the unsorted portion and moving it to the beginning (Selection Sort). Write the pseudocode, formally prove its correctness using loop invariants (Initialization, Maintenance, and Termination), and analyze its Best and Worst-case time complexity.

---

## Sample Output

Enter number of elements: 5

Enter 5 elements:

29 10 14 37 13

Sorted array:

10 13 14 29 37

## Proof of Correctness: Loop Invariant Analysis

**Loop Invariant**
At the beginning of every iteration of the outer loop, the part before $i$ is already sorted and contains the smallest elements of the array. 

In other words:

$A[1 \dots i-1]$ contains the $i-1$ smallest elements in sorted order, while $A[i \dots n]$ is the unsorted part.

**1. Initialization**

Before the first iteration:
$i=1$

So, $A[1 \dots i-1] = A[1 \dots 0]$, which is empty. 

An empty array is already sorted. 

Therefore, the loop invariant is true before the loop starts.

**2. Maintenance**

During each iteration, the algorithm searches the unsorted part:
$A[i \dots n]$
and finds its smallest element. 

It then swaps this element with $A[i]$. 

Now $A[i]$ contains the next smallest element. 

Therefore, the sorted part becomes:
$A[1 \dots i]$

So the loop invariant remains true for the next iteration.

**3. Termination**

The loop stops after processing $i=n-1$. 

At this point, the first $n-1$ elements are already sorted and are the $n-1$ smallest elements. 
Only one element is left. 

Therefore, that last element must be the largest element, so the entire array is sorted.

## Time Complexity Analysis

To analyze the time complexity, we count the number of comparisons made in the inner loop.

* When $i = 1$, the inner loop runs $n - 1$ times.
* When $i = 2$, the inner loop runs $n - 2$ times.
* When $i = n - 1$, the inner loop runs $1$ time.

The total number of comparisons is the sum of the first $n-1$ integers:
$$T(n) = (n - 1) + (n - 2) + \dots + 1 = \frac{n(n - 1)}{2}$$

Expanding this gives $\frac{n^2}{2} - \frac{n}{2}$. Dropping the constants and lower-order terms, we get $O(n^2)$.

Because the algorithm does not know if the array is sorted beforehand, it must always scan the entire remaining unsorted subarray to confidently find the minimum element. It cannot terminate early.

| Case | Time Complexity | Justification |
| :--- | :--- | :--- |
| **Best Case** | $\Theta(n^2)$ | Array is already sorted. The inner loop still fully executes to verify the minimum. |
| **Worst Case** | $\Theta(n^2)$ | Array is sorted in reverse. The same number of exact comparisons is made. |
| **Average Case** | $\Theta(n^2)$ | Elements are in random order. The comparison count remains structurally identical. |

---

## Conclusion

Selection sort is a highly intuitive, in-place comparison sort. By analyzing its loop invariants, we can mathematically guarantee that it correctly sorts any given array by systematically expanding a sorted prefix. However, its time complexity is strictly $\Theta(n^2)$ across all cases—best, average, and worst. While the optimization minimizes the number of memory writes, its quadratic comparison time makes it highly inefficient for large datasets compared to more advanced algorithms like Merge Sort or Quick Sort.

### Note: Why Does the Outer Loop Run Only (n - 1) Times?

The outer loop only needs to execute **n - 1** times due to the process of elimination. 

Think about how the algorithm builds the sorted array element by element:
* By the end of the **1st** iteration, the 1st smallest element is locked into the 1st position.
* By the end of the **2nd** iteration, the 2nd smallest element is locked into the 2nd position.
* Then the **(n - 1)**-th iteration: the smallest **n - 1** elements are now perfectly sorted in the first **n - 1** positions.

Since the array only has **n** elements in total, if you have already put the smallest **n - 1** elements into their correct spots, there is only **one element left**, and only **one spot left** (the very end of the array). By default, that single remaining element must be the largest element in the array, and it is already sitting exactly where it belongs. Running an **n**-th iteration would be completely redundant.

## Pseudocode

```text
SELECTION_SORT(A, n)

1. For i = 1 to n - 1
2.     min = i
3.     For j = i + 1 to n
4.         If A[j] < A[min]
5.             min = j
6.     If min != i
7.         temp = A[i]
8.         A[i] = A[min]
9.         A[min] = temp
