## 2. Problem Statement:

Among $n$ identical coins, one coin might be defective (lighter than the rest due to excessive shaping), or all coins might be perfectly identical. Using a balance weighing scale, the goal is to find the defective coin (if it exists) using a Divide and Conquer approach in $O(\log_2 n)$ time.

---

## Algorithm: Defective Coin Search (Divide & Conquer)

FIND_DEFECTIVE(coins, low, high)

1. Calculate n = high - low + 1

2. If n == 1
       Return low 

3. If n == 2

       If coins[low] < coins[high] Return low

       If coins[high] < coins[low] Return high

       Return -1 (No defective coin)

4. mid = low + (n / 2) - 1

5. If n % 2 == 0 (Even number of coins):

       weight1 = sum(coins from low to mid)

       weight2 = sum(coins from mid + 1 to high)
       
       If weight1 < weight2
           Return FIND_DEFECTIVE(coins, low, mid)
       Else If weight2 < weight1
           Return FIND_DEFECTIVE(coins, mid + 1, high)
       Else
           Return -1 (Both piles equal; no defective coin)

6. If n % 2 != 0 (Odd number of coins):

       weight1 = sum(coins from low to mid)

       weight2 = sum(coins from mid + 1 to high - 1)
       
       If weight1 < weight2
           Return FIND_DEFECTIVE(coins, low, mid)
       Else If weight2 < weight1
           Return FIND_DEFECTIVE(coins, mid + 1, high - 1)
       Else
           If coins[high] < coins[low]
               Return high
           Else
               Return -1 (All coins are perfect)

## Sample Output

Enter the number of coins: 5

Enter the weights of the 5 coins:

10 10 7 10 10

Results:

The defective (lighter) coin is at position: 3

Weight of the defective coin: 7

## Time Complexity Analysis

Let $T(n)$ be the number of balance-scale weighings required to search for the defective coin among $n$ coins. 
At each step, the remaining candidate coins are divided into two nearly equal groups. One balance-scale weighing determines which group can contain the defective coin. Therefore, only one recursive subproblem of approximately half the size is processed.

**Step 1: Formulate the Recurrence Relation**
$$T(n) = T(n/2) + c$$

**Step 2: Expand the Recurrence Relation (Substitution Method)**
We expand the equation to find the pattern.
First, substitute $T(n/2)$ into the equation:
$$T(n/2) = T(n/4) + c$$

Plug this back into the original equation:
$$T(n) = [T(n/4) + c] + c$$
$$T(n) = T(n/4) + 2c$$

Now, substitute $T(n/4)$ which is $T(n/8) + c$:
$$T(n) = [T(n/8) + c] + 2c$$
$$T(n) = T(n/8) + 3c$$

**Step 3: Generalize for $k$ Steps**
If we continue this expansion for $k$ iterations, we get:
$$T(n) = T(n/2^k) + kc$$

**Step 4: Apply the Base Case**
The recursion hits the base case when there is only 1 coin left to check.
$$\frac{n}{2^k} = 1$$
$$n = 2^k$$
$$k = \log_2 n$$

**Step 5: Simplify and Solve**
Substitute $k = \log_2 n$ back into the generalized equation:
$$T(n) = T(1) + c \log_2 n$$

**Step 6: Final Result**
Since $T(1)$ (the time to check a single coin) and $c$ (the constant time to weigh) are constants, they are dropped in asymptotic notation. 

$$\boxed{T(n) = O(\log_2 n)}$$

---

## Conclusion

By discarding half of the remaining coins at every step, the divide and conquer strategy allows us to find the defective coin (or confirm its absence) in logarithmic time. A standard linear search would require checking each coin one by one, resulting in $O(n)$ complexity. The balance-scale approach vastly improves efficiency, ensuring the defective coin is found in strictly $O(\log_2 n)$ comparisons.

**Note on Time Complexity:** 
 The theoretical time complexity of this divide and conquer algorithm is $O(\log_2 n)$, assuming a physical balance scale can weigh two piles in constant $O(1)$ time. However, to simulate this physical scale in software, the `getWeight` function must iteratively sum the array elements. This introduces an $O(k)$ summation step at each recursive call, meaning the actual execution time of the C program is $O(n)$.
