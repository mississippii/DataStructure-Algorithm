#include <bits/stdc++.h>
using namespace std;

/*
 * 0/1 Knapsack Problem
 *
 * Problem: Given weights and values of n items, put these items in a knapsack
 * of capacity W to get the maximum total value. Each item can be taken or left (0/1).
 *
 * Recurrence: dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i])
 *
 * Time: O(n * W)
 * Space: O(n * W) or O(W) with optimization
 */

// Method 1: Recursive with Memoization (Top-Down)
int memo[1001][1001];

int knapsackMemo(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0) return 0;

    if (memo[n][W] != -1) return memo[n][W];

    if (wt[n-1] > W) {
        // Can't include this item
        return memo[n][W] = knapsackMemo(wt, val, n-1, W);
    }

    // Max of including or excluding current item
    int include = val[n-1] + knapsackMemo(wt, val, n-1, W - wt[n-1]);
    int exclude = knapsackMemo(wt, val, n-1, W);

    return memo[n][W] = max(include, exclude);
}

// Method 2: Tabulation (Bottom-Up) - O(n*W) space
int knapsackTabulation(int wt[], int val[], int n, int W) {
    int dp[n+1][W+1];

    // Base case: 0 items or 0 capacity = 0 value
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int w = 0; w <= W; w++) dp[0][w] = 0;

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(
                    dp[i-1][w],                           // Exclude
                    val[i-1] + dp[i-1][w - wt[i-1]]       // Include
                );
            } else {
                dp[i][w] = dp[i-1][w];  // Can't include
            }
        }
    }

    return dp[n][W];
}

// Method 3: Space Optimized - O(W) space
int knapsackOptimized(int wt[], int val[], int n, int W) {
    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        // Traverse right to left to avoid using updated values
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}

// Print which items are selected
void printSelectedItems(int wt[], int val[], int n, int W) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int w = 0; w <= W; w++) dp[0][w] = 0;

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << "Maximum Value: " << dp[n][W] << endl;
    cout << "Selected Items: ";

    // Backtrack to find selected items
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << " ";  // Item i is selected (1-indexed)
            w -= wt[i-1];
        }
    }
    cout << endl;
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;

    cout << "=== 0/1 Knapsack Problem ===" << endl;
    cout << "Items (weight, value): ";
    for (int i = 0; i < n; i++) {
        cout << "(" << wt[i] << "," << val[i] << ") ";
    }
    cout << "\nKnapsack Capacity: " << W << endl;

    // Method 1: Memoization
    memset(memo, -1, sizeof(memo));
    cout << "\nMemoization: " << knapsackMemo(wt, val, n, W) << endl;

    // Method 2: Tabulation
    cout << "Tabulation: " << knapsackTabulation(wt, val, n, W) << endl;

    // Method 3: Optimized
    cout << "Optimized: " << knapsackOptimized(wt, val, n, W) << endl;

    // Print selected items
    cout << "\n";
    printSelectedItems(wt, val, n, W);

    return 0;
}

/*
 * Output:
 * Maximum Value: 220
 * Selected Items: 3 2 (items with values 120 and 100)
 *
 * Variations:
 * 1. Unbounded Knapsack: Each item can be taken multiple times
 *    - Change inner loop to: for (w = wt[i]; w <= W; w++)
 *
 * 2. Subset Sum: Check if subset with given sum exists
 *    - Use boolean dp, no values
 *
 * 3. Equal Partition: Split array into two equal sum subsets
 *    - Use subset sum with target = totalSum / 2
 */
